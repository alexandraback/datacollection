#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int motes[110];
int dp[110];

int main() {
	int cases;
	cin >> cases;
	for (int c = 1; c <= cases; ++c) {
		printf("Case #%d: ",c);
		int a, n;
		cin >> a >> n;
		for(int i=0; i<n; ++i){
			cin >> motes[i];
			dp[i] = 99999;
		}
		sort(motes, motes+n);
		
		int add = 0;
		for(int i=0; i<n; ++i){
			if(motes[i] < a) a+= motes[i];
			else{
				while(add <= 100 && motes[i] >= a){
					a+=a-1;
					++add;
				}
				a+=motes[i];

				if(add>100) break;
			}
			dp[i] = add;
		}
		int best = n;
		for(int i=0; i<n; ++i){
			best = min(best, dp[i]+n-i-1);
			//cout << i << " " << dp[i] << " " << n-i-1 << endl;
		}
		cout << best << endl;
	}
	return 0;
}

