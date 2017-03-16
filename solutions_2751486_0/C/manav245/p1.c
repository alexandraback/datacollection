#include<stdio.h>
int vov(char x)
	{
	if(x=='a' || x=='e' || x=='o' || x=='i' || x=='u')
	return 0;
	return 1;	
	}
int main()
{
int T,t;
char s[150],nl[2];
int i,j,f,f2,ans,n;
scanf("%d",&T);
for(t=1;t<=T;t++)
	{
	gets(nl);
	scanf("%s %d",s,&n);
	ans=0;
	for(i=0;s[i]!='\0';i++)
			{
			f2=0;
			f=0;
			for(j=i;s[j]!='\0';j++)
					{
					if(f2==0)
						{
						if(vov(s[j])==1)	
						{
						f++;
			//			printf("#");
						}
						else
						{
							f=0;
						//	printf(".");
							}
						if(f==n)
							{
				//			printf("k");
							f2=1;
							}
						}
					if(f2==1)
					ans++;
					}
			}
		printf("Case #%d: %d\n",t,ans);
	}
return 0;	
}
