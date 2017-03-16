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

map < char, int > mp;
string num[10] = {"ZERO" , "ONE" , "TWO" , "THREE" , "FOUR" , "FIVE" , "SIX" , "SEVEN" , "EIGHT" , "NINE" };

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
		string n , res ;
		mp.clear();
		cin >> n;
		Rep(i, n.size()) mp[n[i]]++;
		///0
		while (mp['Z'] != 0) {
			Rep(i, num[0].size()) mp[num[0][i]]--;
			res.push_back('0');
		}
		///6
		while (mp['X'] != 0) {
			Rep(i, num[6].size()) mp[num[6][i]]--;
			res.push_back('6');
		}
		///8
		while (mp['G'] != 0) {
			Rep(i, num[8].size()) mp[num[8][i]]--;
			res.push_back('8');
		}
		///2
		while (mp['W'] != 0) {
			Rep(i, num[2].size()) mp[num[2][i]]--;
			res.push_back('2');
		}
		///4
		while (mp['U'] != 0) {
			Rep(i, num[4].size()) mp[num[4][i]]--;
			res.push_back('4');
		}
		///after all 4 now 5
		while (mp['F'] != 0) {
			Rep(i, num[5].size()) mp[num[5][i]]--;
			res.push_back('5');
		}
		///after 4 and 5 now 7
		while (mp['V'] != 0) {
			Rep(i, num[7].size()) mp[num[7][i]]--;
			res.push_back('7');
		}
		///after 2 and 8 now 3
		while (mp['T'] != 0) {
			Rep(i, num[3].size()) mp[num[3][i]]--;
			res.push_back('3');
		}
		///1
		while (mp['O'] != 0) {
			Rep(i, num[1].size()) mp[num[1][i]]--;
			res.push_back('1');
		}
		///else 9
		while (mp['N'] != 0) {
			Rep(i, num[9].size()) mp[num[9][i]]--;
			res.push_back('9');
		}
		Sort(res);
		cout << res << endl;
	}
	return 0;
}