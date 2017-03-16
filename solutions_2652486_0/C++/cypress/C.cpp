#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int R,N,M,K;
int a[15];

void calc(){
	int t=1;
	for (int i=1;i<=K;i++) {
		cin>>a[i];
		t=max(a[i],t);
	}
	int s[6];
	memset(s,0,sizeof(s));
	for (int k=5;k>=2;k--) {
		while (t%k==0) {
			s[k]++;
			t/=k;
		}
	}
	int ss=0;
	for (int i=2;i<=5;i++) {
		for (int j=1;j<=s[i];j++) {
			cout<<i;
			ss++;
			if (ss==N) break;
		}
		if (ss==N) break;
	}
	for (int j=1;j<=(N-ss);j++) cout<<2;
	cout<<"\n";
}

void solve(){
	cin>>R>>N>>M>>K;
	for (int z=1;z<=R;z++) {
		calc();
	}
}

int main(){
	
	freopen("C-small.in","r",stdin);
	freopen("C-small.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int cs=1;cs<=T;cs++) {
		cout<<"Case #"<<cs<<":\n";
		solve();
	} 
	
	
	return 0;
}
