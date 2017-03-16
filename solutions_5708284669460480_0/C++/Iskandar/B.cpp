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
#include <iomanip>

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

string keyboard, target;

int found(string s, int total_length) {
    if (s.length() == total_length) {
        int res = 0;
        for (int i = 0; i < total_length - target.length() + 1; i++) {
            bool isMatch = true;
            int start_pos = i;
            for (int j = 0; j < target.length(); j++) {
                if (s[start_pos] != target[j]) { isMatch = false; break; }
                start_pos++;
            }
            if (isMatch) res++;
        }
        return res;
    } else {
        int total = 0;
        for (int i = 0; i < keyboard.length(); i++) {
            total += found(s + keyboard[i], total_length);
        }
        return total;
    }
}

int main() {

  int T;

  cin >> T;

  for (int i = 1; i <= T; i++) {

    /** Reading Inputs */
    int counter[26];
    for (int j = 0; j < 26; j++) counter[j] = 0;
    int L, K, S, nex_pos = -1, total_banana = 0;
    double answer = 0;
    cin >> K >> L >> S;
    cin >> keyboard;
    for (int j = 0; j < K; j++) {
        counter[keyboard[j]-'A']++;
    }
    cin >> target;

    /** Process */
    for (int pos = 1; pos < target.length(); pos++) {
        bool isSame = true;
        int ctx = 0;
        for (int q = pos; q < target.length(); q++) {
            if (target[ctx] != target[q]) {isSame = false; break;}
            ctx++;
        }
        if (isSame) {
            nex_pos = pos;
            break;
        }
    }
    if (nex_pos == -1) nex_pos = L;

    total_banana = (S - L) / nex_pos + 1; // in theory, maximum if all available
    bool isExist = true;
    for (int j = 0; j < L; j++) {
        if (counter[target[j] - 'A'] == 0) isExist = false;
    }
    if (!isExist) total_banana = 0;

    if (isExist) {
        int occ = found("", S);
        int total_probs = total_banana;
        for (int j = 1; j <= S; j++) total_probs *= K;
        answer = (double) total_banana * (((double) total_probs - (double) occ) / total_probs);
    } else answer = 0;

    /** Output */
    cout << "Case #" << i << ": ";
    cout << std::fixed;
    cout << std::setprecision(10) << answer;
    cout << endl;

  }

  return 0;
}
/** Created by freedomofkeima */
