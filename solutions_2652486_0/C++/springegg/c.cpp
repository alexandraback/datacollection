#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#define maxl 1000000000
#define maxn 11000
#define maxm 10000
using namespace std;
set<int> ss;
int n,m,k;

void did(){
	int a[10],two[10],b[10],i,j,tmp;
	for(i=1;i<=k;++i)cin>>b[i];
	two[1]=1;
	for(i=2;i<=4;++i)two[i]=two[i-1]<<1;
	for(a[1]=2;a[1]<=m;++a[1])
	for(a[2]=2;a[2]<=m;++a[2])
	for(a[3]=2;a[3]<=m;++a[3]){
		ss.clear();
		for(i=0;i<two[4];++i){
			tmp=1;
			for(j=1;j<=3;++j)if(two[j]&i)tmp*=a[j];
			ss.insert(tmp);
		}
		for(i=1;i<=k;++i)if(!ss.count(b[i]))break;
		if(i>k){
			cout<<a[1]<<a[2]<<a[3]<<endl;
			return;
		}
	}
}

void solve(){
	int r;
	cin>>r>>n>>m>>k;
	for(int i=1;i<=r;++i)did();
}

int main(){
	ios::sync_with_stdio(false);
	int t,i;
	cin>>t;
	for(i=1;i<=t;++i){
		cout<<"Case #"<<i<<":"<<endl;
		solve();
	}
	return 0;
}