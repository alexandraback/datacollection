#include <bits/stdc++.h>
using namespace std;
#define maxn 1001

char s[maxn], ans[maxn];
list<char> ret;
list<char>::iterator it;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int t, tn = 1, n, i;
	scanf("%d\n", &t);
	while(t--)
	{
		scanf("%s", s);
		n = strlen(s);
		ret.push_back(s[0]);
		for(i = 1; i < n; i++)
			if(s[i] > ret.front()) ret.push_front(s[i]);
			else
				if(s[i] < ret.front()) ret.push_back(s[i]);
				else
				{
					it = ret.begin();
					for(++it; it != ret.end(); it++)
						if(*it != s[i]) break;
					if(it == ret.end()) ret.push_back(s[i]);
					else
						if(s[i] > *it) ret.push_front(s[i]);
						else ret.push_back(s[i]);
				}
		for(i = 0, it = ret.begin(); it != ret.end(); it++, i++)
			ans[i] = *it;
		ans[i] = '\0';
		ret.clear();
		printf("Case #%d: %s\n", tn++, ans);
	}
	return 0;
}
