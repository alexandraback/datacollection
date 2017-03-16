#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()


string s;
int tests;

LL gcd(LL a, LL b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main() {
	scanf("%d",&tests);
	for (int test = 1; test <= tests; test++) {	
		printf("Case #%d: ", test);
		cin >> s;
		LL a = 0; LL b = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '/') {
				for (int j = i + 1; j < s.size(); j++) {
					b = b * 10LL + s[j] - '0';
				}
				break;
			}
			a = a * 10LL + s[i] - '0';
		}
		
		LL c = gcd(a,b);
		a /= c; b /= c;
		
		int bits = 0;
		LL b2 = b;
		while(b2) {
			if (b2%2) bits++;
			b2 /= 2;
		}
		
		if (bits != 1) {
			printf("impossible\n");
			continue;
		}
		
		
		for (int i = 1;; i++) {
			a *= 2LL;
			if (a >= b) {
				printf("%d\n",i);
				break;
			}
		}		
	}
	return 0;
}
			

			
		
		


