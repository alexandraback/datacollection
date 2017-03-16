#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;
const int inf = int(1e9)+7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

set<long long> mp;
long long a[502], ff;
int n;

void dfs(int x, long long base) {
	if (x == n || ff) return;
	long long tmp = base+a[x];
	if (mp.count(tmp)) {
		ff = tmp;
		return;
	}
	mp.insert(tmp);
	dfs(x+1, tmp);
	dfs(x+1, base);
}

int cur;
int p[502];
int ans[2][502]; 

void dfs2(int x, long long base) {
	if (x == n || cur == 2) return;
	long long tmp = base+a[x];
	p[x] = 1;
	if (tmp == ff) {
		REP(i,x+1,n) p[i] = 0;
		memcpy(ans[cur], p, sizeof(p));
		cur++;
	}
	dfs2(x+1, tmp);

	p[x] = 0;
	dfs2(x+1, base);
}


int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int caseNum;
	scanf("%d", &caseNum);	
	
	REP(c, 1, caseNum+1) {
		mp.clear();
		ff = 0;
		cin>>n;
		FOR(i,n) cin>>a[i];
		dfs(0,0);
		cur = 0;
		ME(p);
		dfs2(0,0);
		FOR(i,n) {
			if (ans[0][i] == ans[1][i]) {
				ans[0][i] = 0;
				ans[1][i] = 0;
			}
		}
	//	printf("Case #%d:\n", c);
	//	cout<<ff<<endl;
		cout<<"Case #"<<c<<":"<<endl;
		FOR(i,n) if (ans[0][i]) cout<<a[i]<<" ";
		cout<<endl;
		FOR(i,n) if (ans[1][i]) cout<<a[i]<<" ";
		cout<<endl;
	}
//	while (1>0) {}
	
	return 0;
} 
