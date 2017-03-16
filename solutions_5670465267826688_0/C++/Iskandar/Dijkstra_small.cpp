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
#include <map>
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

int converter(int l_temp, char r) {
    bool is_negative = false;
    int l;
    if (l_temp < 0) {
        is_negative = true;
        l = l_temp * -1;
    } else l = l_temp;
    int ans;
    if (l == 1) {
        if (r == 'i') ans = 2;
        if (r == 'j') ans = 3;
        if (r == 'k') ans = 4;
    } else if (l == 2) {
        if (r == 'i') ans = -1;
        if (r == 'j') ans = 4;
        if (r == 'k') ans = -3;
    } else if (l == 3) {
        if (r == 'i') ans = -4;
        if (r == 'j') ans = -1;
        if (r == 'k') ans = 2;
    } else if (l == 4) {
        if (r == 'i') ans = 3;
        if (r == 'j') ans = -2;
        if (r == 'k') ans = -1;
    }
    if (is_negative) return ans * -1;
    else return ans;
}

int dp[10005][10005];

int main() {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {

    /** Reading Inputs */
    bool isPossible = false;
    long long L, X;
    string input, p;
    cin >> L >> X;
    cin >> input;
    for (int j = 1; j <= X; j++) {
        p += input;
    }

    /** Process */
    for (int j = 0; j < p.length(); j++) {
        if (p[j] == 'i') dp[j][j] = 2;
        else if (p[j] == 'j') dp[j][j] = 3;
        else dp[j][j] = 4;
        for (int k = j+1; k < p.length(); k++) {
            dp[j][k] = converter(dp[j][k-1], p[k]);
        }
    }


    for (int j = 0; j < p.length()-2; j++) {
        if (dp[0][j] == 2) {
            for (int k = j+1; k < p.length()-1; k++) {
                if (dp[j+1][k] == 3 && dp[k+1][p.length()-1] == 4) {
                    isPossible = true;
                    break;
                }
            }
        }
        if (isPossible) break;
    }

    /** Output */
    cout << "Case #" << i << ": ";
    if (isPossible) cout << "YES";
    else cout << "NO";
    cout << endl;

  }

  return 0;
}
/** Created by freedomofkeima */
