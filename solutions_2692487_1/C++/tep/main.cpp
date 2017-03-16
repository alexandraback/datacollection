#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a;
vector<int> mote;
void initZ(){
	mote.clear();
}
int minn(int x,int b){
	if(x>b)return b;
	return x;
}
int travel(){
	int time = 0;
	for(int i=0;i<n;++i){
		if(mote[i]<a){
			a+=mote[i];
		}else{
			if(mote[i]<a*2-1){
				time++;
				a=a*2-1+mote[i];
			}else{
				time++;
			}
		}
	}
	return time;
}
int recur(int i,int A){
	if(i==n-1 && mote[i]<A)return 0;
	//cout<<i<<":"<<A<<endl;
	if(mote[i]<A)return recur(i+1,A+mote[i]);
	else{
		if(A==1)return (n-i);
		return minn(recur(i,A+A-1)+1,(n-i));
	}
}
void greedy(){
	int num;
	cin>>a>>n;
	initZ();

	for(int i=0;i<n;++i){
		cin>>num;
		mote.push_back(num);
	}

	sort(mote.begin(),mote.end());
}
void solve(){
	int t;
	cin>>t;
	for(int i=1;i<=t;++i){
		greedy();
		cout<<"Case #"<<i<<": "<<recur(0,a)<<endl;
		//cout<<"Case #"<<i<<": "<<travel()<<endl;
	}
}
int main(){
	solve();
}