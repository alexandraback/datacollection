#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<sstream>

#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<bitset>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<string> vs; 
typedef pair<int,int> ii;
typedef long long int LLI;
typedef unsigned long long int ULLI;

#define sz(a)                        int((a).size()) 
#define pb                           push_back 
#define mp                           make_pair
#define F                            first
#define S                            second
#define present(c,x)                 ((c).find(x) != (c).end()) 
#define cpresent(c,x)                (find(all(c),x) != (c).end())
#define tr(c,i)                      for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define all(c)                       (c).begin(),(c).end()
#define si(n)                        scanf("%d",&n)
#define sl(n)                        scanf("%lld",&n)
#define sf(n)                        scanf("%f",&n)
#define sd(n)                        scanf("%lf",&n)
#define ss(n)                        scanf("%s",n)

#define INF                          INT_MAX
#define LINF                         (long long)1e18
#define EPS                          1e-9
#define max(a,b)                     ((a)>(b)?(a):(b))
#define min(a,b)                     ((a)<(b)?(a):(b))
#define abs(x)                       ((x)<0?-(x):(x))
#define fill(a,v)                    memset((a),(v),sizeof (a))

int a[22];
int sum[2200000];
int main()
{
	int t,n,lim,summ,flag;
	si(t);
	for(int cases=1; cases<=t; cases++)
	{
		fill(sum,-1);
		si(n);
		for(int i=0; i<n; i++)
			si(a[i]);

		flag = 0;
		printf("Case #%d:\n",cases);
		lim = 1<<n;
		for(int i=1; i<lim; i++)
		{
			bitset<20> bs(i);
			summ = 0;
			for(int j=0; j<n; j++)
				if(bs[j] == 1)
					summ += a[n-1-j];
			if(sum[summ] == -1)
				sum[summ] = i;
			else
			{
				flag = 1;
				bitset<20> bs1(sum[summ]);
				bitset<20> bs2(i);
				for(int j=0; j<n; j++)
					if(bs1[j] == 1)
						printf("%d ",a[n-1-j]);
				printf("\n");
				for(int j=0; j<n; j++)
					if(bs2[j] == 1)
						printf("%d ",a[n-1-j]);
				printf("\n");
				break;
			}
		}
		if(flag == 0)
			printf("Impossible\n");
	}
	return 0;
}
