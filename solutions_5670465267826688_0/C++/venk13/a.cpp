#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

const int ONE=1;
const int I=2;
const int J=3;
const int K=4;

int table[4][4]={
	{ONE,I,J,K},
	{I,-ONE,K,-J},
	{J,-K,-ONE,I},
	{K,J,-I,-ONE}
};

inline int mul(int x,int y)
{

	int mul=x*y<0?-1:1;
	if(x<0) x=-x;
	if(y<0) y=-y;
	x=table[x-1][y-1];
	x*=mul;
	return x;
}

char s[10005];

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		int l,x;
		scanf("%d%d",&l,&x);
		scanf(" %s",s);
		//printf("input->%s\n",s);
		int used=1;
		int ptr=0;
		int cur=ONE;
		while(used<=4)
		{
			cur=mul(cur,s[ptr]-'i'+I);
			if(cur==I) break;
			++ptr;
			if(ptr==l)
			{
				++used;
				ptr=0;
			}
		}
		if(cur!=I)
		{
			printf("NO\n");
			continue;
		}
		//cerr<<"used!!\n";
		int used2=1;
		int ptr2=l-1;
		cur=ONE;
		while(used2<=4)
		{
			cur=mul(s[ptr2]-'i'+I,cur);
			//printf("cur=%d\n",cur);
			if(cur==K) break;
			--ptr2;
			if(ptr2<0)
			{
				++used2;
				ptr2=l-1;
			}
		}
		if(cur!=K)
		{
			printf("NO\n");
			continue;
		}
		//cerr<<"used="<<used<<", used2="<<used2<<'\n';
		//cerr<<"ptr="<<ptr<<", ptr2="<<ptr2<<'\n';
		if(used+used2>x+1)
		{
			printf("NO\n");
			continue;
		}
		if(used+used2==x+1)
		{
			if(ptr>=ptr2)
			{
				printf("NO\n");
				continue;
			}
			int now=ONE;
			for(int j=ptr+1;j<ptr2;++j)
			{
				now=mul(now,s[j]-'i'+I);
			}
			if(now!=J)
			{
				printf("NO\n");
			}
			else
			{
				printf("YES\n");
			}
			continue;
		}
		cur=ONE;
		for(int j=ptr+1;j<l;++j)
		{
			cur=mul(cur,s[j]-'i'+I);
		}
		int base=ONE;
		for(int j=0;j<l;++j)
			base=mul(base,s[j]-'i'+I);
		int exp=x-used-used2;
		int res=ONE;
		while(exp)
		{
			if(exp&1) res=mul(res,base);
			base=mul(base,base);
			exp>>=1;
		}
		cur=mul(cur,res);
		for(int j=0;j<ptr2;++j)
		{
			cur=mul(cur,s[j]-'i'+I);
		}
		if(cur==J)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
    return 0;
}