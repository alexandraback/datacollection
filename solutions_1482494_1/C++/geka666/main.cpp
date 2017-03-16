#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:256000000")

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
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
 
//const int INF = (int)1E9;
const int INF = INT_MAX/2-1;
const long double EPS = 1E-12;
const long double PI = 3.1415926535897932384626433832795;
//#define y1 usfogiudsogndiogbdouigfbsdlifgsdbg
typedef vector<int> vint;
typedef pair<int,int> pii;

#undef assert
#define assert(expr){if (!(expr)) {char *a = 0; *a = 10;} }

#ifdef acm
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) ;
#endif

vector<pii> v;
vector<int> valid1;
vector<int> valid2;

void solve(){
	int n; cin>>n;
	REP(i,0,n){
		int x,y; cin>>x>>y;
		v.pb(mp(x,y));
	}
	valid1.assign(n,1);
	valid2.assign(n,1);
	int cnt2 = 0;
	bool err = false;
	int cur_cnt = 0;
	int it_cnt = 0;
	while(cnt2 < n && !err){
		int id1 = -1;
		int id2 = -1;
		int id_cnt = 0;
		REP(i,0,n){
			if (valid1[i] && valid2[i] && v[i].second <= cur_cnt){
				id_cnt = 2;
				id1=id2=i;
			}else if (valid2[i] && v[i].second <= cur_cnt){
				id_cnt = 1;
				id2=i;
				id1=-1;
			}else if (valid1[i] && v[i].first <= cur_cnt){
				if (id_cnt == 0){
					id1=i;
					id_cnt = 1;
				}else if (id1!=-1){
					if (v[id1].second < v[i].second){
						id1 = i;
					}
				}
			}
			if (id_cnt == 2) break;
		}
		if (id1 != -1){
			cur_cnt++;
			valid1[id1]=0;
		}
		if (id2 != -1){
			cur_cnt++;
			valid2[id2]=0;
			cnt2++;
		}
		if (id_cnt == 0 && cnt2 < n)
			err = true;
		it_cnt++;
	}
	if (err)
		cout<<"Too Bad"<<endl;
	else
		cout<<it_cnt<<endl;
	v.clear();
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t; scanf("%d\n",&t);
	for(int i=0;i<t;i++){
		printf("Case #%d: ",i+1);
		solve();
	}
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);

	return 0;
}