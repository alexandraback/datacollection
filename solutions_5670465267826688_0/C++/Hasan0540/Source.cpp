#pragma comment(linker, "/STACK:36777216")

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll k;
char s[10001];
char res[2][4] = { "NO", "YES" };
string mul(char a, char b){
	if (a == '1' && a == b)
		return "1";
	if (a == b)
		return "-1";
	if (a == '1')
		return string(1, b);
	if (b == '1')
		return string(1, a);
	if (a == 'i' && b == 'j')
		return "k";
	if (a == 'i' && b == 'k')
		return "-j";
	if (a == 'j' && b == 'k')
		return "i";
	swap(a, b);
	if (a == 'i' && b == 'j')
		return "-k";
	if (a == 'i' && b == 'k')
		return "j";
	if (a == 'j' && b == 'k')
		return "-i";
	cout << a << " " << b << endl;
	puts("???");
	exit(0);
}
string fix(string s){
	if (s[0] == '-' && s[1] == '-' && s.size() == 2){
		puts("?!@>$5^$&^$#%$^$%");
		exit(0);
	}
	if (s[0] == '-' && s[1] == '-')
		return s.substr(2);
	return s;
}
string mul(string a, string b){
	if (a[0] == '-' && b[0] == '-')
		return mul(a[1], b[1]);
	if (a[0] == '-')
		return fix("-" + mul(a[1], b[0]));
	if (b[0] == '-')
		return fix("-" + mul(a[0], b[1]));
	return mul(a[0], b[0]);
}
string str;
vector<string> STR;
map<string, int> mp;
vector<bool> vis[3][8];
string state = "ijk";
bool calc(int i, char s,string z){
	if (i == STR.size())
		return s == 2 && z == "k";
	if (vis[s][mp[z]][i])
		return false;
	vis[s][mp[z]][i] = true;
	if (calc(i + 1, s, mul(z, STR[i])))
		return true;
	if (s != 2 && state[s] == z[0] && calc(i + 1, s + 1, STR[i]))
		return true;
	return false;
}
bool solve(){
	str = "";
	STR.clear();
	if (k <= 6){
		for (int i = 0; i < k; ++i)
			str += s;
		for (int i = 0; i < str.size(); ++i)
			STR.push_back(string(1, str[i]));
	}
	else{
		k -= 6;
		for (int i = 0; i < 3; ++i)
			str += s;
		string cur = "";
		cur += s[0];
		for (int i = 1; i < n; ++i)
			cur = mul(cur, string(1, s[i]));
		--k;
		k %= 4;
		if (k == 1)
			cur = mul(cur, cur);
		else if (k == 2)
			cur = mul(cur, mul(cur, cur));
		else if (k == 3)
			cur = mul(cur, mul(cur, mul(cur, cur)));
		for (int i = 0; i < str.size(); ++i)
			STR.push_back(string(1, str[i]));
		STR.push_back(cur);
		for (int i = 0; i < str.size(); ++i)
			STR.push_back(string(1, str[i]));
	}
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 8;++j){
		vis[i][j].clear();
		vis[i][j].resize(STR.size());
	}
	return calc(1, 0, STR[0]);
}
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string val = "1ijk";
	for (int i = 0; i < val.size();++i)
	for (int j = 0; j < val.size(); ++j){
		string ret = mul(val[i], val[j]);
		if (mp.find(ret) == mp.end()){
			int idx = ret.size();
			mp[ret] = idx;
		}
	}
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; ++T){
		printf("Case #%d: ", T);
		scanf("%d%lld%s", &n, &k, &s);
		puts(res[solve()]);
	}
	return 0;
}