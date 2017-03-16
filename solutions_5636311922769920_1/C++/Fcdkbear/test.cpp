#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define MEMS(a,b) memset((a),(b),sizeof(a))
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define LL long long
#define U unsigned

string gen(string wh, int c) {
	string res = wh;
	string gs = "";
	FOR(i,0,wh.size())
		gs += 'G';
	FOR(i,1,c) {
		string nres = "";
		FOR(j,0,res.size()) {
			if (res[j] == 'L')
				nres += wh;
			else
				nres += gs;
		}
		res = nres;
	}
	return res;
}

string genWh(int n, int p)
{
	string res  = "";
	FOR(i,0,n)
		if (i == p)
			res += 'G';
		else
			res += 'L';
	return res;
}
vector<string> all;

LL gen(int from, int to, int k, int c) {
	LL p = 1;
	FOR(i,0,c-1)
		p*=k;
	LL start = p*from;
	if (from == to) {
		return start;
	}
	return start + gen(from + 1, to, k, c - 1);
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int tests;
	scanf("%d",&tests);
	FOR(testNumber,1,tests+1) {
		int k,c,s;
		cin>>k>>c>>s;
		int need = (k+c-1)/c;
		printf("Case #%d:",testNumber);
		if (need>s) {
			printf(" IMPOSSIBLE\n");
		} else {
			int from = 0;
			int to = min(k - 1, c - 1);
			while (from < k) {
				LL val = gen(from, to, k, c);
				cout<<" "<<val+1;
				from = to+1;
				to = min(k - 1, from+c - 1);
			}
			cout<<endl;
		}
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}
