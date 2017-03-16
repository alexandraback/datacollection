#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<stack>
#include<string>
#include<vector>

#define pi 2*acos(-1)
#define SIZE 250
#define ROOT 100000

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, t=0, n, x, m;
    double num[SIZE], tot, p, p2, tot2;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        tot = 0.0;
        tot2 = 0.0;
        m = 0;
        for(int i=0; i<n; i++){
            scanf("%lf",&num[i]);
            tot += num[i];
        }
        p = tot;
        tot = (2.0*tot)/n;
        for(int i=0; i<n; i++){
            if(num[i]>tot){
                tot2 += num[i];
                 m++;
            }
        }
        p2 = (2.0*p-tot2)/(n-m);
        for(int i=0; i<n; i++){
            if(num[i]>tot) num[i] = 0.0;
            else{
                num[i] = ((p2-num[i])*100.0)/p;
            }
        }

        printf("Case #%d:",++t);
        for(int i=0; i<n; i++){
            printf(" %lf",num[i]);
        }
        printf("\n");


    }

    return 0;
}
