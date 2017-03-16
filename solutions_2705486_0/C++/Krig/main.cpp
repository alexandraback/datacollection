#include<functional>
#include<algorithm>
//#include<iostream>
#include<numeric>
#include<cassert>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<queue>
//#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)
#define FOReach(it,V) for(__typeof((V).begin()) it=(V).begin();it!=(V).end();++it)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int stmp;
#define scanf stmp=scanf


const int MAX = 1300000;
const int N = 4100;
const int INF = 1000000001;

int next[MAX][26];
bool end[MAX];
char A[MAX];
int cnt = 1;

void read_dict() {
	memset(next, -1, sizeof next);
	FILE *f = fopen("garbled_email_dictionary.txt", "r");
	char word[111];
	int l = 0;
	while(fscanf(f, "%s", word) != EOF)
	{
		l = max(l, (int)strlen(word));
		int v = 0;
		for(char* c=word;*c;c++)
		{
			if(next[v][*c-'a'] == -1)
				next[v][*c-'a'] = cnt++;
			v = next[v][*c-'a'];
		}
		end[v] = true;
	}
	fclose(f);
	debug("%d\n", cnt);
	debug("%d\n", l);
}

bool find(const string &t) {
	int v = 0;
	REP(i,SIZE(t))
		if(next[v][t[i]-'a'] == -1) return false;
		else v = next[v][t[i]-'a'];
	return end[v];
}

bool f[N][11];
int best[N][11][10];

int n;

void init(int ind, int len) {
	string t = string(A+ind, len);
	f[ind][len] = find(t);
	REP(i,len)
	{
		best[ind][len][i] = INF;
		char _c1 = t[i];
		REP(c1,26)
			if(c1 != _c1) {
				t[i] = 'a'+c1;
				if(find(t)) {
					best[ind][len][i] = i;
					break;
				}
				else {
					FOR(j,i+5,len-1)
					{
						char _c2 = t[j];
						REP(c2,26)
							if(c2 != _c2) {
								t[j] = 'a'+c2;
								if(find(t)) {
									best[ind][len][i] = j;
									t[j] = _c2;
									c1 = c2 = 26; j = len;
									break;
								}
							}
						t[j] = _c2;
					}
				}
			}
		t[i] = _c1;
	}
}

int dp[N][5];

int solve() {
	FOR(l,1,10)
		FOR(i,1,n-l+1)
			init(i, l);
	dp[0][4] = 0;
	FOR(i,1,n)
	{
		REP(j,5) dp[i][j] = INF;
		FOR(l,1,min(i,10))
		{
			if(f[i-l+1][l]) {
				REP(t,5) dp[i][min(t+l,4)] = min(dp[i][min(t+l,4)], dp[i-l][t]);
			}
			else {
				REP(c,l)
				{
					if(best[i-l+1][l][c] != INF) {
						if(best[i-l+1][l][c] == c) {
							REP(t,5)
								if(t+c >= 4)
									dp[i][min(4, l-c-1)] = min(dp[i][min(4, l-c-1)], dp[i-l][t]+1);
						}
						else {
							REP(t,5)
								if(t+c >= 4)
									dp[i][min(4, l-best[i-l+1][l][c]-1)] = min(dp[i][min(4, l-best[i-l+1][l][c]-1)], dp[i-l][t]+2);
						}
					}
				}
			}
		}
	}
	int res = dp[n][0];
	REP(i,4) res = min(res, dp[n][i+1]);
	return res;
}

int main(int argc, char *argv[]) {
	read_dict();
//	printf("%d\n", find(string("produ")));
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		scanf("%s", A+1);
		n = strlen(A+1);
		printf("%d\n", solve());
	}
	return 0;
}

