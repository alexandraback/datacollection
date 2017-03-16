#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int cas(0);
struct node
{
    int pot;
    int ind;
    double prb;
};
node jg[205];

bool cmp(node a, node b)
{
    return a.pot>b.pot;
}
bool cmp2(node a, node b)
{
    return a.ind<b.ind;
}

int main()
{
    int t(0);
    int i(0),j(0),k(0);
    double res(0.0),sc,sum;
    freopen("test.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d", &n);
        res = 0;
        for(i=0; i<n; ++i)
        {
            scanf("%d", &jg[i].pot);
            jg[i].ind = i;
            res += jg[i].pot;
            //cout<<pot[i]<<"  ";
        }
        sum = res;
        sort(jg,jg+n,cmp);
        printf("Case #%d:",++cas);
        for(i=0; i+1<n; ++i)
        {
            if(jg[i].pot<=(res+sum-jg[i].pot)/(n-i-1))
            {
                break;
            }
            else
            {
                jg[i].prb = 0;
                res -= jg[i].pot;
            }
        }
        k = n-i;
        for(; i<n; ++i)
        {
            jg[i].prb = 100*(res+sum-k*jg[i].pot)/sum/k;
        }
        sort(jg, jg+n,cmp2);
        for(i=0; i<n; ++i)
        {
            printf(" %0.6lf",jg[i].prb);
            //else printf(" 0.0000000");
        }
        printf("\n");
    }
    return 0;

}


