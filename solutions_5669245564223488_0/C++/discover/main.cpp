#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 100100;

ll gcd(ll a, ll b)
{
	return b? gcd(b, a%b): a;
}

int n;
string a[20];
int id[20];

int pos[50];

bool ok()
{
	string s = "";
	for (int i = 0; i < n; ++i) s += a[id[i]];
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < s.size(); ++i){
		int tmp = s[i] - 'a';
		if(pos[tmp] != -1 && pos[tmp] + 1 != i) return false;
		pos[tmp] = i;
	}
	return true;
}

void get_ans()
{
	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		cin >> a[i];
		id[i] = i;
	}

	int res = 0;
	do {
		if(ok()) ++res;
	} while(next_permutation(id, id + n));
	cout << res << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	int cas, tcas = 0;
	for (cin >> cas; cas; --cas)
	{
		cout << "Case #" << (++tcas) << ": ";
		get_ans();
	}
}
