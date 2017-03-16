#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<set>
using namespace std;
int T,t,n,m;
long long ans;
char s1[10], s2[10];

int main()
{
	freopen("CIn.txt","r",stdin);
	freopen("Cout.txt","w",stdout);
	scanf("%d\n",&T);
	for(;T>0;T--)
	{
		ans=0;
		scanf("%d%d",&n,&m);
		for (int i=n;i<m;i++)
		{
			itoa(i,s1,10);
			set<int> f;
			for (int j=1;j<strlen(s1);j++) if (s1[j]!='0')
			{
				strcpy(s2,s1+j);
				strncat(s2,s1,j);
				int tmp=atoi(s2);
				if (tmp>i && tmp<=m && f.find(tmp)==f.end()) 
				{
    				ans++;
    				f.insert(tmp);
				}
			}
		}
		cout << "Case #" << ++t << ": " << ans << endl;
	}
	return 0;
}
