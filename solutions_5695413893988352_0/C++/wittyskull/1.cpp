#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.1415926535897932
#define inf 10000000000000
char c[5],j[5];
int main()
{ 
	int t;
	scanf("%d",&t);
	int y=0;
	while(t--)
	{
		y++;
		printf("Case #%d: ",y);
		scanf("%s",c);
		scanf("%s",j);
		int n=strlen(c);
		if(n==1)
		{
			int cf=c[0]-'0';
			int jf=j[0]-'0';
			int cans=10000,jans=10000,diff=10000;
			int i,k;
			for(i=0;i<=9;i++)
			{
				for(k=0;k<=9;k++)
				{
					if((c[0]=='?'||cf==i)&&(j[0]=='?'||jf==k))
					{
						if(abs(i-k)<diff)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
						else if(abs(i-k)==diff&&i<cans)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
						else if(abs(i-k)==diff&&k<jans)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
					}
				}
			}
			printf("%d %d\n",cans,jans);
		}
		else if(n==2)
		{
			int cf=c[0]-'0';
			int jf=j[0]-'0';
			int cs=c[1]-'0';
			int js=j[1]-'0';
			int cans=10000,jans=10000,diff=10000;
			int i,k;
			for(i=0;i<=99;i++)
			{
				for(k=0;k<=99;k++)
				{
if((c[0]=='?'||cf==i/10)&&(j[0]=='?'||jf==k/10)&&(c[1]=='?'||cs==i%10)&&(j[1]=='?'||js==k%10))
					{
						if(abs(i-k)<diff)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
						else if(abs(i-k)==diff&&i<cans)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
						else if(abs(i-k)==diff&&k<jans)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
					}
				}
			}
			if(cans<=9)
			printf("0%d ",cans);
			else
			printf("%d ",cans);
			if(jans<=9)
			printf("0%d\n",jans);
			else
			printf("%d\n",jans);
		}
		else
		{
			int cf=c[0]-'0';
			int jf=j[0]-'0';
			int cs=c[1]-'0';
			int js=j[1]-'0';
			int ct=c[2]-'0';
			int jt=j[2]-'0';
			int cans=10000,jans=10000,diff=10000;
			int i,k;
			for(i=0;i<=999;i++)
			{
				for(k=0;k<=999;k++)
				{	
if((c[0]=='?'||cf==i/100)&&(j[0]=='?'||jf==k/100)&&(c[1]=='?'||cs==(i/10)%10)&&(j[1]=='?'||js==(k/10)%10)&&(c[2]=='?'||ct==i%10)&&(j[2]=='?'||jt==k%10))
					{
						if(abs(i-k)<diff)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
						else if(abs(i-k)==diff&&i<cans)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
						else if(abs(i-k)==diff&&k<jans)
						{
							diff=abs(i-k);
							cans=i;
							jans=k;
						}
					}
				}
			}
			if(cans<=9)
			printf("00%d ",cans);
			else if(cans<=99)
			printf("0%d ",cans);
			else
			printf("%d ",cans);
			if(jans<=9)
			printf("00%d\n",jans);
			else if(jans<=99)
			printf("0%d\n",jans);
			else
			printf("%d\n",jans);
		}
			
	}
	return 0;
}
