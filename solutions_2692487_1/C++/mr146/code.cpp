#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;


int a[1046];


void solve(int t)
{
	int n, s;
	scanf("%d%d", &s, &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int S = s;
	sort(a, a + n);

	int ans = n;
	if(S != 1)
	{
	for(int i = 0; i <= n; i++)
	{
		s = S;
		int cur = n - i;
		for(int j = 0; j < i; j++)
		{            
			while(s <= a[j])
			{
				s += s - 1;
				cur++;
			}
			s += a[j];
		}
		ans = min(ans, cur);
	}
	}
	printf("Case #%d: %d\n", t, ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i + 1);
}