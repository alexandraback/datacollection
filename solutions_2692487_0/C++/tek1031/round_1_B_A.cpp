#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> mote;
int A,N,T;
vector<int> cap;

int ans;

int get(int size){
	for(int i=0;i<mote.size();i++){
		if(mote[i]>=size){
			return mote.size()-i;
		}
	}
	return 0;
}

void calc(int idx,int size,int cost){
//	cout<<idx<<" "<<size<<" "<<cost<<endl;
	if(idx>=mote.size()){
		ans=min(ans,cost);
		return;
	}
	if(cost>=ans){
		return;
	}
	if(size>mote[idx]){
		calc(idx+1,size+mote[idx],cost);
	}
	else{
		ans=min(ans,cost+(int)mote.size()-idx);
		if(size>1)
			calc(idx,size*2-1,cost+1);
	}
}

int main(){
	int T;
	cin>>T;
	cap=vector<int>(1000000,-1);
	for(int t=1;t<=T;t++){
		ans=mote.size();
		cin>>A>>N;
		mote=vector<int>(N);
		for(int i=0;i<N;i++)
			cin>>mote[i];
		sort(mote.begin(),mote.end());
		ans=mote.size();
		calc(0,A,0);
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}