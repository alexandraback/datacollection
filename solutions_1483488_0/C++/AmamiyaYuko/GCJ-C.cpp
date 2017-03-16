#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <cstring>

//kAc
#define ALL(x) x.begin(), x.end()
#define foreach(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)a.size()
#define VEC vector
#define STR string
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }
using namespace std;
char buf[1001];
set<pair<int, int> > S;
int main()
{
freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
int TEST; scanf("%d", &TEST);
for (int testi = 1; testi <= TEST; testi++){
	S.clear();
	int ans = 0, a, b;
	scanf("%d%d", &a, &b);
	int l = 0, m = 1; while(m <= a) m *= 10, ++l;
	for (int i = a; i <= b; i++){
		sprintf(buf, "%d", i);
		sprintf(buf + l, "%d", i);
		for (int j = 1; j < l; j++){
			char rec = buf[j + l]; buf[j + l] = 0;
			int t = atoi(buf + j);
			if (t > i && t >= a && t <= b && !S.count(make_pair(i, t))){
				++ans;
				S.insert(make_pair(i, t));
			}
			buf[j + l] = rec;
		}
	}
	printf("Case #%d: %d\n", testi, ans);
}	
}
