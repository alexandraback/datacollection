#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#define LL long long
using namespace std;
int T,l;
char s[90005];
LL x;
void Calc(char a[],char b[],char s[])
{
	s[0]=s[1]=' ';
	if (a[0]=='i'&&b[0]=='j') s[0]='k';
	if (a[0]=='j'&&b[0]=='i') s[1]='k',s[0]='-';
    if (a[0]=='j'&&b[0]=='k') s[0]='i';
    if (a[0]=='k'&&b[0]=='j') s[1]='i',s[0]='-';
    if (a[0]=='k'&&b[0]=='i') s[0]='j';
    if (a[0]=='i'&&b[0]=='k') s[1]='j',s[0]='-';
	if (a[0]=='1') s[0]=b[0];
	if (a[0]=='-'&&a[1]=='1') s[0]='-',s[1]=b[0];
	if (a[0]==b[0]) s[0]='-',s[1]='1';

	if (a[0]=='-'&&a[1]!='1')
	{
	a[0]=a[1];
    if (a[0]=='i'&&b[0]=='j') s[0]='k';
	if (a[0]=='j'&&b[0]=='i') s[1]='k',s[0]='-';
    if (a[0]=='j'&&b[0]=='k') s[0]='i';
    if (a[0]=='k'&&b[0]=='j') s[1]='i',s[0]='-';
    if (a[0]=='k'&&b[0]=='i') s[0]='j';
    if (a[0]=='i'&&b[0]=='k') s[1]='j',s[0]='-';
	if (s[0]=='-') s[0]=s[1];
	else s[1]=s[0],s[0]='-';
	if (a[0]==b[0]) s[0]='1';
	}
}
int main()
{
	freopen("t.in","r",stdin);freopen("t.out","w",stdout);
    scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%lld",&l,&x);
		scanf("%s",s+1);
		if (1LL*l*x<3LL)
		{
			printf("NO\n");
			continue;
		}
		int m=(int)((int)min(x,8LL)*l);
		for (int i=l+1;i<=m;i++)
			s[i]=s[i-l];
		char now[4];
		now[0]=s[1];
		for (int i=2;i<=l;i++)
		{
			char a[4],b[4];
			b[0]=now[0],b[1]=now[1];
			a[0]=s[i];
			Calc(b,a,now);
		}
		if (now[0]=='1')
		{
			printf("NO\n");
			continue;
		}
		if (now[0]=='-')
		{
			if ((now[1]=='1'&&(x%2LL==0LL))||(now[1]!='1'&&(x%4LL!=2LL)))
			{
				printf("NO\n");
				continue;
			}
		}
		if (now[0]!='-')
		{
			if (x%4LL!=2LL)
			{
				printf("NO\n");
				continue;
			}
		}
		if (now[0]=='-'&&now[1]=='1')
			m=(int)((int)min(x,4LL)*l);
		int oki=0,okk=0;
		now[0]=s[1];
		if (now[0]=='i') oki=1;
		for (int i=2;i<=m;i++)
		{
            char a[4],b[4];
			b[0]=now[0],b[1]=now[1];
			a[0]=s[i];
			Calc(b,a,now);
			if (!oki&&now[0]=='i') oki=i;
			if (now[0]=='k'&&(!okk||okk<oki))
				okk=i;
		}
		if (!okk||!oki)
		{
			printf("NO\n");
			continue;
		}
		if ((okk>oki&&okk<(1LL*x*l))||(okk<oki&&m+okk<(1LL*x*l)))
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
