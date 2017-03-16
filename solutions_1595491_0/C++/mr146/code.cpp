#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;


bool dp[146][146][146];
bool cool[146], surp[146], surpcool[146], nope[146];
int ar[146];


void solve(int test)
{
	memset(dp, false, sizeof(dp));
	memset(cool, false, sizeof(cool));
	memset(surp, false, sizeof(surp));
	memset(surpcool, false, sizeof(surpcool));
	memset(nope, false, sizeof(nope));
	int n, s, p;
	scanf("%d%d%d", &n, &s, &p);
	for(int i = 0; i < n; i++)
		scanf("%d", &ar[i]);
	for(int a = 0; a <= 10; a++)
		for(int b = a; b <= 10; b++)
			for(int c = b; c <= 10; c++)
			{
				if(c > a + 2)
					continue;
				if(c == a + 2 && c < p)
					surp[a + b + c] = true;
				if(c >= p && c != a + 2)
					cool[a + b + c] = true;
				if(c == a + 2 && c >= p)
					surpcool[a + b + c] = true;
				if(c != a + 2 && c < p)
					nope[a + b + c] = true;
			}
	 dp[0][0][0] = true;
	 for(int i = 0; i < n; i++)
	 	for(int j = 0; j <= s; j++)
	 		for(int k = 0; k < n; k++)
	 			if(dp[i][j][k])
	 			{
//	 				printf("(%d %d %d)\n", i, j, k);
	 				if(surp[ar[i]])
	 					dp[i + 1][j + 1][k] = true;
	 				if(cool[ar[i]])
	 					dp[i + 1][j][k + 1] = true;
	 				if(surpcool[ar[i]])
	 					dp[i + 1][j + 1][k + 1] = true;
	 				if(nope[ar[i]])
	 					dp[i + 1][j][k] = true;
	 			}	 		
	 int ans = -1;
	 for(int i = 0; i <= n; i++)
	 	if(dp[n][s][i])
	 		ans = i;
	 printf("Case #%d: %d\n", test + 1, ans);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
		solve(i);
}