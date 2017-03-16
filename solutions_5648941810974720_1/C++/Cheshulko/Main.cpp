# define _CRT_SECURE_NO_WARNINGS
# include <unordered_map>
# include <functional>
# include <algorithm>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <vector>
# include <string>
# include <bitset>
# include <cmath>
# include <queue>
# include <stack>
# include <ctime>
# include <set>
# include <map>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

# define Work_It_Harder_Make_It_Better_Do_It_Faster_Makes_Us_Stronger 	ios::sync_with_stdio(0); cin.tie(0);
# define  rep(x, a, b) for(int (x) = (a); (x) <  int(b); ++(x))
# define repd(x, a, b) for(int (x) = (a); (x) >= int(b); --(x))
# define WaitMyDear cin.sync(); cin.get();
# define endl "\n"
# define INF 0x3F3F3F3F
# define y1 qwerty 
# define EPS 1e-10

//# define INT_MAX 2147483647   
//# define INT_MIN (-2147483647 - 1)    
# define LL_MAX  9223372036854775807i64        
# define LL_MIN  (-9223372036854775807i64 - 1)
# define PI 3.14159265358979323846

using namespace std;
typedef long long                  ll;
typedef pair<long long, long long> pll;
typedef pair<int, int>             pii;
typedef pair<double, int>          pdi;
typedef pair<double, double>       pdd;
typedef pair<string, string>       pss;
typedef unsigned long long         ull;

int T;
string s;
int cnt[300];
int num[10];


int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	Work_It_Harder_Make_It_Better_Do_It_Faster_Makes_Us_Stronger;

	cin >> T;
	rep(_t, 0, T){
		cin >> s;
		memset(cnt, 0, sizeof cnt);
		memset(num, 0, sizeof num);
		rep(i, 0, s.length()){
			cnt[s[i] - 'A']++;
		}
		while (cnt['Z' - 'A']){
			num[0]++;
			cnt['Z' - 'A']--; cnt['E' - 'A']--; cnt['R' - 'A']--; cnt['O' - 'A']--;
		}
		while (cnt['U' - 'A']){
			num[4]++;
			cnt['F' - 'A']--; cnt['O' - 'A']--; cnt['U' - 'A']--; cnt['R' - 'A']--;
		}
		while (cnt['G' - 'A']){
			num[8]++;
			cnt['E' - 'A']--; cnt['I' - 'A']--; cnt['G' - 'A']--; cnt['H' - 'A']--; cnt['T' - 'A']--;
		}
		while (cnt['X' - 'A']){
			num[6]++;
			cnt['S' - 'A']--; cnt['I' - 'A']--; cnt['X' - 'A']--;
		}
		while (cnt['W' - 'A']){
			num[2]++;
			cnt['T' - 'A']--; cnt['W' - 'A']--; cnt['O' - 'A']--;
		}
		while (cnt['H' - 'A']){
			num[3]++;
			cnt['T' - 'A']--; cnt['H' - 'A']--; cnt['R' - 'A']--;  cnt['E' - 'A']-=2;
		}
		while (cnt['F' - 'A']){
			num[5]++;
			cnt['F' - 'A']--; cnt['I' - 'A']--; cnt['V' - 'A']--; cnt['E' - 'A']--;
		}
		while (cnt['O' - 'A']){
			num[1]++;
			cnt['O' - 'A']--; cnt['N' - 'A']--; cnt['E' - 'A']--;
		}
		while (cnt['V' - 'A']){
			num[7]++;
			cnt['S' - 'A']--; cnt['E' - 'A'] -= 2; cnt['V' - 'A']--; cnt['N' - 'A']--;
		}
		while (cnt['I' - 'A']){
			num[9]++;
			cnt['N' - 'A']-=2; cnt['I' - 'A'] --; cnt['E' - 'A']--;
		}
		printf("Case #%d: ", _t + 1);
		rep(i, 0, 10){
			rep(j, 0, num[i]) printf("%d", i);
		}
		puts("");
	}

	
	//WaitMyDear WaitMyDear
	return 0;
}