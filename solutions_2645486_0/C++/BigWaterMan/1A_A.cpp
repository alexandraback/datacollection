/*
by george_cheng
*/
#include<iostream>
using namespace std;
long long max(long long x,long long y){
	if (x>y)return x;
	return y;
}
int e,r,n;
		int v[10000];
int s(int u,int x){
	if (x==n)return 0;
	int ans=0;
	int temp=0;
	for (int i=0;i<=u;++i){
		temp=v[x]*i+s(min(u-i+r,e),x+1);
		if (temp>ans)ans=temp;
	}
	return ans;
}


int main(){

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	int z;
	cin>>z;
	for (int i=0;i<z;++i){

		cin>>e>>r>>n;

		for (int i=0;i<n;++i)cin>>v[i];
		cout<<"Case #"<<i+1<<": "<<s(e,0)<<endl;
	}
}