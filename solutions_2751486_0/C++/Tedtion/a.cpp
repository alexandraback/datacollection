#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define NN 1000099

bool isvow(char c)
{
	char vow[] = "aeiou";
	for (int i=0; vow[i]; i++)
	{
		if (vow[i] == c) return true;
	}
	return false;
}

int main()
{
	int t,n;
	char s[NN];
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	
	scanf("%d",&t);
	for (int cas=1; cas<=t; cas++)
	{
		scanf("%s%d",s,&n);
		long long ans = 0, L;
		int last=-1, con=0;
		L = strlen(s);
		for (int i=0; s[i]; i++)
		{
			if (isvow(s[i])) con=0;
			else con++;
			if (con==n) {
				ans += (i-n+1-last)*(L-i);
				last = i-n+1;
				con--;
			}
		}
		printf("Case #%d: %lld\n", cas, ans);
	}
	return 0;
}

