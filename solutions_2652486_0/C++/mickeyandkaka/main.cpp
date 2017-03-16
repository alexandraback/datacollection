#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define clr(a,b)    (memset(a,b,sizeof(a)))
#define rep(i,a)    for(int i=0; i<(int)a.size(); i++)

const int INF = 0x3f3f3f3f;
const double eps = 1E-8;

int T;
int r,n,m,k;
int num;
int fg[10][4];

int c1[4],c2[4];

int main()
{
	freopen("D:\\C-small-1-attempt0.in","r",stdin);
	freopen("D:\\out.txt","w",stdout);

	int cas = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d:\n",cas++);

		for(int i=1; i<=r; i++)
		{
			clr(fg, 0);
			for(int j=1; j<=k; j++)
			{
				scanf("%d",&num);
				while(num % 5 == 0)	fg[j][2]++,num/=5;
				while(num % 3 == 0)	fg[j][1]++,num/=3;
				while(num % 2 == 0)	fg[j][0]++,num/=2;
			}
			clr(c1, 0);
			for(int j=1; j<=k; j++)
			{
				c1[0] = max(c1[0], fg[j][0]);
				c1[1] = max(c1[1], fg[j][1]);
				c1[2] = max(c1[2], fg[j][2]);
			}

			int a1,a2,a3;

			bool fd = false;
			for(int a=2; a<=5 && fd == false; a++)
			{
				for(int b=2; b<=5 && fd == false; b++)
				{
					for(int c=2; c<=5 && fd == false; c++)
					{
						clr(c2, 0);
						int tmp = a;
						while(tmp % 2 == 0)	c2[0]++,tmp/=2;
						while(tmp % 3 == 0)	c2[1]++,tmp/=3;
						while(tmp % 5 == 0)	c2[2]++,tmp/=5;

						tmp = b;
						while(tmp % 2 == 0)	c2[0]++,tmp/=2;
						while(tmp % 3 == 0)	c2[1]++,tmp/=3;
						while(tmp % 5 == 0)	c2[2]++,tmp/=5;


						tmp = c;
						while(tmp % 2 == 0)	c2[0]++,tmp/=2;
						while(tmp % 3 == 0)	c2[1]++,tmp/=3;
						while(tmp % 5 == 0)	c2[2]++,tmp/=5;

						if(c1[0] == c2[0] && c1[1] == c2[1] && c1[2] == c2[2])
						{
							fd = true;
							a1 = a;
							a2 = b;
							a3 = c;
						}
					}
				}
			}

			printf("%d%d%d\n",a1,a2,a3);
		}
	}
	return 0;
}
