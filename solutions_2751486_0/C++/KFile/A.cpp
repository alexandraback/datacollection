#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pi 2*acos(0.0)
#define eps 1e-9
#define PII pair<int,int> 
#define PDD pair<double,double>
#define LL long long
#define INF 1000000000

using namespace std;

char inp[111];
int len, T, L, ans;

bool isvowel(char x)
{
	return x == 'a' || x == 'e' || x == 'i' || x == 'u' || x == 'o';
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%s %d", inp, &L); len = strlen(inp);
		
		ans = 0;
		for(int a = 0; a < len; a++)
			for(int b = a; b < len; b++)
			{
				int x = a - 1, longest = 0;
				do
				{
					x++;
					if(isvowel(inp[x])) continue;
					
					int y = x, temp = 0;
					while(y <= b && !isvowel(inp[y])) y++, temp++;
					longest = max(longest, temp);
					x = y - 1;
				} while( x + 1 <= b);
				
				if(longest >= L) ans++;
			}
			
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

