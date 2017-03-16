#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<set>
#include<algorithm>
#include<stack>
#include<list>

//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define ll long long
#define eps 1e-8
#define PI 2*cos(0.0)
#define MOD 1000000007

#define MAXN 2005

map<char, int>m;
int ans[10];
string a;
int main()
{
	freopen("A-small-attempt4.in", "r", stdin);
	freopen("Aout.txt", "w", stdout);

	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		m.clear();
		mem(ans, 0);

		cin >> a;
		for (int i = 0; i < a.length(); i++)
		{
			m[a[i]]++;
		}

		m['E'] -= m['Z'];
		m['R'] -= m['Z'];
		m['O'] -= m['Z'];
		ans[0] = m['Z'];
		m['Z'] = 0;

		m['T'] -= m['W'];
		m['O'] -= m['W'];
		ans[2] = m['W'];
		m['W'] = 0;

		m['F'] -= m['U'];
		m['O'] -= m['U'];
		m['R'] -= m['U'];
		ans[4] = m['U'];
		m['U'] = 0;

		m['V'] -= m['F'];
		m['I'] -= m['F'];
		m['E'] -= m['F'];
		ans[5] = m['F'];
		m['F'] = 0;

		m['S'] -= m['X'];
		m['I'] -= m['X'];
		ans[6] = m['X'];
		m['X'] = 0;

		m['E'] -= m['G'];
		m['I'] -= m['G'];
		m['H'] -= m['G'];
		m['T'] -= m['G'];
		ans[8] = m['G'];
		m['G'] = 0;

		ans[3] = m['H'];
		ans[7] = m['S'];
		ans[9] = m['I'];
		ans[1] = m['O'];

		printf("Case #%d: ", kase);

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < ans[i]; j++)
			{
				printf("%d", i);
			}
		}
		printf("\n");

	}
}
