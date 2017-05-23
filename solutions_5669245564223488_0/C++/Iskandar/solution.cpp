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

int main() {

  int T;
  long long MODULO = 1000000007;

  cin >> T;

  for (int i = 1; i <= T; i++) {
    string input[101];
    int app[26];
    int N, results = 0;
    /** Reading Inputs */
    for (int j = 0; j < 26; j++) app[j] = 0;
    cin >> N;

    int* permute = (int*) malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
        permute[j] = j;
    }
    for (int j = 0; j < N; j++) {
        string temp;
        cin >> temp;
        input[j] = temp[0];
        for (int k = 1; k < temp.length()-1; k++) {
            if (temp[k] != temp[k-1]) input[j] = input[j] + temp[k];
        }
        input[j] = input[j] + temp[temp.length()-1];
        for (int k = 0; k < input[j].length(); k++) {
            app[input[j][k] - 'a']++;
        }
    }

    /** Process */
    do {
        bool isValid = true;
        string concat = "";
        for (int j = 0; j < N; j++) {
            // check j with j+1
            concat = concat + input[permute[j]];
        }
        for (int j = 0; j < 26; j++) {
            bool isFound = false;
            int counter = 0;
            for (int k = 0; k < concat.length(); k++) {
                if (app[j] == 0) break;
                if (isFound) {
                    if (concat[k] != (char) ((int) 'a' + j)) {
                        if (counter != app[j]) {
                            isValid = false;
                        }
                        break;
                    } else counter++;
                } else if (concat[k] == (char) ((int) 'a' + j)) {
                    if (!isFound) isFound = true;
                    counter++;
                }
            }
            if (!isValid) break;
        }
        if (isValid) results++;
    } while (next_permutation(permute, permute + N));

    /** Output */
    cout << "Case #" << i << ": ";
    cout << results;
    cout << endl;

  }

  return 0;
}
/** Created by freedomofkeima */
