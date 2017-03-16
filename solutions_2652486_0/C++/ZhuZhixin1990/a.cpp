#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstring>//memset需要
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <stack>
using namespace std;
typedef __int64 ll;
const int N = 1005;
int cnt[N],ar[N];
bool u[N][10];
////////////////
int main(){
	//请在此填代码
	int tt;
	int ca=1;
	scanf("%d",&tt);
	while(tt--)
	{
		printf("Case #%d:\n",ca++);
		int R,N,M,K;
		scanf("%d%d%d%d",&R,&N,&M,&K);
		while(R--)
		{
			for(int i=0;i<K;i++)scanf("%d",&ar[i]);
			memset(cnt,0,sizeof(cnt));
			memset(u,0,sizeof(u));
			int a,b,c;
			for(a=2;a<=M;a++)
			{
				for(b=2;b<=M;b++)
				{
					for(c=2;c<=M;c++)
					{
						for(int i1=0;i1<2;i1++)
						{
							for(int i2=0;i2<2;i2++)
							{
								for(int i3=0;i3<2;i3++)
								{
									int r=1;
									if(i1)r*=a;
									if(i2)r*=b;
									if(i3)r*=c;
									//printf("a:%d b:%d c:%d r:%d \n",a,b,c,r);
									for(int h=0;h<K;h++)
									{
										if(ar[h]==r){cnt[a*100+b*10+c]++;u[a*100+b*10+c][h]=true;}
									}
								}
							}
						}
					}
				}
			}
			int i,j=0;
			for(i=0;i<1000;i++)
			{
				int h;
				for(h=0;h<K;h++)if(!u[i][h])break;
				if(h==K&&cnt[i]>cnt[j])j=i;
			}
			printf("%d\n",j);
		}
	}
	return 0;
}