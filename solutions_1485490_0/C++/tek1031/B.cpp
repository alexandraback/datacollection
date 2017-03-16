#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>
using namespace std;

class thing{
public:
	long long  num,type;
	thing (long long  num,long long  type):num(num),type(type){}
};

vector<thing> toy;
vector<thing> box;
long long  ans;

void put(int toy_idx,int box_idx,long long  count){
//	cout<<toy_idx<<" "<<box_idx<<" "<<count<<endl;
	if(toy_idx>=toy.size() || box_idx>=box.size()) return;

	if(toy[toy_idx].type==box[box_idx].type){
		long long p=min(toy[toy_idx].num,box[box_idx].num);
		count+=p;
		toy[toy_idx].num-=p;
		box[box_idx].num-=p;

		int bef_toy=toy_idx;
		int bef_box=box_idx;

		ans=max(ans,count);
		if(toy[toy_idx].num==0){
			toy_idx++;
		}
		if(box[box_idx].num==0){
			box_idx++;
		}
		put(toy_idx,box_idx,count);
		toy[bef_toy].num+=p;
		box[bef_box].num+=p;
	}
	else{
		put(toy_idx+1,box_idx,count);
		put(toy_idx,box_idx+1,count);
	}
}

int main()
{
	int T;cin>>T;
	for(int t=1;t<=T;t++){
		int N,M;
		cin>>N>>M;
		toy.clear();
		box.clear();
		for(int i=0;i<N;i++){
			long long  n,a; cin>>n>>a;
			toy.push_back(thing(n,a));
		}

		for(int i=0;i<M;i++){
			long long int n2,a; cin>>n2>>a;
			box.push_back(thing(n2,a));
		}
		ans=0;
		put(0,0,0);

		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}