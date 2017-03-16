#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <map>
#define pb push_back
#define MAXN 100001
#define MAXM 1
#define INF (1<<30)
#define PI 3.1415926535898
#define esp 10e-6
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
using namespace std;

double a[MAXN];

class Point
{
      public:
             int x;
             int y;
};

int work()
{
    int A,B;
    scanf("%d%d",&A,&B);
    for (int i=1;i<=A;++i)
        scanf("%lf",&a[i]);
    double ans=2+B;
    double All_true=1;
    for (int i=A;i>0;--i)
        {
        double Del=0;
        Del+=All_true*(2*i+(B-A)+1);
        Del+=(1-All_true)*(B+1+2*i+(B-A)+1);
        All_true*=a[A-i+1];
        if (Del<ans) ans=Del;
        }    
    //if (Del/A<ans) ans=Del/A;
    //All_true*=a[A];
    if ((B-A+1)*All_true+(1-All_true)*(B-A+1+B+1)<ans)
       ans=((B-A+1)*All_true+(1-All_true)*(B-A+1+B+1));
    printf("%lf\n",ans);
    return 0;
}

int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int i=1;i<=T;++i)
        {
        printf("Case #%d: ",i);
        work();
        }
    return 0;
}
