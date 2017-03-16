#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<string>
#include<cctype>
#include<list>
#include<set>
#include<deque>
#include<queue>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>

using namespace std;

int main()
{
	int t,i,j,curr,k,ans,l,c,n,e,test;
	char a[1000];
	int start[1000],end[1000];
	scanf("%d",&t);test=1;
	while(t--)
	{
		scanf("%s %d",a,&n);
		l=strlen(a);
		/*for(i=n-1;i>=0;i++)
		{
			if((a[i]!='a')&&(a[i]!='e')&&(a[i]!='i')&&(a[i]!='o')&&(a[i]!='u'))
			{
				curr++;
				if(i>j)j=i;
			}
			else break;
		}
		i=n;j=;ans=0;
		while(i<l)
		{
			if((a[i]!='a')&&(a[i]!='e')&&(a[i]!='i')&&(a[i]!='o')&&(a[i]!='u'))
			{
				curr++;
				if(curr==n)ans=ans+*/
		c=0;
		for(i=0;i<l;i++)
		{
			if((a[i]!='a')&&(a[i]!='e')&&(a[i]!='i')&&(a[i]!='o')&&(a[i]!='u'))
			{
				start[c]=i;
				while(((a[i]!='a')&&(a[i]!='e')&&(a[i]!='i')&&(a[i]!='o')&&(a[i]!='u'))&&(i<l))
				{i++;}
				if(i-start[c]>=n)
				{
					end[c]=i;c++;
				}
			}
		}
ans=0;
		for(i=0;i<c;i++)
		{
			if(i<c-1)e=start[i+1]+n;
			else e=l+1;
			k=start[i];j=start[i]+n;
			while(j<=end[i])
			{
				ans=ans+k+1;
				k++;j++;
			}
			while(j<e)
			{
				ans=ans+k;
				j++;
			}
		}
			printf("Case #%d: %d\n",test,ans);test++;
}
return 0;
}

















