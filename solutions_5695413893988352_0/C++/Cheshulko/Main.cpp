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
string s1, s2;
int cnt[300];
int num[10];


int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	Work_It_Harder_Make_It_Better_Do_It_Faster_Makes_Us_Stronger;

	int what = 0;

	cin >> T;
	rep(_t, 0, T){
		cin >> s1 >> s2;
		what = 0;
		rep(i, 0, s1.length()){
			if (s1[i] == '?'){
				if (s2[i] == '?'){
					if (what == 1) s1[i] = '0', s2[i] = '9';
					else if (what == 2) s1[i] = '9', s2[i] = '0';
					else s1[i] = s2[i] = '0';
				}
				else{
					if (what == 1) s1[i] = '0';
					else if (what == 2) s1[i] = '9';
					else s1[i] = s2[i];
				}
			}
			else{
				if (s2[i] == '?'){
					if (what == 1) s2[i] = '9';
					else if (what == 2) s2[i] = '0';
					else s2[i] = s1[i];
				}
				else{
					if (what == 0){
						if (s1[i] > s2[i]) what = 1;
						else if (s1[i] < s2[i]) what = 2;
					}
				}
			}
		}	
		printf("Case #%d: ", _t + 1);
		cout << s1 << " " << s2 << endl;
	}

	
	//WaitMyDear WaitMyDear
	return 0;
}