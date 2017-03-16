#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=100001;
const int INF=0x7FFFFFFF;
const double eps=1e-8;
const double pi=acos(-1.0);


int n;
int a[1000];
int ca;
vector<int> v[3000000];
int f[3000000];

void init(){
	cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
}

void print(int m){
	int t=0;
	for (int i=0; i<n; i++)
		if (m&(1<<i)){
			if (t++) cout<<' ';
			cout<<a[i];
		}
	cout<<endl;
}

void solve(){
	for (int i=0; i<(1<<n); i++)
		for (int j=0; j<n; j++)
			if (!(i&(1<<j)))
				f[i+(1<<j)]=f[i]+a[j];
	memset(v,0,sizeof(v));
	for (int i=1; i<(1<<n); i++) v[f[i]].push_back(i);
	for (int i=1; i<(1<<n); i++){
		for (int j=0; j<v[f[i]].size(); j++)
			for (int k=j+1; k<v[f[i]].size(); k++)
				if (!(v[f[i]][j]&v[f[i]][k])){
					print(v[f[i]][j]);
					print(v[f[i]][k]);
					return;
				}
	}
	cout<<"Impossible"<<endl;
	/*
		for (int i=1; i<=n; i++)
			cout<<f[i];
	*/
}

void deal()
{
	cin>>ca;
	for (int i=1; i<=ca; i++){
		cout<<"Case #"<<i<<":"<<endl;
		init();
		solve();
	}
}
int main(){
	freopen("CC.in","r",stdin);
	freopen("CC.out","w",stdout);
	deal();
	return 0;
}

