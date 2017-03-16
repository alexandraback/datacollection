#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#pragma comment(linker, "/STACK:128000000")
 
typedef pair<int, int> pii;
typedef long long int64;
typedef pair<int64, int64> pii64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<int,pii> piii;
typedef pair<int64,pii> piii64;
typedef pair<pii,pii> piiii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
 
#define y1 dsjfksdj_fks
#define y2 alksaad_sa
#define y0 _sdkfsjfs__
 
#define tm _dskfjskdfjksdf

string dig[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

inline int get_id(char c)
{
	return static_cast<int>(c - 'A');
}

int n;
int nt;
string s;
int cnt[26];
int ans[10];

inline void add(int id, int val)
{
	ans[id] += val;
	int l = static_cast<int>(dig[id].length());
	for (int i = 0; i < l; ++i)
	{
		int cid = get_id(dig[id][i]);
		cnt[cid] -= val;
	}
}

inline string solve(string &s)
{
	memset(ans, 0, sizeof ans);
	memset(cnt, 0, sizeof cnt);
	n = static_cast<int>(s.length());
	for (int i = 0; i < n; ++i)
		++cnt[get_id(s[i])];
	string res = "";
	add(0, cnt[get_id('Z')]);
	add(2, cnt[get_id('W')]);
	add(6, cnt[get_id('X')]);
	add(7, cnt[get_id('S')]);
	add(5, cnt[get_id('V')]);
	add(4, cnt[get_id('F')]);
	add(3, cnt[get_id('R')]);
	add(8, cnt[get_id('T')]);
	add(9, cnt[get_id('I')]);
	add(1, cnt[get_id('O')]);
	for (int id = 0; id < 10; ++id)
		for (int j = 0; j < ans[id]; ++j)
			res += static_cast<char>(id + '0');
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		cin >> s;
		string res = solve(s);
		printf("Case #%d: ", tn);
		cout << res << endl;
	}

    return 0;
}  