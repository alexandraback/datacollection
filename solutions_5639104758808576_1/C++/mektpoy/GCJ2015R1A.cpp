#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
char s[1010];
int T, n;
int main()
{
  //freopen("text.in","r",stdin);
  //freopen("text.out","w",stdout);
  cin >> T;
 	for (int t=1; t<=T; t++)
  	{
			scanf ("%d\n", &n);
			scanf ("%s", s);
			int k = 0, ans = 0;
			for (int i=0; i<=n; i++)
				if (k >= i) k += s[i]-'0'; else ans++, k += s[i]-'0'+1;
			printf ("Case #%d: %d\n", t, ans);
		}
	return 0;
}

