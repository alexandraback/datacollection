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

int T,ts,n,i,j,x,ac,aj;
char s[20],t[20];
vector<int>v,w;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",&s,&t);
		for(n=0;s[n];n++);
		v.clear();
		w.clear();
		for(i=0;i<1000;i++)
		{
			x=i;
			j=n-1;
			for(j=n-1;j>=0;j--)
			{
				if(s[j]!='?' && s[j]-'0'!=x%10)
					break;
				x/=10;
			}
			if(!x && j<0)
				v.push_back(i);
		}
		for(i=0;i<1000;i++)
		{
			x=i;
			j=n-1;
			for(j=n-1;j>=0;j--)
			{
				if(t[j]!='?' && t[j]-'0'!=x%10)
					break;
				x/=10;
			}
			if(!x && j<0)
				w.push_back(i);
		}
		ac=aj=-1;
		for(i=0;i<v.size();i++)
			for(j=0;j<w.size();j++)
				if(ac==-1 || abs(w[j]-v[i])<abs(ac-aj))
				{
					ac=v[i];
					aj=w[j];
					continue;
				}
		for(j=n-1;j>=0;j--)
		{
			s[j]=ac%10+'0';
			t[j]=aj%10+'0';
			ac/=10;
			aj/=10;
		}
		printf("Case #%d: %s %s\n",++ts,s,t);
		/*for(i=0;i<n;i++)
			if(s[i]!='?' && t[i]!='?')
				break;
		if(i==n)
		{
			for(i=0;i<n;i++)
				if(s[i]=='?' && t[i]=='?')
					s[i]=t[i]=0;
				else if(s[i]=='?')
					s[i]=t[i];
				else t[i]=s[i];
			printf("Case #%d: %s %s\n",++ts,s,t);
			continue;
		}*/
	}
	return 0;
}