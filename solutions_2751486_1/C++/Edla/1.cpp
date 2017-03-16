#include<cstdio>
using namespace std;
char s[10000000];
int main()
{
	int t,T,n,l,ans,i,con,last;
	char c;
	scanf("%d",&T);
	scanf("%c",&c);
	for(t=1;t<=T;t++)
	{
		fgets(s,10000000,stdin);
		i=0;
		while(s[i]!=' ')
		{
			i++;
		}
		n=0;
		s[i]=0;
		l=i;
		i++;
		while(s[i]>='0'&&s[i]<='9')
		{	
			n=n*10+s[i]-48;
			i++;
		}
		con=0;
		last=0;
		//printf("%s %d\n",s,n);
		ans=0;
		for(i=0;i<l;i++)
		{
			if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			{
				con=0;
			}
			else
			{
				con++;
				if(con>=n)
				{
						ans+=(i-n+1-last+1)*(l-i);
					last=i-n+2;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
