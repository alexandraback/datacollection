#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
struct level{
	int one,two;
	bool onlyone,alive,choose;
	int leftover;
	level(int l,int r):one(l),two(r),leftover(2){
		onlyone=choose=false;
		alive=true;
	}
	void greedy(int &points,int &steps){
		if(alive && points>=two){
			points+=leftover;
			steps+=1;	
			alive=false;
		}
	}
	bool possible(int &points){
		if(alive && points>=one && !choose) return true;
		return false;
	}
	bool larger(level & another){
		return two>=another.two;
	}
	int runmax(int &points,int &steps){
		if(!alive) return 1;
		points+=1;
		steps+=1;
		leftover=1;
		choose=true;
	}
	void kill(){
		alive=false;
	}
};
vector<level> all;
int run(int &points,int &steps,int n,int k){
	bool bad=false;
	while(points!=n*2){
		int before=points;
		while(true){
			int gb=points;
			for(int i=0;i<all.size();++i){
				all[i].greedy(points,steps);
			}
			if(gb==points) break;
		}
//cout<<points<<"up"<<steps<<endl;
		
		level * max;
		int count=0;
		for(int i=0;i<all.size();++i){
			if(all[i].possible(points)){
				if(count==0) {
					count=1;
					max=&all[i];
				}	
				else if(all[i].larger(*max) ){
					max=&all[i];
				}
			}
		}
		if(count!=0){
			max->runmax(points,steps);

		}
		
		if(before==points) {
			bad==true;
			break;
		}
	}
	if(points==n*2){
		cout<<"Case #"<<k<<": "<<steps<<endl;
	}
	else{
		cout<<"Case #"<<k<<": "<<"Too Bad"<<endl;
	}
}
int main(){

	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		all.clear();
		int points=0,steps=0;
		int n;
		cin>>n;
		for(int j=0;j<n;++j){
			int left,right;
			cin>>left>>right;
			level l(left,right);
			all.push_back(l);
		}
		run(points,steps,n,i+1);
	}
	
}
