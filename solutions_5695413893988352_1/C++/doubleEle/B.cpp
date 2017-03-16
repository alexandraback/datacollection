#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long ans,sum,mina,minb,nowa,nowb,a[20],b[20];
int n,T;
char s[20];

void dfs(int x,long long u,long long v)
{
	if (x>n)
	{
		if (ans==sum)
		{
			if ((nowa<mina)||((nowa==mina)&&(nowb<minb)))
			{
				mina=nowa;
				minb=nowb;
			}
		}
		if (ans>sum)
		{
			ans=sum;
			mina=nowa;
			minb=nowb;
		}
		return;
	}
	long long aa,bb,c;
	if (u==9) c=1; else c=-1;
	if (a[x]<0) aa=u; else aa=a[x];
	if (b[x]<0) bb=v; else bb=b[x];
	sum=sum*10+(bb-aa)*c;
	nowa=nowa*10+aa;
	nowb=nowb*10+bb;
	dfs(x+1,u,v);
	nowb/=10;
	nowa/=10;
	sum=(sum-(bb-aa)*c)/10;
}
	

int main()
{
//	freopen("B-large.in","r",stdin);
//	freopen("B-large.out","w",stdout);
	scanf("%d",&T);
	for (int id=1; id<=T; id++)
	{
		scanf("%s",s);
		n=strlen(s);
		for (int i=1; i<=n; i++) if (s[i-1]=='?') a[i]=-1; else
												a[i]=s[i-1]-'0';
		scanf("%s",s);
		for (int i=1; i<=n; i++) if (s[i-1]=='?') b[i]=-1; else
												b[i]=s[i-1]-'0';
		//for (int i=1; i<=n; i++) cout << i << ' ' << a[i] << endl;
		ans=mina=minb=1000000000000000000;
		sum=nowa=nowb=0;
		for (int i=1; i<=n+1; i++) 
		{if (i==n+1)
				{
					if (sum<ans)
					{
						if ((nowa<mina)||((nowa==mina)&&(nowb<minb)))
						{
							mina=nowa;
							minb=nowb;
						}
						ans=sum;
					}
					if (ans==sum)
					{
						ans=0;
						mina=nowa;
						minb=nowb;
					}
					break;
					}
			if ((a[i]>=0)&&(a[i]==b[i]))
			{
				nowa=nowa*10+a[i];
				nowb=nowb*10+b[i];
				sum=sum*10;
				
			}
			if ((a[i]<0)&&(b[i]<0))
			{
				nowa=nowa*10;
				nowb=nowb*10+1;
				sum=sum*10+1;
				dfs(i+1,9,0);
				nowb--;
				sum--;
			}
			if ((a[i]<0)&&(b[i]>=0))
			{
				if (b[i]!=0)
				{
					nowa=nowa*10+b[i]-1;
					nowb=nowb*10+b[i];
					sum=sum*10+1;
					dfs(i+1,9,0);
					nowa++;
					sum--;
				}
				else
				{
					nowa=nowa*10+b[i];
					nowb=nowb*10+b[i];
					sum=sum*10;
				}
			}
			if ((a[i]>=0)&&(b[i]<0))
			{
				if (a[i]!=9)
				{
					nowa=nowa*10+a[i];
					nowb=nowb*10+a[i]+1;
					sum=sum*10+1;
					dfs(i+1,9,0);
					nowb--;
					sum--;
				}
				else
				{
					nowa=nowa*10+a[i];
					nowb=nowb*10+a[i];
					sum=sum*10;
				}
			}
			if ((a[i]>=0)&&(b[i]>=0)&&(a[i]!=b[i]))
			{
				if (a[i]>b[i]) break;
				nowa=nowa*10+a[i];
				nowb=nowb*10+b[i];
				sum=sum*10+b[i]-a[i];
				dfs(i+1,9,0);
				break;
			}
			//cout << nowa << ' ' << nowb << endl;
		}
		
		//cout << ans << ' ' << mina << ' ' << minb << endl;
		
		sum=nowa=nowb=0;
		for (int i=1; i<=n+1; i++) 
		{
			if (i==n+1)
				{
					if (sum<ans)
					{
						if ((nowa<mina)||((nowa==mina)&&(nowb<minb)))
						{
							mina=nowa;
							minb=nowb;
						}
						ans=sum;
					}
					if (ans==sum)
					{
						ans=0;
						mina=nowa;
						minb=nowb;
					}
					break;
					}
			if ((a[i]>=0)&&(a[i]==b[i]))
			{
				nowa=nowa*10+a[i];
				nowb=nowb*10+b[i];
				sum=sum*10;
			}
			if ((a[i]<0)&&(b[i]<0))
			{
				nowa=nowa*10+1;
				nowb=nowb*10;
				sum=sum*10+1;
				dfs(i+1,0,9);
				nowa--;
				sum--;
			}
			if ((a[i]<0)&&(b[i]>=0))
			{
				if (b[i]!=9)
				{
					nowa=nowa*10+b[i]+1;
					nowb=nowb*10+b[i];
					sum=sum*10+1;
					dfs(i+1,0,9);
					nowa--;
					sum--;
				}
				else
				{
					nowa=nowa*10+b[i];
					nowb=nowb*10+b[i];
					sum=sum*10;
				}
			}
			if ((a[i]>=0)&&(b[i]<0))
			{
				if (a[i]!=0)
				{
					nowa=nowa*10+a[i];
					nowb=nowb*10+a[i]-1;
					sum=sum*10+1;
					dfs(i+1,0,9);
					nowb++;
					sum--;
				}
				else
				{
					nowa=nowa*10+a[i];
					nowb=nowb*10+a[i];
					sum=sum*10;
				}
			}
			if ((a[i]>=0)&&(b[i]>=0)&&(a[i]!=b[i]))
			{
				if (a[i]<b[i]) break;
				nowa=nowa*10+a[i];
				nowb=nowb*10+b[i];
				sum=sum*10+a[i]-b[i];
				dfs(i+1,0,9);
				break;
			}
		}
		
		
		
		//cout << ans << ' ' << mina << ' ' << minb << endl;
		
		printf("Case #%d: ",id);
		int len=0; long long x=mina;
		if (x==0) len=1; else
		while (x>0) 
		{
			x/=10;
			len++;
		}
		for (int i=len+1; i<=n; i++) printf("0"); printf("%lld ",mina);
	    len=0;x=minb; 
	    if (x==0) len=1; else
		while (x>0) 
		{
			x/=10;
			len++;
		}
		for (int i=len+1; i<=n; i++) printf("0"); printf("%lld\n",minb);
	}
	return 0;
}
