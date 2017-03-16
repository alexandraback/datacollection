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

int DIF(string a, string b) {
	int aa = 0 , bb = 0 , t = 1 ;
	for (int i = a.size() - 1 ; i >= 0 ; i--) {
		aa += (int)(a[i] - '0') * t ;
		t *= 10;
	}
	t = 1;
	for (int i = b.size() - 1; i >= 0; i--) {
		bb += (int)(b[i] - '0') * t ;
		t *= 10;
	}
	return abs(aa - bb);
}

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
		string C, J;
		cin >> C >> J ;
		vector < string > vc, vj , tot ;
		for (int i = '0'; i <= '9'; i++) {
			for (int j = '0'; j <= '9'; j++) {
				for (int t = '0'; t <= '9'; t++) {
					string tmp;
					tmp.push_back(char(i));
					tmp.push_back(char(j));
					tmp.push_back(char(t));
					//cout << tmp << endl;
					tot.push_back(tmp);
				}
			}
		}
		for (int i = '0'; i <= '9'; i++) {
			for (int j = '0'; j <= '9'; j++) {
					string tmp;
					tmp.push_back(char(i));
					tmp.push_back(char(j));
					//cout << tmp << endl;
					tot.push_back(tmp);
			}
		}
		for (int i = '0'; i <= '9'; i++) {
				string tmp;
				tmp.push_back(char(i));
				tot.push_back(tmp);
		}
		Rep(i, tot.size()) {
			if (tot[i].size() == C.size()) {
				bool flag = 1;
				Rep(j, C.size()) {
					if ( ( C[j] != '?' && tot[i][j] == C[j]) || C[j] == '?' ) continue;
					flag = 0;
					break;
				}
				if (flag) vc.push_back(tot[i]);
				flag = 1;
				Rep(j, J.size()) {
					if ( (J[j] != '?' && tot[i][j] == J[j]) || J[j] == '?' ) continue;
					flag = 0;
					break;
				}
				if (flag) vj.push_back(tot[i]);
			}
		}
		vector < pair < int, pair < string, string > > > res;
		Rep(i, vc.size()) {
			if (i == 9) {
				cout << "";
			}
			Rep(j, vj.size()) {
				int dif = DIF(vc[i], vj[j]);
				res.push_back({ dif ,{vc[i],vj[j]} });
			}
		}
		Sort(res);
		cout << res[0].second.first << ' ' << res[0].second.second << endl;
	}
	return 0;
}