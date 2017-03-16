#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <bitset>

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define bitcnt(x) __builtin_popcountll(x)
#define rt return

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

const int INF = (int)1e9 + 37;
const ld PI = acos(-1.0);
const int MAXN = (int)5e4 + 222;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};

string toStr(int val){
	string ret;
	while (val){
		ret.pb(char(val % 10 + '0'));
		val /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool fitsMask(int Val, string mask){
	string val = toStr(Val);
	while ((int)val.length() != (int)mask.length()){
		val = '0' + val;
	}
	
	for (int i=0;i<(int)mask.length();i++){
		if (mask[i] != '?' && mask[i] != val[i]){
			return 0;
		}
	}
	
	return 1;
}

string solve(){
	string s1, s2;
	cin >> s1 >> s2;
	int sz = s1.length(), limit = (int)pow(10, sz);
	int ans1 = -1, ans2 = -1;
	for (int i=0;i<limit;i++){
		for (int j=0;j<limit;j++){
			if (fitsMask(i, s1) && fitsMask(j, s2)){
				if (ans1 == -1){
					ans1 = i, ans2 = j;
				} else {
					if (abs(i - j) < abs(ans1 - ans2)){
						ans1 = i, ans2 = j;
					} else if ((abs(i - j) == abs(ans1 - ans2)) and (i < ans1)){
						ans1 = i, ans2 = j;
					} else if ((abs(i - j) == abs(ans1 - ans2)) and (i == ans1) and (j < ans2)){
						ans1 = i, ans2 = j;
					}
				}
			}
		}
	}
	string Ans1 = toStr(ans1), Ans2 = toStr(ans2);
	while ((int)Ans1.length() != (int)s1.length()){
		Ans1 = '0' + Ans1;
	}
	while ((int)Ans2.length() != (int)s2.length()){
		Ans2 = '0' + Ans2;
	}
	return Ans1 + ' ' + Ans2;
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	int T;
	cin >> T;
	for (int Test=1;Test<=T;Test++){
		
			
		printf("Case #%d: ", Test);
		cout << solve() << endl;		
	}
				
    rt 0;
}
