#include<stdio.h>
#include<string.h>

const int mx=2000010;

char s[20],s2[20];
int a,b;
bool vis[mx];

int cal(int n)
{
	int i,j;
	sprintf(s,"%d",n);
	int len=strlen(s);
	if( 1 == len ) return 1;
	int p,cnt=1;
	s2[len]='\0';
	for(i=1;i<len;i++)
	{
		if('0' == s[i]) continue;
		for(j=0;j<len;j++)
		{
			s2[j]=s[(i+j)%len];
		}
		sscanf(s2,"%d",&p);
		//printf("%d\n",p);
		if(a<=p&&p<=b&&vis[p]==false)
		{
			cnt++;
			vis[p]=true;
		}
	}
	return cnt;
}

int main()
{
	int i;
	int t,ca=0;

//	cal(12345);

	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int ans=0;
		for(i=a;i<=b;i++) vis[i]=false;
		for(i=a;i<=b;i++)
		{
			if(vis[i]) continue;
			vis[i]=true;
			int res=cal(i);
			ans += res*(res-1)/2;
		}
		printf("Case #%d: %d\n",(++ca),ans);
	}

	return 0;
}

