#include <stdio.h>
#include <algorithm>
int ans[2005],have[1005];
char s[2005];
void doe(int x)
{
	int anum=0,i;
	for(i=0;i<1000;i++)
		have[i]=0;
	scanf("%s",s);
	for(i=0;s[i]!=0;i++)
		have[s[i]]++;
	while(have['Z']>0)
	{
		have['Z']--;
		have['E']--;
		have['R']--;
		have['O']--;
		ans[anum++]=0;
	}
	while(have['W']>0)
	{
		have['T']--;
		have['W']--;
		have['O']--;
		ans[anum++]=2;
	}
	while(have['U']>0)
	{
		have['F']--;
		have['O']--;
		have['U']--;
		have['R']--;
		ans[anum++]=4;
	}
	while(have['X']>0)
	{
		have['S']--;
		have['I']--;
		have['X']--;
		ans[anum++]=6;
	}
	while(have['G']>0)
	{
		have['E']--;
		have['I']--;
		have['G']--;
		have['H']--;
		have['T']--;
		ans[anum++]=8;
	}
	while(have['F']>0)
	{
		have['F']--;
		have['I']--;
		have['V']--;
		have['E']--;
		ans[anum++]=5;
	}
	while(have['S']>0)
	{
		have['S']--;
		have['E']--;
		have['V']--;
		have['E']--;
		have['N']--;
		ans[anum++]=7;
	}
	while(have['I']>0)
	{
		have['N']--;
		have['I']--;
		have['N']--;
		have['E']--;
		ans[anum++]=9;
	}
	while(have['O']>0)
	{
		have['O']--;
		have['N']--;
		have['E']--;
		ans[anum++]=1;
	}
	while(have['T']>0)
	{
		have['T']--;
		have['H']--;
		have['R']--;
		have['E']--;
		have['E']--;
		ans[anum++]=3;
	}
	std::sort(ans,ans+anum);
	printf("Case #%d: ",x);
	for(i=0;i<anum;i++)
		printf("%d",ans[i]);
	printf("\n");
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("Aout.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		doe(i);
	return 0;
}
