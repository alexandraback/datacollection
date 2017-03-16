#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>

#define tr(c, i) for(typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
#define all(c) (c).begin(),(c).end()
#define sz(c) int((c).size())
#define INF 1000000000
#define EPS 1e-9
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

int T, a, b;
char s[15], B[15];
int len;

int main() {
	scanf("%d", &T);
	
	for(int tc = 0; tc < T; ++tc) {
		scanf("%d%d", &a, &b);
		
		sprintf(B, "%d", b);
		len = strlen(B);
		
//		printf("B=%s, len=%d\n", B, len);
		
		set <ii> aans;
		int ans = 0;
		for(int i = a; i <= b; ++i) {
			sprintf(s, "%d", i);
			if(strlen(s) != len) continue;
//			printf("s=%s\n", s);
			for(int j = 1; j < len; ++j) {
//				if(s[j] == '0') continue;	// gabole leading zeroes
				
				bool valid = 0;	// harus > i 
				for(int k = 0; k < len; ++k) {
					char now = s[(k+j)%len], ori = s[k];
					if(now < ori) break;	// lesser
					if(now > ori) { valid = 1; break; }
					// kalo == lanjut saja
				}	
				
				if(valid) {
					// harus <= b
					for(int k = 0; k < len; ++k) {
						char now = s[(k+j)%len], bb = B[k];
						if(now > bb) { valid = 0; break; }
						if(now < bb) break;	// valid
						// kalo == lanjut saja	
					}
				}	
				
				if(valid) {
//					printf("i=%d, j=", i);
//					for(int k = 0; k < len; ++k) printf("%c", s[(k+j)%len]); puts("");
					int jj = 0;
					for(int k = 0; k < len; ++k)
						jj = jj*10 + s[(k+j)%len]-'0';
					
//					if(aans.count(ii(i, jj))) printf("repeat! (%d, %d)\n", i, jj);	
					aans.insert(ii(i, jj));
//					printf("%d %d\n", i, jj);
				}
			}
		}
		
		printf("Case #%d: %d\n", tc + 1, sz(aans));	
	}
	
	return 0;
}
