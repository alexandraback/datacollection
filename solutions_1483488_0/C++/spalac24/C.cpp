#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#define D(x) cout<<#x "is : "<<x<<" in line "<<__LINE__<<endl;
#define MAXN 2000005
using namespace std;

int pow (int a, int b) {
	int ax = 1;
	while(b--){
		ax*=a;
	}
	return ax;
}

unsigned long long fact (int x) {
	if (x < 2)
		return 1;
	return x*fact(x-1);
}

int main () {
	int t,n,m;
	cin>>t;
	for (int cas = 1; cas <= t; ++cas) {
		cout<<"Case #"<<cas<<": ";
		bool arr [MAXN] = {false};
		int digs;
		cin>>n>>m;
		digs = log10(n+1);
		int pot = pow(10,digs);
		unsigned long long ans = 0;
		while(n < m) {
			if (!arr[n]){
				int x = n;
				arr[x] = true;
				int tot = 1;
				for (int i = 0; i < digs; ++i) {
					int dig = x%10;
					x /= 10;
					x += dig*pot;
					if (x == n){
						break;
					}
					if (x < MAXN)
						arr[x] = true;
					if (x <= m && x >= n) {
						++tot;
					}
				}
				ans += (tot*(tot-1))/2;
			}
			++n;
		}
		cout<<ans<<endl;
	}
	
}
