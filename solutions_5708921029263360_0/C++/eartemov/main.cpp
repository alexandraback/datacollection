//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "C-small-attempt0"
#pragma comment(linker, "/STACK:536870912")
#include <cstdio>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>

const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 100010;
const long double EPS = 1e-8;
const int HASH_POW = 29;
const long double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

int k1, k2, k3, k;
vector <int> cur, ans;
int cnt1[4][4], cnt2[4][4], cnt3[4][4];

void perebor(int id)
{
	if (id == k1*k2*k3)
	{
		if (cur.size() > ans.size())
			ans = cur;
		return;
	}
	if (cur.size() + k1*k2*k3 - id <= ans.size())
		return;
	perebor(id + 1);
	int x = id / (k2*k3), y = (id / k3) % k2, z = id % k3;
	if (cnt1[x][y] < k && cnt2[x][z] < k && cnt3[y][z] < k)
	{
		++cnt1[x][y];
		++cnt2[x][z];
		++cnt3[y][z];
		cur.push_back(id);
		perebor(id + 1);
		cur.pop_back();
		--cnt1[x][y];
		--cnt2[x][z];
		--cnt3[y][z];
	}
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	mt19937 mt_rand(time(0));
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
#endif

	int CASE;
	scanf("%d", &CASE);
	for (int it = 1; it <= CASE; ++it)
	{
		scanf("%d %d %d %d", &k1, &k2, &k3, &k);
		perebor(0);
		printf("Case #%d: %d\n", it, ans.size());
		for (int i = 0; i < ans.size(); ++i)
		{
			int x = ans[i] / (k2*k3), y = (ans[i] / k3) % k2, z = ans[i] % k3;
			printf("%d %d %d\n", x + 1, y + 1, z + 1);
		}
		ans.clear();
	}

	my_return(0);
}