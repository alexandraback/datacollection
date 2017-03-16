#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)
int mx,ME,a[15],N;

void gain(int i,int E,int R,int x)
{
    if(i==N)
        mx=max(mx,x);
    else
    {
        for(int j=0;j<=E;j++)
            gain(i+1,min(E-j+R,ME),R,x+a[i]*j);
    }

}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int tc,t=1,i,E,R;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&E,&R,&N);
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        mx=0;
        ME=E;
        gain(0,E,R,0);
        printf("Case #%d: %d\n",t++,mx);
    }
    return 0;
}
