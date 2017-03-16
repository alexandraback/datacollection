///////////////////////IN THE NAME OF GOD
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <utility>
#include <sstream>
#include <list>
#include <iomanip>
#include <functional>
#include <deque>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <climits>
#include <cctype>
#include <cassert>
#include <bitset>
#include <limits>
#include <numeric>

using namespace std;

#define     For(i,a,b)      for (int i=a; i<(int)b; i++)
#define     Rep(i,a)        for (int i=0; i<(int)a; i++)
#define     ALL(v)          (v).begin(),(v).end()
#define     Set(a,x)        memset((a),(x),sizeof(a))
#define     EXIST(a,b)      find(ALL(a),(b))!=(a).end()
#define     Sort(x)         sort(ALL(x))
#define     UNIQUE(v)       Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     SF              scanf
#define     PF              printf
#define     timestamp(x)    printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define     INF             1e9
#define     pii             pair < int , int >
#define     MP              make_pair
#define     MOD             1000000007
#define     EPS             1e-9
#define     ll              long long
#define     MAXN            100000+10
#define     Dbug            cout<<""
#define     PI                3.1415926535897932384626433
//int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

map < int, int > mp;

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int tc = 1;
	int t , n , tmp ;
	cin >> t;
	while (t--) {
		cout << "Case #" << tc++ << ": ";
		mp.clear();
		cin >> n;
		Rep(i, 2 * n - 1) {
			Rep(j, n) {
				cin >> tmp;
				mp[tmp]++;
			}
		}
		vector < int > res;
		for ( auto x : mp) {
			if (x.second % 2) {
				res.push_back(x.first);
			}
		}
		Sort(res);
		Rep(i, res.size()) {
			cout << res[i];
			if (i != res.size() - 1) cout << ' ';
		}
		cout << endl;
	}
	return 0;
}