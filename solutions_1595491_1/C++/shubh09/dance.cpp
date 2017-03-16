#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i,a,b)				for (int i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)

typedef long long ll;

vector <int> tot;

int main()
{
	int t;
	s(t);
	int n,s,p;
	FOR(i,0,t)
	{
		int count=0;
		int t2;
		s(n);s(s);s(p);
		tot.clear();
		FOR(j,0,n)
		{
			s(t2);
			tot.push_back(t2);
		}
		//FOR(j,0,n) p(tot[j]);
		//printf("\n");
		sort(tot.begin(),tot.end());
		//FOR(j,0,n) p(tot[j]);
		for(int k=n-1;k>=0;k--)
		{
			//if (s)
			//{
				int rem=tot[k]%3;
				int div=tot[k]/3;	//assuming div<=10
				if (rem==0)
				{
					if (div>=p) count++;
					else
					{
						if (div+1==p&&s&&div>=1&&div<=9)
						{
							count++;
							s--;
						}
					}
				}
				else
				{
					if (rem==1)
					{
						if (div+1>=p&&div<=9) count++;
					}
					else //rem==2
					{
						if (div+1>=p&&div<=9) count++;
						else
						{
							if (div+2==p&&s&&div<=8)
							{
								count++;
								s--;
							}
						}
					}
				}
			//}
		}
		printf("Case #%d: %d\n",i+1,count);
	}
	return 0;
}
