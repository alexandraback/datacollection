#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

int main() {
	cout<<"Case #1:"<<endl;
	int N = 16;
	int K = 50;
	srand(1897);
	int onem = 1000000;
	vector<int> primes;
	vector<int> s(onem + 1, 1);
	for (int i = 2; i <= onem; i++) {
		for (int j = 2 * i; j <= onem; j += i)
			s[j] = 0;
	}
	for (int i = 2; i <= onem; i++)
		if (s[i] == 1)
			primes.pb(i);
	REP(_x, K) {
		char c[32];
		int gr[32];
		while (1) {
			REP(i, N) c[i] = rand() & 1;
			c[0] = c[N - 1] = 1;
			int tens = 1;
			for (int mod = 2; mod <= 10; mod++) {
				int good = 0;
				for (int p : primes) {
					if (p > 10000) break;
					LL r = 0, pp = 1;
					REP(i, N) {
						r += pp * c[i];
						r %= p;
						pp *= mod; pp %= p;
					}
					if (r == 0) {
						gr[mod] = p;
						good = 1;
						break;
					}
				}
				if (good == 0) {
					tens = 0;
					break;
				}
			}
			if (tens) {
				//got one
				REP(i, N) cout<<(int)c[N - 1 - i];
				for (int i = 2; i <= 10; i++) cout<<' '<<gr[i];
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}