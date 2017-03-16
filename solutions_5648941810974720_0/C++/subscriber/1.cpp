#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

string e[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string uni = "ZOWHUFXVGE";

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		string ans = "";
		string s;
		cin >> s;
		map<char, int> cnt;

		for (int i = 0; i < s.size(); i++) cnt[s[i]]++;

		for (int i = 0; i < 10; i++) while (i != 1 && i != 9 && i != 3 && cnt[uni[i]] > 0) {
			ans.pb('0' + i);
			for (int j = 0; j < e[i].size(); j++) cnt[e[i][j]]--;
		}
		for (int i = 0; i < 10; i++) while (i != 1 && i != 9 && cnt[uni[i]] > 0) {
			ans.pb('0' + i);
			for (int j = 0; j < e[i].size(); j++) cnt[e[i][j]]--;
		}
		for (int i = 0; i < 10; i++) while (cnt[uni[i]] > 0) {
			ans.pb('0' + i);
			for (int j = 0; j < e[i].size(); j++) cnt[e[i][j]]--;
		}
		sort(ans.begin(), ans.end());

		cout << "Case #" << tt << ": ";
		cout << ans << endl;

	}
	return 0;
}