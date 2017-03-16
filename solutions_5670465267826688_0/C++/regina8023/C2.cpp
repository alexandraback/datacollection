#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#define LL long long
using namespace std;
int T,l;
char s[40005];
int x;
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
	freopen("t.in","r",stdin);freopen("t2.out","w",stdout);
    scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		scanf("%d%d",&l,&x);
		scanf("%s",s);
		if (l*x<3)
		{
			printf("NO\n");
			continue;
		}
		char now[4];
		now[0]=s[0];
		for (int i=1;i<l*x;i++)
		{
			char a[4],b[4];
			b[0]=now[0],b[1]=now[1];
			a[0]=s[i%l];
			Calc(b,a,now);
		}
		if (now[0]=='-'&&now[1]=='1')
		{
			now[0]=s[0];
			int oki=0,ok=0;
		if (now[0]=='i') oki=1;
		for (int i=1;i<x*l;i++)
		{
            char a[4],b[4];
			b[0]=now[0],b[1]=now[1];
			a[0]=s[i%l];
			Calc(b,a,now);
			if (now[0]=='i') oki=1;
			if (now[0]=='k'&&oki)
				ok=1;
		}
		if (ok)
			printf("YES\n");
		else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}
