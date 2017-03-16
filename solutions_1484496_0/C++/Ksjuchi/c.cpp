#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int s[1000];
int st[25];

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	st[0]=1;
	for (int i=1;i<=20;i++)
		st[i]=st[i-1]*2;
	map<int,int> m;
	int t,n,cur;
	bool flag;
	cin >> t;
	for (int cnt=1;cnt<=t;cnt++)
	{
		flag=false;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",s+i);
		printf("Case #%d:\n",cnt);
		m.clear();
		for (int mask=0;mask<st[n];mask++)
		{
			cur=0;
			for (int i=0;i<n;i++)
				if (mask&st[i]) cur+=s[i];
			if (m.count(cur))
			{
				for (int i=0;i<n;i++)
					if (mask&st[i]) printf("%d ",s[i]);
				printf("\n");
				for (int i=0;i<n;i++)
					if (m[cur]&st[i]) printf("%d ",s[i]);
				printf("\n");
				flag=true;
				break;
			}
			else
				m[cur]=mask;
		}
		if (!flag) printf("Impossible\n");
	}
	return 0;
}