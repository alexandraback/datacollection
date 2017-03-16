#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int T,ts,n,i,m,j,ok;
char s[20],t[20],ss[20],tt[20];
long long ac,aj;

void upd()
{
	long long a=0,b=0;
	int i;
	for(i=0;i<n;i++)
	{
		a=a*10+ss[i]-'0';
		b=b*10+tt[i]-'0';
	}
	if(ac==-1)
	{
		ac=a;
		aj=b;
		return;
	}
	if(abs(ac-aj)>abs(a-b))
	{
		ac=a;
		aj=b;
		return;
	}
	if(abs(ac-aj)<abs(a-b))
		return;
	if(a<ac || a==ac && b<aj)
	{
		ac=a;
		aj=b;
	}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",&s,&t);
		for(n=0;s[n];n++);
		for(i=0;i<n;i++)
			if(s[i]!='?' && t[i]!='?' && s[i]!=t[i])
				break;
		if(i==n)
		{
			for(i=0;i<n;i++)
				if(s[i]=='?' && t[i]=='?')
					s[i]=t[i]='0';
				else if(s[i]=='?')
					s[i]=t[i];
				else t[i]=s[i];
			printf("Case #%d: %s %s\n",++ts,s,t);
			continue;
		}
		m=i;
		ac=aj=-1;
		for(i=0;i<m;i++)
			tt[i]=ss[i]=s[i]!='?'?s[i]:t[i]!='?'?t[i]:'0';
		for(i=m;i<n;i++)
		{
			ss[i]=s[i]!='?'?s[i]:s[m]<t[m]?'9':'0';
			tt[i]=t[i]!='?'?t[i]:s[m]<t[m]?'0':'9';
		}
		upd();

		long long x,y;
		x=y=0;
		for(i=0;i<m;i++)
		{
			x=x*10+(s[i]=='?'?9:s[i]-'0');
			y=y*10+(t[i]=='?'?0:t[i]-'0');
		}
		if(x>y)
		{
			for(i=m-1;i>=0;i--)
				if(s[i]!='?' && t[i]!='?')
				{
					ss[i]=s[i];
					tt[i]=t[i];
				}
				else if(s[i]=='?' && t[i]=='?')
				{
					ok=false;
					for(j=i-1;j>=0;j--)
					{
						if((s[j]=='0' || s[j]=='?') && (t[j]=='9' || t[j]=='?'))
							continue;
						if(t[j]=='?' && s[j]!='0')
						{
							ok=true;
							break;
						}
					}
					if(!ok)
					{
						ss[i]='1';
						tt[i]='0';
						break;
					}
					for(;i>j;i--)
					{
						ss[i]='0';
						tt[i]='9';
					}
					ss[i]=s[i];
					tt[i]=s[i]-1;
					break;
				}
				else if(s[i]!='?')
				{
					ss[i]=s[i];
					tt[i]=s[i]=='0'?'9':s[i]-1;
					if(s[i]!='0')break;
				}
				else
				{
					ss[i]=t[i]=='9'?'0':t[i]+1;
					tt[i]=t[i];
					if(t[i]!='9')break;
				}
			for(i--;i>=0;i--)
				tt[i]=ss[i]=s[i]=='?' && t[i]=='?'?'0':s[i]=='?'?t[i]:s[i];
			for(i=m;i<n;i++)
			{
				ss[i]=s[i]=='?'?'0':s[i];
				tt[i]=t[i]=='?'?'9':t[i];
			}
			upd();
		}
		x=y=0;
		for(i=0;i<m;i++)
		{
			x=x*10+(s[i]=='?'?0:s[i]-'0');
			y=y*10+(t[i]=='?'?9:t[i]-'0');
		}
		if(x<y)
		{
			for(i=m-1;i>=0;i--)
				if(s[i]!='?' && t[i]!='?')
				{
					ss[i]=s[i];
					tt[i]=t[i];
				}
				else if(s[i]=='?' && t[i]=='?')
				{
					ok=false;
					for(j=i-1;j>=0;j--)
					{
						if((t[j]=='0' || t[j]=='?') && (s[j]=='9' || s[j]=='?'))
							continue;
						if(s[j]=='?' && t[j]!='0')
						{
							ok=true;
							break;
						}
					}
					if(!ok)
					{
						tt[i]='1';
						ss[i]='0';
						break;
					}
					for(;i>j;i--)
					{
						tt[i]='0';
						ss[i]='9';
					}
					tt[i]=t[i];
					ss[i]=t[i]-1;
					break;
				}
				else if(s[i]!='?')
				{
					ss[i]=s[i];
					tt[i]=s[i]=='9'?'0':s[i]+1;
					if(s[i]!='9')break;
				}
				else
				{
					ss[i]=t[i]=='0'?'9':t[i]-1;
					tt[i]=t[i];
					if(t[i]!='0')break;
				}
			for(i--;i>=0;i--)
				tt[i]=ss[i]=s[i]=='?' && t[i]=='?'?'0':s[i]=='?'?t[i]:s[i];
			for(i=m;i<n;i++)
			{
				ss[i]=s[i]=='?'?'9':s[i];
				tt[i]=t[i]=='?'?'0':t[i];
			}
			upd();
		}
		for(i=n-1;i>=0;i--)
		{
			s[i]=ac%10+'0';
			t[i]=aj%10+'0';
			ac/=10;
			aj/=10;
		}
		printf("Case #%d: %s %s\n",++ts,s,t);
	}
	return 0;
}