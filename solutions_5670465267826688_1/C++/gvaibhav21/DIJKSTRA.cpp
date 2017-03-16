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
#define pd(a) prlong longf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
int main()
{
	int t;
	int l;
	int i,j,k,i1,i2,cur;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char s[10010];
	int in[10010];
	int in1[50010];
	long long x;
	int op[9][9]={
		{0,0,0,0,0,0,0,0,0},
		{0,1,2,3,4,5,6,7,8},
		{0,2,5,4,7,6,1,8,3},
		{0,3,8,5,2,7,4,1,6},
		{0,4,3,6,5,8,7,2,1},
		{0,5,6,7,8,1,2,3,4},
		{0,6,1,8,3,2,5,4,7},
		{0,7,4,1,6,3,8,5,2},
		{0,8,7,2,1,4,3,6,5}
	};
	sd(t);
	for(k=1;k<=t;++k)
	{
		scanf("%d %lld",&l,&x);
		scanf("%s",&s);
		for(i=0;i<l;++i)
		{
			if(s[i]=='i')
				in[i]=2;
			else if(s[i]=='j')
				in[i]=3;
			else
				in[i]=4;
		}
		for(i=0;i<4;++i)
		{
			for(j=0;j<l;++j)
				in1[i*l+j]=in[j];
		}
		i=1;
		cur=in1[0];
		while(cur!=2&&i<4*l)
		{
			cur=op[cur][in1[i]];
			++i;
		}
		if(cur==2)
		{
			i1=i-1;
			cur=in1[4*l-1];
			i=4*l-2;
			while(cur!=4&&i>=0)
			{
				cur=op[in1[i]][cur];
				--i;
			}
			if(cur==4)
			{
				i2=i+1;
				if(i1<x*l-4*l+i2-1)
				{
					if(x<=10)
					{
						cur=in1[i1+1];
						for(i=i1+2;i<x*l-4*l+i2;++i)
						{
							cur=op[cur][in1[i]];
						}
						if(cur==3)
							printf("Case #%d: YES\n",k);
						else
							printf("Case #%d: NO\n",k);
					}
					else
					{
						cur=in1[0];
						for(i=1;i<l;++i)
							cur=op[cur][in1[i]];
						long long x1=x;
						int cur1=cur;
						while((x1-1)%4)
						{
							cur1=op[cur1][cur];
							x1--;
						}
						cur=in1[i1+1];
						for(i=i1+2;i<4*l;++i)
							cur=op[cur][in1[i]];
						cur=op[cur][cur1];
						for(i=0;i<i2;++i)
							cur=op[cur][in1[i]];
						if(cur==3)
							printf("Case #%d: YES\n",k);
						else
							printf("Case #%d: NO\n",k);

					}
				}
				else
					printf("Case #%d: NO\n",k);

			}
			else
				printf("Case #%d: NO\n",k);
		}
		else
			printf("Case #%d: NO\n",k);

	}
}