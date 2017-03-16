#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <time.h>
#include <bitset>
#include <list>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
typedef vector<string> vstr;
typedef vector<char> vc;

double EPS = 1e-9;
int INF = 2000000000;
long long INFF = 8000000000000000000LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORL(a,b,c) for (LL (a)=(b);(a)<=(c);++(a))
#define FORLSQ(a,b,c) for (int (a)=(b);(LL)(a)*(LL)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define REPD(i,n) FORD(i,n,1)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
#define READ(n,data) {scanf("%d",&n); REPN(i,n) scanf("%d",&data[i]);}

inline string IntToString(int a){
    char x[100];
    sprintf(x,"%d",a); string s = x;
    return s;
}

inline int StringToInt(string a){
    char x[100]; int res;
    strcpy(x,a.c_str()); sscanf(x,"%d",&res);
    return res;
}

inline string GetString(void){
	char x[1000005];
	scanf("%s",x); string s = x;
	return s;
}

inline string uppercase(string s){
	int n = SIZE(s);
	REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
	return s;
}

inline string lowercase(string s){
	int n = SIZE(s);
	REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
	return s;
}

inline void OPEN (string s) {
    freopen ((s + ".in").c_str (), "r", stdin);
    freopen ((s + ".out").c_str (), "w", stdout);
}

char map[21][21];
int N, M, K;

int checkMap() {
    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            bool isValid = false;
            if (map[i][j] == 'x') {
                res++;
                continue;
            }
            // up
            int position_up = j;
            while (position_up > 0) {
                position_up--;
                if (map[i][position_up] == 'x') {
                    isValid = true;
                }
            }
            // left
            if (!isValid) continue;
            isValid = false;
            int position_left = i;
            while (position_left > 0) {
                position_left--;
                if (map[position_left][j] == 'x') {
                    isValid = true;
                }
            }
            // down
            if (!isValid) continue;
            isValid = false;
            position_up = j;
            while (position_up < M - 1) {
                position_up++;
                if (map[i][position_up] == 'x') {
                    isValid = true;
                }
            }
            // right
            if (!isValid) continue;
            isValid = false;
            position_left = i;
            while (position_left < N-1) {
                position_left++;
                if (map[position_left][j] == 'x') {
                    isValid = true;
                }
            }
            if (isValid) {
                res++;
            }
        }
    }
    return res;
}

int main() {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    int temp, results = -1;
    /** Reading Inputs */
    cin >> N >> M >> K;

    for (int j = 0; j < 21; j++)
        for (int k = 0; k < 21; k++)
            map[j][k] = '.';

    /** Process */
    if (K <= 3) results = K;
    else if (N < 3 || M < 3){
        results = K;
    } else {
        for (int j = 3; j <= N; j++) {
            for (int t = 3; t <= M; t++) {
                int enclosure = (j * t) - 4;
                if (K <= enclosure) {
                    int stone = (j - 2) * 2 + (t - 2) * 2;
                    if (results == -1 || stone < results) {
                        results = stone;
                    }
                }
            }
        }
        if (K > N * M - 4) {
            results = (N - 2) * 2 + (M - 2) * 2;
            if (K >= N * M - 3) results++;
            if (K >= N * M - 2) results++;
            if (K >= N * M - 1) results++;
            if (K >= N * M) results++;
        }
    }

    /** Output */
    cout << "Case #" << i << ": ";
    cout << results;
    cout << endl;

  }

  return 0;
}
/** Created by freedomofkeima */
