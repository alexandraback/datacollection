
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int c, d, v;
set<int> S;
vector<int> V;

int f[100][100];

int F(int pos, int rem)
{	if(rem == 0) return 1;
	if(rem < 0) return 0;
	if(pos >= V.size()) return 0;
	
	if(f[pos][rem] != -1)
		return f[pos][rem];
	
	int A = F(pos + 1, rem);
	int B = 0;
	if(rem - V[pos] >= 0)
		B = F(pos + 1, rem - V[pos]);
		
	return f[pos][rem] = (A || B);
}

int check(int val)
{	
	V.clear();
	for(auto x: S) V.push_back(x);
	memset(f, -1, sizeof(f));
	return F(0, val);
}

int main(void)
{	
	int T, TT = 1;
	scanf("%d", &T);
	while(T--)
	{
		int ans = 0;
		scanf("%d %d %d", &c, &d, &v);
		
		S.clear();
		for(int i = 0; i < d; i++)
		{
			int x;
			scanf("%d", &x);
			S.insert(x);
		}
		
		for(int i = 1; i <= v; i++)
		{	if(check(i) == 0)
			{	ans++;
				S.insert(i);
			}
		}
		printf("Case #%d: %d\n", TT++, ans);
	}
	return 0;
}
