#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> pii;

char str[1005];

void solve ()
{
	scanf("%s",str);
	
	string ans;
	int len = strlen(str);
	ans += str[0];
	for (int i = 1; i < len; ++i)
	{
		char c = str[i];
		
		if (ans[0] <= c)
		{
			ans = c + ans;
		}
		else
			ans += c;
	}	
	
	printf("%s\n",ans.c_str());
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ",t);
		solve();
	}
	
	return 0;
}
