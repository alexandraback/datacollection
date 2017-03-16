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


string num[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
int seq[10] = { 0, 4, 8, 5, 6, 7, 2, 1, 3, 9 };
char val[10] = { 'Z', 'U', 'G', 'F', 'X', 'V', 'W', 'O', 'R', 'I' };
int lett[1000];
vector<int> ans;

void func(){

	for (int k = 0; k <= 9; k++){
		char v = val[k];
		int rnt = seq[k];

		int mn = lett[v];

		for (int j = 0; j < mn; j++){
			ans.push_back(rnt);
		}
		for (int j = 0; j < num[rnt].size(); j++){
			lett[num[rnt][j]] -= mn;
		}

	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T; cin >> T;

	for (int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";

		string str;

		cin >> str;

		memset(lett, 0, sizeof(lett));
		ans.clear();
		for (int i = 0; i < str.size(); i++){
			lett[str[i]]++;
		}

		func();
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i];
		}

		cout << endl;
	}


	return 0;
}


