#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

using namespace std;
int a[21];
vector<pnt > b,c;
vector<int> res1,res2;
vector<pnt > doit(int l)
{
	vector<pnt > res;
	FOR(i,0,59049)
	{
		int sum1=0,sum2=0;
		int v=i;
		FOR(j,0,10)
		{
			int q=v%3;
			v/=3;
			if (q==1)
				sum1+=a[l+j];
			if (q==2)
				sum2+=a[l+j];
		}
		res.push_back(mp(sum2-sum1,i));
	}
	return res;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	FOR(it,1,t+1)
	{
		int n;
		scanf("%d",&n);
		FOR(i,0,n)
			scanf("%d",&a[i]);
		b=doit(0);
		c=doit(10);
		res1.clear();
		res2.clear();
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		printf("Case #%d:\n",it);
		bool f=false;
		FOR(i,0,b.size())
		{
			int l=0,r=c.size()-1;
			int best=-1;
			while (l<=r)
			{
				int m=(l+r)/2;
				if (c[m].first>-b[i].first)
					r=m-1;
				else
					if (c[m].first<-b[i].first)
						l=m+1;
					else
					{
						if ((b[i].second==0) && (c[m].second==0))
							l=m+1;
						else
						{
							best=m;
							break;
						}
					}
			}
			if (best!=-1)
			{
				int v=b[i].second;
				FOR(j,0,10)
				{
					int q=v%3;
					v/=3;
					if (q==1)
						res1.push_back(a[j]);
					if (q==2)
						res2.push_back(a[j]);
				}
				v=c[best].second;
				FOR(j,0,10)
				{
					int q=v%3;
					v/=3;
					if (q==1)
						res1.push_back(a[10+j]);
					if (q==2)
						res2.push_back(a[10+j]);
				}
				if ((res1.size()==0) || (res2.size()==0))
				{
					res1.clear();
					res2.clear();
					continue;
				}
				f=true;
				int sum1=0,sum2=0;
				FOR(i,0,res1.size())
				{
					if (i)
						printf(" ");
					sum1+=res1[i];
					printf("%d",res1[i]);
				}
				printf("\n");
				FOR(i,0,res2.size())
				{
					if (i)
						printf(" ");
					sum2+=res2[i];
					printf("%d",res2[i]);
				}
				printf("\n");
				fprintf(stderr,"%d %d\n",sum1,sum2);
				break;
			}
		}
		if (!f)
			printf("Impossible\n");
	}
	return 0;
}