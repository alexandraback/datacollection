#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,cnt[200],ans[100];
bool app[20];
char in[2010];
void done(long long x)
{
	
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,tt;
	int i,j;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		scanf("%s",in+1);
		n=strlen(in+1);
		for(i='A';i<='Z';++i)
			cnt[i]=0;
		for(i=1;i<=n;++i)
			++cnt[in[i]];
		cnt['E']-=cnt['Z'];
		cnt['R']-=cnt['Z'];
		cnt['O']-=cnt['Z'];
		ans[0]=cnt['Z'];
		cnt['T']-=cnt['W'];
		cnt['O']-=cnt['W'];
		ans[2]=cnt['W'];
		cnt['F']-=cnt['U'];
		cnt['O']-=cnt['U'];
		cnt['R']-=cnt['U'];
		ans[4]=cnt['U'];
		cnt['T']-=cnt['R'];
		cnt['H']-=cnt['R'];
		cnt['E']-=cnt['R'];
		cnt['E']-=cnt['R'];
		ans[3]=cnt['R'];
		cnt['E']-=cnt['G'];
		cnt['I']-=cnt['G'];
		cnt['H']-=cnt['G'];
		cnt['T']-=cnt['G'];
		ans[8]=cnt['G'];
		cnt['N']-=cnt['O'];
		cnt['E']-=cnt['O'];
		ans[1]=cnt['O'];
		cnt['I']-=cnt['F'];
		cnt['V']-=cnt['F'];
		cnt['E']-=cnt['F'];
		ans[5]=cnt['F'];
		cnt['S']-=cnt['X'];
		cnt['I']-=cnt['X'];
		ans[6]=cnt['X'];
		ans[7]=cnt['V'];
		ans[9]=cnt['I'];
		printf("Case #%d: ",t);
		for(i=0;i<=9;++i)
			for(j=1;j<=ans[i];++j)
				printf("%d",i);
		puts("");
	}
	return 0;
} 
