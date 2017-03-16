#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cstring>
#include <ctime>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <list>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <sstream>
//C++11
//#include <unordered_map>
//#include <unordered_set>
using namespace std;
char mp[55][55];
int main()
{
	freopen("out","w",stdout);
	int T,r,c,m;
	scanf("%d",&T);
	for (int t=1;t<=T;++t)
	{
		scanf("%d%d%d",&r,&c,&m);
		memset(mp,'*',sizeof(mp));
		bool solved=false;
		if (r==1 || c==1 || m+1==r*c)
		{
			int rem=r*c-m;
			for (int i=0;i<r;++i)
			{
				int j;
				for (j=0;j<c;++j)
				{
					if (rem-->0)
						mp[i][j]='.';
					else
						break;
				}
				if (j<c)	break;
			}
			mp[0][0]='c';
			solved=true;
		}
		else
		{
			int total=r*c;
			for (int i=2;i<=r;++i)
			{
				for (int j=2;j<=c;++j)
				{
					int rem=m-(total-i*j);
					if (rem==0)
					{
						for (int pi=0;pi<i;++pi)
							for (int pj=0;pj<j;++pj)
								mp[pi][pj]='.';
						mp[0][0]='c';
						solved=true;
						break;
					}
					else if (rem>0 && rem<min(i,j))
					{
						if (i==2||j==2)	continue;
						if (i<j || i==j&&rem<=i-2)
						{
							int pi,pj;
							for (pi=0;pi<i;++pi)
								for (pj=0;pj<j;++pj)
									mp[pi][pj]='.'; 
							for (pj=j-1;pj>j-1-rem;--pj)
								mp[i-1][pj]='*';
							mp[0][0]='c';
							solved=true;
							break;
						} 
						else if (i>j)
						{
							int pi,pj;
							for (pi=0;pi<i;++pi)
								for (pj=0;pj<j;++pj)
									mp[pi][pj]='.'; 
							for (pi=i-1;pi>i-1-rem;--pi)
								mp[pi][j-1]='*';
							mp[0][0]='c';
							solved=true;
							break;
						}
						else if (i>=4)
						{
							int pi,pj;
							for (pi=0;pi<i;++pi)
								for (pj=0;pj<j;++pj)
									mp[pi][pj]='.';
							for (pi=i-1;pi>i-rem;--pi)
								mp[pi][j-1]='*';
							mp[i-1][j-2]='*';
							mp[0][0]='c';
							solved=true;
							break;
						}
					}
				}
				if (solved)	break;
			}
		}
		printf("Case #%d:\n",t);
		if (!solved)
			printf("Impossible\n");
		else
		{
			for (int i=0;i<r;++i)
			{
				for (int j=0;j<c;++j)
					putchar(mp[i][j]);
				putchar('\n');
			}
		}
	}
	return 0;
}