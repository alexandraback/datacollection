#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <cassert>
#include <ctime>
#include <list>
#include <bitset>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
 
template<typename T> inline T Abs(T a){ return a>0 ? a : -a; }
template<typename T> inline T sqr(T a){ return a*a; }
template<typename T> inline void relaxMin(T &a,T b){ if (b<a) a=b; }
template<typename T> inline void relaxMax(T &a,T b){ if (b>a) a=b; }

#define _(a,val) memset(a,val,sizeof a);
#define REP(i, a, b) for(int i(a),_bb(b); i < _bb; ++i)
//#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
 
const int INF = (int)1E9;
//const int INF = INT_MAX/2-1;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
#define y1 idfgoseincdjkg
typedef vector<int> vint;
typedef pair<int,int> pii;

#ifdef NDEBUG
#undef assert
#define assert(expr){if (!(expr)) { ++*(char*)0; } }
//#define assert(expr){if (!(expr)) { char *a=0; *a=10; } }
#endif

#define VMAX 1500000
int sz;
struct vertex {
	int next[26];
	bool leaf;
	int p;
	char pch;
	//int link;
	//int go[26];
} t[VMAX];
 
void init_bor() {
	t[0].p = -1;
	//t[0].p = t[0].link = -1;
	memset (t[0].next, 255, sizeof t[0].next);
	//memset (t[0].go, 255, sizeof t[0].go);
	sz = 1;
}
 
void add_string(const string & s) {
	int v = 0;
	for (size_t i=0; i<s.length(); ++i) {
		char c = s[i]-'a';
		if (t[v].next[c] == -1) {
			memset (t[sz].next, 255, sizeof t[sz].next);
			//memset (t[sz].go, 255, sizeof t[sz].go);
			//t[sz].link = -1;
			t[sz].p = v;
			t[sz].pch = c;
			t[v].next[c] = sz++;
		}
		v = t[v].next[c];
	}
	t[v].leaf = true;
}
 
/*int go (int v, char c);
 
int get_link (int v) {
	if (t[v].link == -1)
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go (get_link (t[v].p), t[v].pch);
	return t[v].link;
}
 
int go (int v, char c) {
	if (t[v].go[c] == -1)
		if (t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
	return t[v].go[c];
}*/


void pre(){
	freopen("dict.txt", "rt", stdin);
	init_bor();
	string s;
	//int max_l = 0;
	while(cin>>s){
		add_string(s);
		//max_l=max(max_l,(int)s.length());
	}
	//cout<<max_l<<endl;
	//exit(0);
}

//длина, количество хороших букв
int dp[100][5];
char s[100];

void solve(){
	gets(s);
	int n = strlen(s);
	//string s; cin>>s;
	//int n = s.length();
	REP(i,1,n+1) REP(j,0,5) dp[i][j]=INF;
	REP(j,0,5) dp[0][j]=0;
	REP(i,0,n){
		//0
		{
			int p = 0;
			int cur = 0;
			while(cur != -1){
				if (t[cur].leaf){
					REP(j,0,5){
						int dist = min(4,j+p);
						REP(k,0,dist+1)
							dp[i+p][k]=min(dp[i+p][k],dp[i][j]);
					}
				}
				if (i+p>=n) break;
				char c = s[i+p]-'a';
				cur = t[cur].next[c];
				p++;
			}
			i=i;
		}
		//1
		{
			REP(j,0,5){
				for(int pos=max(0,4-j);pos<=9;pos++) for(int ch=0;ch<26;ch++){
					int p = 0;
					int cur = 0;
					while(cur != -1){
						if (t[cur].leaf){
							int good = min(4,j+p);
							int add = 0;
							if (pos+1<=p){
								good = min(4,p-pos-1);
								add=1;
							}
							REP(k,0,good+1)
								dp[i+p][k]=min(dp[i+p][k],dp[i][j]+add);
						}
						if (i+p>=n) break;
						char c = s[i+p]-'a';
						if (p==pos && c==ch) break;
						if (p==pos) c=ch;//!!
						cur = t[cur].next[c];
						p++;
					}
				}
			}
			i=i;
		}
		//2
		{
			REP(j,0,5){
				for(int pos1=max(0,4-j);pos1<=9;pos1++) for(int ch1=0;ch1<26;ch1++){
				for(int pos2=pos1+5;pos2<=9;pos2++) for(int ch2=0;ch2<26;ch2++){
					int p = 0;
					int cur = 0;
					while(cur != -1){
						if (t[cur].leaf){
							int good = min(4,j+p);
							int add = 0;
							if (pos1+1<=p){
								good = min(4,p-pos1-1);
								add+=1;
							}
							if (pos2+1<=p){
								good = min(4,p-pos2-1);
								add+=1;
							}
							REP(k,0,good+1)
								dp[i+p][k]=min(dp[i+p][k],dp[i][j]+add);
						}
						if (i+p>=n) break;
						char c = s[i+p]-'a';
						if (p==pos1 && c==ch1) break;
						if (p==pos2 && c==ch2) break;
						if (p==pos1) c=ch1;//!!
						if (p==pos2) c=ch2;//!!
						cur = t[cur].next[c];
						p++;
					}
				}
				}
			}
			i=i;
		}
	}
	int ans = INF;
	REP(j,0,5)
		ans=min(ans,dp[n][j]);
	assert(ans != INF);
	cout<<ans<<endl;
}


//#define TASK "equality"
int main(){
#ifdef acm
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	//freopen("error.txt", "wt", stderr);
#else
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	//freopen(TASK".in", "rt", stdin);
	//freopen(TASK".out", "wt", stdout);
#endif
	srand(0xA1B2C3D4);

	pre();

	freopen("input.txt", "rt", stdin);
	int tc; scanf("%d\n",&tc);
	REP(i,0,tc){
		printf("Case #%d: ",i+1);
		solve();
	}
	//solve();


#ifdef acm
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);
#endif
	return 0;
}