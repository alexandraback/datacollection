#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <hash_map>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <float.h>
#include <time.h>
#include <queue>
#include <cstdint>
#define PI 3.14159265358979323846
#define ull unsigned long long int
#define ll long long int
#define EPS 1e-12
#define pb push_back
#define EOS(c) (c != EOF && c != '\0' && c != '\n' && c != ' ')
#define oo 1000000005
#define ALL(v) v.begin(), v.end()
#define mp make_pair
#define sqr(a) (a) * (a)

using namespace std;

#define FILE "sort"
//#define OUT "put.txt"

template<class telem>telem MAX(telem a, telem b)
{
	return (a > b) ? a : b;
}

template<class telem>telem MIN(telem a, telem b)
{
	return (a < b) ? a : b;
}

template<class telem>telem GCD(telem a, telem b)
{
	return b ? GCD(b, a % b) : a;
}

template<class telem>telem LCM(telem a, telem b)
{
	return a / GCD(a, b) * b;
}

template<class telem>telem UNSIGNED(telem a)
{
	return (a > 0) ? a : a * (-1);
}

template<class telem>void bez_swop(telem &a, telem &b)
{
	telem c = a;
	a = b;
	b = c;
}

void swop(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int T;
int n, m;
string v[11];
map<string, int> q;
priority_queue<string, vector<string>, greater<string> > qq;
vector<string> mas[11];
string tmp, ans;
int ttt[11][11];
char trt[11][11];
char was[11];

char pt[11];

vector<int> can;


void dfs(int t, priority_queue<string, vector<string>, greater<string> >  qq1, string path, int co)
{
	char re[11];

	memset(re, 0, sizeof(re));

	for(int i = 0; i < mas[t].size(); i++)
	{
		int y = q[mas[t][i]];

		
			if(ttt[t][y] == 2)
			{
				if(!trt[t][y])
					continue;
			}

		if(!was[y])
		{
			qq1.push(mas[t][i]);


			was[y] = 1;
			re[y] = 1;
		}
	}

	path += v[t];

	if(co == n)
	{
		tmp = min(tmp, path);
		return;
	}

	while(!qq1.empty())
	{
		string qw = qq1.top();
		qq1.pop();

		int tt = q[qw];

		trt[t][tt] = 1;
				
		dfs(tt, qq1, path, co + 1);

		trt[t][tt] = 0;	
	}

	for(int i = 1; i <= n; i++)
	{
		if(re[i])
			was[i] = 0;
	}

	return;
}

string mx;

int main()
{

#ifndef ONLINE_JUDGE
#ifdef OUT
	freopen("in"OUT, "r", stdin);
	freopen("out"OUT, "w", stdout); 
#endif

#ifdef FILE
 	freopen(FILE".in", "r", stdin);
	freopen(FILE".out", "w", stdout); 
#endif
#endif

	ios_base::sync_with_stdio(false);
	srand(time(NULL));
	time_t start = clock();

	scanf("%d", &T);

	

	mx.resize(20000, 'z');
	v[10] = mx;

	for(int test = 1; test <= T; test++)
	{
		printf("Case #%d: ", test);

		scanf("%d %d", &n, &m);

		q.clear();

		for(int i = 1; i <= n; i++)
		{
			cin >> v[i];
			q[v[i]] = i;
		}

		for(int i = 1; i <= n; i++)
		{
			mas[i].clear();
		}

		for(int i = 0; i < m; i++)
		{
			int a, b;

			scanf("%d %d", &a, &b);

			ttt[a][b] = 1;
			ttt[b][a] = 2;

			mas[a].push_back(v[b]);
			mas[b].push_back(v[a]);
		}

		ans = mx;

		for(int i = 1; i <= n; i++)
		{
			pt[i] = i;
		}

		do
		{

			tmp = "";
			for(int i = 1; i <= n; i++)
			{
				tmp += v[i];
			}

			bool check = false;

			for(int i = 2; i <= n && !check; i++)
			{
				if(!ttt[pt[i - 1]][pt[i]])
				{
					check = true;
				
				}

				if(ttt[pt[i - 1]][pt[i]] == 2)
				{
					if(!trt[pt[i]][pt[i - 1]])
						check = true;
				}

				trt[pt[i - 1]][pt[i]] = 1;
			}

			if(check)
				continue;

			ans = min(ans, tmp);

		}while(next_permutation(pt + 1, pt + n + 1));


		cout << ans << '\n';
	}
	
#ifndef ONLINE_JUDGE
	fprintf(stderr, "\n%0.3lf\n", (clock() - start) * 1.0 / CLOCKS_PER_SEC);
#endif

	return 0;
}