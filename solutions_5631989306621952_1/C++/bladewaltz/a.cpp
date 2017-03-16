#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char ss[1111];
string ans;

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	getchar();
	int k = 0;
	while(T--)
	{
		scanf("%s",ss);
		int len = strlen(ss);
		ans = ss[0];
		string tmp;
		for(int i = 1; i < len; ++i)
		{
			if(ss[i] >= ans[0])
			{
				tmp = ans;
				ans = ss[i];
				ans += tmp;
			}
			else ans += ss[i];
		}
		printf("Case #%d: ", ++k);
		cout << ans << endl;
	}

	return 0;
}
