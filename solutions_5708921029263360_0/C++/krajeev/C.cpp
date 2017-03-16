#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int total = 0;
int J,P,S,K;
vector<pair<pair<int,int>,int> > ans;
void fun(int i,int j,int k,int total_temp, map<pair<int,int>,int> JP, map<pair<int,int>,int> PS, map<pair<int,int>,int> JS, vector<pair<pair<int,int>,int> > ans_temp){
	//cout<<i<<" "<<j<<" "<<k<<endl;

	int aa = JP[make_pair(i,j)];
	int bb = PS[make_pair(j,k)];
	int cc = JS[make_pair(i,k)];
	JP[make_pair(i,j)] = aa+1;
	PS[make_pair(j,k)] = bb+1;
	JS[make_pair(i,k)] = cc+1;
	ans_temp.push_back(make_pair(make_pair(i,j),k));
	//if(i==1){
	//	cout<<"ind" <<i<<" "<<j<<" "<<k<<endl;
	//	cout<<" c "<<aa+1<<" "<<bb+1<<" "<<cc+1<<endl;
	//}
	
	vector<pair<pair<int,int>,int> > ans_temp2;
	if(k+1<=S){
		int a = JP[make_pair(i,j)];
		int b = PS[make_pair(j,k+1)];
		int c = JS[make_pair(i,k+1)];
		if(a<K && b<K && c< K){
			fun(i,j,k+1,total_temp+1,JP,PS,JS,ans_temp);
			ans_temp2.insert(ans_temp2.end(),ans_temp.begin(),ans_temp.end());
		}
	}

	if(j+1<=P){
		int a = JP[make_pair(i,j+1)];
		int b = PS[make_pair(j+1,k)];
		int c = JS[make_pair(i,k)];
		if(a<K && b<K && c< K){
			fun(i,j+1,k,total_temp+1,JP,PS,JS,ans_temp);
			ans_temp2.insert(ans_temp2.end(),ans_temp.begin(),ans_temp.end());
		}
	}
	if(i+1<=J ){
		int a = JP[make_pair(i+1,j)];
		int b = PS[make_pair(j,k)];
		int c = JS[make_pair(i+1,k)];
		if(a<K && b<K && c< K){
			fun(i+1,j,k,total_temp+1,JP,PS,JS,ans_temp);
			ans_temp2.insert(ans_temp2.end(),ans_temp.begin(),ans_temp.end());
		}
	}



	//////////////////////////////////

	if(ans.size()<ans_temp2.size()){
		total =total_temp;
		ans =  ans_temp;
	}




	/////////////////////////////////

}
int main(){
	int t;
	cin>>t;
	for(int num_case=1;num_case <= t;num_case++){
		
		cin>>J>>P>>S>>K;
		map<pair<int,int>,int> JP;
		map<pair<int,int>,int> PS;
		map<pair<int,int>,int> JS;
		total =  0;
		ans = vector<pair<pair<int,int>,int> >();
		vector<pair<pair<int,int>,int> > ans_temp;
		
		fun(1,1,1,1,JP,PS,JS,ans_temp);
		cout<<"Case #"<<num_case<<": ";
		cout<<total<<endl;
		for(int i=0;i<total;i++){
			cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
		}
	}
}