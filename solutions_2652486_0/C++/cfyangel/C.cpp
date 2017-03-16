#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int r,n,m,k,t,id;
int i,j,x,y,z,flag,maxx;
int a[100];

int main()
{
	freopen("C-small-1-attempt1.in","r",stdin);freopen("c.out","w",stdout);
    scanf("%d",&t);
	printf("Case #1:\n");
	scanf("%d%d%d%d",&r,&n,&m,&k);
    for (id=1;id<=r;id++)
    {
		maxx=1;
		for (i=0;i<k;i++)
		{
			scanf("%d",&a[i]);
			if (maxx<a[i])maxx=a[i];
		}
		for (x=2;x<=m;x++)
		{
			for (y=2;y<=m;y++)
			{
				for (z=2;z<=m;z++)
				{
					flag=1;
					if (x*y*z<maxx)flag=0;
					for (i=0;i<k;i++)
						if (a[i]>1 && a[i]%x>0 && a[i]%y>0 && a[i]%z>0 )flag=0;
					if (flag==1)break;
				}
				if (flag==1)break;
			}
			if (flag==1)break;
		}
		printf("%d%d%d\n",x,y,z);
    }
	return 0;
}