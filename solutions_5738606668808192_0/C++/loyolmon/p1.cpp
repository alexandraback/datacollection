#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll dumbPow(ll base, ll exp) {
	ll ans=1;
	while (--exp>=0) ans*=base;
	return ans;
}

void nextStr(string &v) {
	int i=v.size()-1;
	while (v[i]=='1') i--;
	v[i++]='1';
	while (i<v.size()) v[i++]='0';
}

int main() {
	int T; cin>>T;
	for (int testCase=1; testCase<=T; testCase++) {
		printf("Case #%d:\n", testCase);
		
		ll N, J; cin>>N>>J;
		string str(N/2-2, '0');
		
		while(J>0) {
			cout<<1<<str<<11<<str<<1;
			for (ll i=2; i<=10; i++) printf(" %I64d", dumbPow(i, N/2)+1);
			printf("\n");
			
			nextStr(str);
			J--;
		}
	}
	return 0;
}
