#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;scanf("%d",&test);
    for (int t=1;t<=test;t++)
    {
        int n,m,k;scanf("%d%d%d",&k,&n,&m);
        if (n>m) swap(n,m);
        if (n*m%k) {printf("Case #%d: RICHARD\n",t);continue;}
        if (k==3&&n==1) {printf("Case #%d: RICHARD\n",t);continue;}
        if (k==4&&(n<3||m<4)) {printf("Case #%d: RICHARD\n",t);continue;}
        printf("Case #%d: GABRIEL\n",t);
    }
    return 0;
}
