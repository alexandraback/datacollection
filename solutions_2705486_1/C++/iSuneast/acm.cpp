#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class T>inline void ChkMax(T &a,const T &b){if(a < b) a = b;}
template<class T>inline void ChkMin(T &a,const T &b){if(b < a) a = b;}
const int dx[]={ 0, 0,-1, 1,-1, 1,-1, 1};
const int dy[]={-1, 1, 0, 0,-1,-1, 1, 1};
string dir[]={"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

typedef long long LL;
typedef pair<int, int> pii;

#define LOWBIT(v) ((v)&(-(v)))
#define POW2(p) (1<<(p))
#define KTH_BIT(v, k) ((v) & POW2(k))
#define MERGE_BIT(v, k) ((v) | POW2(k))
#define INF 0x3f3f3f3f
#define eps 1e-5

// -------------------------------------------

#define MAXN 4003
#define MOD 
#define MAXNODE 4000000
#define MAXWORD 521200
#define MAXL 12

char dict[MAXWORD][MAXL];
int dn;

void init() {
	FILE *fin = fopen("garbled_email_dictionary.txt", "r");
	
	for(dn = 0; fscanf(fin, "%s", dict[dn]) != EOF; ++dn) {
	}
}

char s[MAXN];
int dp[MAXN][5];

void update(char *str, int offset) {
	for(int i=0; i<dn; ++i) {
		int j = 0;
		int last = -100, cnt = 0;
		int first = -1;
		for( ; str[j] && dict[i][j]; ++j) {
			if(str[j] != dict[i][j]) {
				if(j-last < 5) {
					cnt = -1;
					break;
				} else {
					if(first == -1) {
						first = j;
					}
					last = j;
					cnt ++;
				}
			}
		}
		if(cnt == -1) {
			// not match
			continue;
		}
		if(!str[j] && dict[i][j]) {
			// not a complete word
			continue;
		}
		for(int k=0; k<5; ++k) {
			if(cnt == 0) {
				ChkMin(dp[offset+j][min(j+k, 4)], dp[offset][k]);
			} else {
				if(first+1+k >= 5) {
					ChkMin(dp[offset+j][min(j-1-last, 4)], dp[offset][k]+cnt);
				}
			}
		}
	}
}

int solve() {
	memset(dp, 0x3f, sizeof(dp));
	for(int i=0; i<5; ++i) {
		dp[0][i] = 0;
	}
	int len = strlen(s);
	for(int i=0; i<len; ++i) {
		update(s+i, i);
	}
	int key = INF;
	for(int i=0; i<5; ++i) {
		ChkMin(key, dp[len][i]);
	}
	return key;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C-large.in", "r", stdin);
	freopen("C:\\Users\\suneast\\Downloads\\C.out", "w", stdout);
#endif

	init();
	
	int dataset;
	scanf("%d", &dataset);
	for(int cas=1; cas<=dataset; ++cas) {
		scanf("%s", s);
		printf("Case #%d: %d\n", cas, solve());
	}

	return 0;
}
