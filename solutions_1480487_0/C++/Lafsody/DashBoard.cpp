#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int t,n,co;
double sum,etc,a[201],c[201],etc1,x;
struct node
{
    int num;
    double val;
    bool operator()(node x1,node y1)
    {
        return x1.val>y1.val;
    }
};

int main()
{
    int i,j,k;
    vector<node> b[51];
    node etcn;
    freopen("1.in","r",stdin);
    freopen("1.txt","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&n);
        co=n;
        for(j=0;j<n;j++)
        {
            scanf("%lf",&a[j]);
            etcn.val=a[j];
            etcn.num=j;
            b[i].push_back(etcn);
            sum+=b[i][j].val;
        }
        sort(b[i].begin(),b[i].end(),node());
        etc=sum*2;
        printf("Case #%d: ",i);
        for(j=0;j<n-1;j++)
        {
            if(b[i][j].val>=etc/co)
            {
                c[b[i][j].num]=0;
                etc-=b[i][j].val;
                co--;
            }
            else break;
        }
        for(;j<n;j++)
        {
            c[b[i][j].num]=(etc/co-b[i][j].val)/sum*100;
        }
        for(j=0;j<n;j++)
        {
            printf("%lf ",c[j]);
        }
        printf("\n");
    }
    
    scanf(" ");
    return 0;
}
