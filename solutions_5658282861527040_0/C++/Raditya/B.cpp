#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
inline void OPEN(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
inline void CLOSE()
{
	fclose(stdin);
	fclose(stdout);
}
int t;
int main()
{
	int a,b,k;
	scanf("%d", &t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d", &a, &b, &k);
		int tot = 0;
		for(int j=0;j<a;j++)
		{
			for(int kk=0;kk<b;kk++)
			{
				if((j&kk) < k) tot++;
			}
		}
		printf("Case #%d: %d\n", i, tot);
	}
	return 0;
}
