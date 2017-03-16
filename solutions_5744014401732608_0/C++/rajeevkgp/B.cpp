#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 7;
int n, t;
int b;
long long m;
long long c[50];
void main2() {
	cin>>b>>m;
	if(m > (1ll<<(b-2))) cout<<"IMPOSSIBLE"<<'\n';
	else {
		cout<<"POSSIBLE"<<'\n';
		int x[b][b];
		memset(x,0,sizeof(x));
		long long next;
		for(next=0;(1ll<<next) <= m;next++) {
			for(int i=0;i<next;i++) {
				x[i][next] = 1;
			}
			x[next][b-1] = 1;
		}
		// cout<<(1ll<<next) <<" "<<m<<'\n';
		m -= (1ll<<(next-1));
		if(m) x[next][b-1] = 1;
		for(int i=55;i>=1;i--) {
			if((1ll<<(i-1)) <= m) {
				x[i][next] = 1;
				m -= (1ll<<(i-1));
			}
		}
		for(int i=0;i<b;i++,cout<<'\n') {
			for(int j=0;j<b;j++) cout<<x[i][j];
		}
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("I.in","r",stdin);
		freopen("O.out","w",stdout);
	#endif
	c[1] = c[2] = 1;
	for(int i=3;i<60;i++) {
		c[i] = c[i-1] + c[i-1];
	}
	cin>>t;
	for(int cases=1;cases<=t;cases++) {
		cout<<"Case #"<<cases<<": ";
		main2();
	}
	return 0;
}