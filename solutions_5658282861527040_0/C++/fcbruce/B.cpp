#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
		freopen("t1","w",stdout);
	#endif

	int x,y,k;
	int tt;
	scanf("%d",&tt);

	for (int t=1;t<=tt;t++)
    {
        scanf("%d%d%d",&x,&y,&k);
        printf("Case #%d: ",t);
        int cnt=0;
        for (int i=0;i<x;i++)
        {
            for (int j=0;j<y;j++)
            {
                if ((i&j)<k)
                    cnt++;
            }
        }
        printf("%d\n",cnt);
    }




	return 0;
}
