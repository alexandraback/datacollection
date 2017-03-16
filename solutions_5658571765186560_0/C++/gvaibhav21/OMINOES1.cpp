#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;

#define sd(a) scanf("%d",&a)
#define pd(a) printf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int main()
{
	int i,j,k,l;
	int t,x,r,c;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	sd(t);
	for(l=1;l<=t;++l)
	{
		sd(x);
		sd(r);
		sd(c);
		if(x==1)
			printf("Case #%d: GABRIEL\n",l);
		else if(x==2)
		{
			if((r*c)%2==1)
				printf("Case #%d: RICHARD\n",l);
			else
				printf("Case #%d: GABRIEL\n",l);
		}
		else if(x==3)
		{
			if((r==3&&c==3)||(r==3&&c==4)||(r==4&&c==3)||(r==3&&c==2)||(r==2&&c==3))
				printf("Case #%d: GABRIEL\n",l);
			else
				printf("Case #%d: RICHARD\n",l);
		}
		else
		{
			if(r==4&&c==3||r==3&&c==4||r==4&&c==4)
				printf("Case #%d: GABRIEL\n",l);
			else
				printf("Case #%d: RICHARD\n",l);
		}
	}
}