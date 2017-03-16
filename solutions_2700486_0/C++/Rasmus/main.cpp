#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <stack>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define mp make_pair
#define pb push_back
#define INF (1e9)

typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const double pi = acos(-1.0);
const int inf =(int) 1e9;

const double eps = 1e-4;
const int ss=(int)1e6+3;
const int base=inf;

bool pred (const int& i, const int& j) 
{
	return i>j;
}

int n,x,y;
int z = 26;
int kol = 0;
int all = 0;
VVI ans;

int dx[] = {-2,-1,0,1,2,-4,-3,-2,-1,0,1,2,3,4,-6,-5,-4,-3,-2,-1,1,2,3,4,5,6};
int dy[] = {0,1,2,1,0,0,1,2,3,4,3,2,1,0,0,1,2,3,4,5,5,4,3,2,1,0};
int sz[] = {9,9,9,9,9,14,14,14,14,14,14,14,14,14,23,23,23,23,23,23,23,23,23,23,23,23};

void go(set<PII> m) 
{
	if ((int)m.size()-9 == n) {
		//SORT(a);
		bool result = true;
		/*FOR(i,ans.size()) {
			bool t = true;
			FOR(j,a.size()) {
				if (a[j]!=ans[i][j]) {
					t = false;
					break;
				}
			}
			if (t) {
				result = false;
				break;
			}
		}*/
		if (result) {
			//ans.push_back(a);
			++all;
			if (m.find(mp(x,y))!=m.end()) {
				++kol;
			}
		}
		return;
	}
	FOR(i,26) {
		if (m.size()>=sz[i] &&
			m.find(mp(dx[i]-1,dy[i]-1))!=m.end() &&
			m.find(mp(dx[i]+1,dy[i]-1))!=m.end() && 
			m.find(mp(dx[i],dy[i]))==m.end()) {
			set<PII> s = m;
			s.insert(mp(dx[i],dy[i]));
			/*a.push_back(dx[i]);
			a.push_back(dy[i]);*/
			go(s);
		}
	}
}

int main()
{
//#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
//#else
	//freopen("symposium.in","r",stdin);
   // freopen("symposium.out","w",stdout);
//#endif
	int t;
	scanf("%d",&t);
	set<PII> m;
	m.insert(mp(-7,-1));
	m.insert(mp(-5,-1));
	m.insert(mp(-3,-1));
	m.insert(mp(-1,-1));
	m.insert(mp(1,-1));
	m.insert(mp(3,-1));
	m.insert(mp(5,-1));
	m.insert(mp(7,-1));
	m.insert(mp(0,0));
	FOR(tt,t) {
		printf("Case #%d: ",tt+1);
		scanf("%d%d%d",&n,&x,&y);
		if (x==0 && y==0) {
			printf("1.000000000\n");
			continue;
		}
		if (n==1) {
			printf("0.000000000\n");
			continue;
		}
		--n;
		VI a;
		all = 0;
		kol = 0;
		ans.clear();
		go(m);
		double res = (double)kol/all;
		printf("%.9lf\n",res);
	}
#ifdef _DEBUG
    fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
    return 0;
}

