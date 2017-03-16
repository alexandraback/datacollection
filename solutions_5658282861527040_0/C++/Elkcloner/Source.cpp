//IN THE NAME OF GOD
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

//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define INF 1000000000
#define pii pair < int , int >
#define MP make_pair
#define MOD 1000000007
#define EPS 1e-9
#define LL long long
#define MAXN 300000+10
#define bug cout<<"!!!!!!!!!!!!!!!!!";

int main()
{
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int tc , a , b , k , tcc = 1 ;
	cin >> tc;
	vector < int > ans;
	while (tc--){
		ans.clear();
		cin >> a >> b >> k;
		cout << "Case #" << tcc++ << ": ";
		for (int i = 0; i < a; i++){
			for (int j = 0; j < b; j++){
				ans.push_back(i & j);
			}
		}
		int cnt = 0;
		for (int i = 0; i < ans.size(); i++){
			if (ans[i] < k) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}