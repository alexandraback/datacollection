/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 10:01:15 AM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 10010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct onestar
{
	int a,b,i;
}onetmp;
struct twostar
{
	int a,b,i;
	friend bool operator<(twostar a,twostar b)
	{
		return a.b==b.b?a.a<b.a:a.b>b.b;
	}
}twotmp;
priority_queue<twostar> two;
int vone[N],vtwo[N],sco,ret;
onestar one[N];

int solve_two()
{
	int tag=0;
	for(; sco>=two.top().b&&!(two.empty()); )
	{
		twotmp=two.top();
		//printf("%d %d=>\n",two.top().b,sco);
		int i=twotmp.i;
		if(vone[i]&&vtwo[i])
		{
			two.pop();
			continue;
		}
		else if(vone[i])
		{
			tag=1;
			sco+=1;
			ret++;
			vtwo[i]=1;
			two.pop();
		}
		else if(vtwo[i])
		{
			vone[i]=1;
			two.pop();
		}
		else
		{
			tag=1;
			sco+=2;
			ret++;
			vtwo[i]=1;
			vone[i]=1;
			two.pop();
		}
	}
	if(two.empty())
		return 1;
	return tag;
}

int solve_one(int n)
{
	int tag=0;
	int id=-1,mx=0;
	for(int i=1; i<=n; i++)
	{
		if(sco<one[i].a)
			break;
		if(vone[one[i].i]==1||vtwo[one[i].i]==1)
			continue;
		if(mx<one[i].b)
			mx=one[i].b,id=i;
	}
	if(id==-1)	return 0;
	ret++,sco++;
	vone[one[id].i]=1;
//	printf("%d %d\n",id,sco);
	return 1;
}

int cmp(onestar a,onestar b)
{
	return a.a==b.a?a.b>b.b:a.a<b.a;
}

int main()
{
	int t,ca,n,a,b;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		memset(vone,0,sizeof(vone));
		memset(vtwo,0,sizeof(vtwo));
		ret=0;
		sco=0;
		printf("Case #%d: ",ca);
		for(; !two.empty(); )
			two.pop();
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d",&a,&b);
			twotmp.a=a,twotmp.b=b,twotmp.i=i;
			two.push(twotmp);
			one[i].a=a,one[i].b=b,one[i].i=i;
		}
		/*
		if(ca==23)
		{
			printf("%d\n",n);
			for(int i=1; i<=n; i++)
				printf("%d %d\n",one[i].a,one[i].b);
			puts("");
		}
		*/
		sort(one+1,one+1+n,cmp);
		int tagone,tagtwo;
		for(; !two.empty(); )
		{
			tagtwo=solve_two();
			tagone=solve_one(n);
			if(tagone==0)
				break;
		}
		if(two.empty())
			printf("%d\n",ret);
		else
			printf("Too Bad\n");
	}
	return 0;
}
