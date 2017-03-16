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
//#include <bits/stdc++.h>

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

int main(int argc, char *argv[]) {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, tc = 1;
	cin >> t;
	while (t--) {
		cout << "Case #" << tc++ << ": ";
		int n;
		cin >> n;
		string a, b;
		vector < pair < string, string > > vc;
		Rep(i, n) {
			cin >> a >> b;
			vc.push_back({ a,b });
		}
		int maxi = 0;
		Rep(i, (1 << n)) {
			vector < pair < string, string > > fake , org ;
			Rep(j, vc.size()) {
				if (i & (1 << j)) {
					fake.push_back(vc[j]);
				}
				else org.push_back(vc[j]);
			}
			Sort(fake), Sort(org);
			bool flag = 1;
			For(j , 1 , fake.size()) {
				if (fake[j] == fake[j - 1]) {
					flag = 0;
					break;
				}
			}
			For(j, 1, org.size()) {
				if (org[j] == org[j - 1]) {
					flag = 0;
					break;
				}
			}
			if (!flag) continue;
			
			int cnt = 0;
			Rep(j, fake.size()) {
				flag = 0;
				Rep(t, org.size()) {
					if (fake[j].first == org[t].first) {
						Rep(tt, org.size()) {
							if (tt == t) continue;
							if (fake[j].second == org[tt].second) {
								flag = 1;
								break;
							}
						}
					}
					if (flag) break;
				}
				if (flag) cnt++;
				else break;
			}
			if (cnt == fake.size()) maxi = max(maxi, cnt);
		}
		cout << maxi << endl;
	}
	return 0;
}