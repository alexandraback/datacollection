#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;

int T,cas;
char c;
string s1,s2,s,ans;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	for (scanf("%d",&T);T;T --)
	{
		printf("Case #%d: ",++cas);
		ans = "";
		cin >> s;
		for (int i = 0;i < s.size();i ++)
		{
			s1 = s[i] + ans;
			s2 = ans + s[i];
			if (s1 > s2) ans = s1;
			else ans = s2;
		}
		cout << ans << endl;
	}
	return 0;
}
