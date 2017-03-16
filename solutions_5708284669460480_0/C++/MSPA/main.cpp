#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;

const int N = 1e5+3;
const int inf = 1e9;

using namespace std;

int ans;
int k,l,s;
char key[N], pat[N], str[N];
vector <int> v;
int mx;
void rec(int t)
{
	if (t == s) {
		int c = 0;
		for (int i = 0; i + l <= s; ++i) {
			bool f = 1;
			for (int j=0;j<l;++j)
				if (str[i+j] != pat[j]) {
					f=0;
					break;
				}
			c += f;
		}
		v.push_back(c);
		mx = max(mx, c);
		return ;
	}
	for (int i = 0; i < k; ++i) {
		str[t] = key[i];
		rec(t+1);
	}
}

bool solve(int test)
{
	scanf("%d%d%d",&k,&l,&s);
	scanf("%s%s",key, pat);
	v.clear();
	mx = 0;
	ans = 0;
	rec(0);
	for (int i =0; i < v.size(); ++i)
		ans += v[i];
	printf("Case #%d: %.9lf\n", test, mx - 1.0 * ans / v.size());
	return false;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
		solve(i+1);
	return 0;
}