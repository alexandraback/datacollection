#include <vector>
#include <list>
#include <map>
#include <set>
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

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

int n, arr[100];
string s[10] = {"ZERO", "TWO", "EIGHT", "SIX", "FOUR", "THREE", "FIVE", "ONE", "NINE", "SEVEN"};
string q[10] = {"0", "2", "8", "6", "4", "3", "5", "1", "9", "7"};
string ss;
//0, 2, 8, 6, 4, 3, 5, 1, 9, 7

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){
		cout << "Case #" << casee << ": " ;
		cin >> ss;
		for(int i = 0;i < 100;i++) arr[i] = 0;
		for(int i = 0;i < ss.size();i++){
			arr[ss[i] - 'A']++;
		}
		//for(int i = 0;i < 26;i++) cout << arr[i] << " ";cout << endl;
		string ans = "";
		for(int i = 0;i < 10;i++){
			string curr = s[i];
			//cout << curr << endl;
			int val = arr[curr[0] - 'A'];
			//cout << val << " " << curr[0] << endl;
			for(int j = 0;j < curr.size();j++){
				val = min(val, arr[curr[j] - 'A']);
			}
			//cout << val << endl;
			for(int j = 0;j < val;j++) ans += q[i];
			for(int j = 0;j < curr.size();j++){
				arr[curr[j] - 'A'] -= val;
			}
			//for(int i = 0;i < 26;i++) cout << arr[i] << " ";cout << endl;
		}
		//for(int i = 0;i < 26;i++) cout << arr[i] << " ";cout << endl;
		sort(ans.begin(), ans.end());
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

