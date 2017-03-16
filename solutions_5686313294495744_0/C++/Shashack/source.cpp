#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;

#define y1 mine
#define mp make_pair

double pi = acos(-1);
ll power(ll a, ll b){ ll p_res = 1; while (b > 0){ if (b % 2 == 1) { p_res *= a; b--;} a *= a; b /= 2;} return p_res;}

map<pair<string, string>, int > mm;
map<pair<string, string>, int >::iterator it;
int ans;
string str1, str2;
string arr[10000][2];

int main(){
	//freopen("input.txt", "r", stdin);
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; cin >> T;

	for (int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		
		int n; cin >> n;
		for (int i = 0; i < n; i++){
			cin >> str1 >> str2;
			mm[mp(str1, str2)] = i;
			arr[i][0] = str1;
			arr[i][1] = str2;
		}
		ans = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i == j){
					continue;
				}
				it = mm.find(mp(arr[i][0], arr[j][1]));
				if (it != mm.end() && arr[i][0] != arr[j][1] && it->second != i && it->second != j){
					ans++;
				}
			}
		}
		cout << ans;
		cout << endl;
	}


	return 0;
}


