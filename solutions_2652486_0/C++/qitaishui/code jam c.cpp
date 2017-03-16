#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;
const int maxn = 100005;
const int inf = 1111111111;
int r,n,m,k;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas,a;
    srand(time(NULL));
	scanf("%d",&cas);
	for(int ca = 1; ca<=cas; ca++)
    {
        scanf("%d%d%d%d",&r,&n,&m,&k);
         printf("Case #%d:\n",ca);
        for(int i = 1; i <=r; i++)
        {
            for(int j = 1;j <= n; j++)
            {
                scanf("%d",&a);
            }
            for(int j = 1; j <= n; j++)
            {
                a=2+(rand()%m);
                while(a>m){a=2+(rand()%m);}
                printf("%d",a);
            }
            printf("\n");
        }


    }
    return 0;
}


