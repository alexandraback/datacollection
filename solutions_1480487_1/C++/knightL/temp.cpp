#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<sstream>
#include<ctime>
#include<set>
#include<queue>
#include<map>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;

int s[201];

int main()
{
	int T;
	scanf("%d",&T);
	for(int ai=1;ai<=T;ai++)
	{
		int N;
		int X=0;
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&s[i]);
			X+=s[i];
		}
		printf("Case #%d:",ai);
		for(int i=0;i<N;i++)
		{
			double l=0; double r=100;
			for(int j=0;j<100;j++)
			{
				double c=(l+r)/2;
				double curscore=s[i]+c*X/100;
				double left=100;
				for(int k=0;k<N;k++)
				{
					if((s[k]-curscore)<1e-5)
					{
						left-=(curscore-s[k])/X*100;
					}
				}
				if(left<-1e-7)
					r=c;
				else
					l=c;
			}
			printf(" %.14lf",l);
		}
		puts("");
	}
	return 0;
}
