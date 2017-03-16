#include<memory.h>
#include<cstdio>
#include<map>
using namespace std;
int a[505];
void ma(int a)
{
    return;
}
map<int,int> xxmap;
void min(int a)
{
    return;
}
bool xx[505],yy[505];
void max(int a)
{
    return;
}
pair<map<int,int>::iterator,bool> p;
int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("xx.out","w",stdout);
    int t,n,numm,summ,i,j,key,tyu=0;
    scanf("%d",&t);
    while(t--)
    {
        tyu++;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",a+i);
        xxmap.clear();
        numm=1<<n;
        for(i=0; i<numm; i++)
        {
            summ=0;
            for(j=0; j<n; j++)
                if((1<<j)&i)
                    summ+=a[j];
            p=xxmap.insert(make_pair(summ,i));
            if(!p.second)
            {
                key=xxmap[summ];
                memset(xx,0,sizeof(xx));
                memset(yy,0,sizeof(yy));
                for(j=0; j<n; j++)
                    if((1<<j)&i)
                        xx[j]=1;
                for(j=0; j<n; j++)
                    if((1<<j)&key)
                        yy[j]=1;
                printf("Case #%d:\n",tyu);
                for(j=0; j<n; j++)
                    if(xx[j] && !yy[j])
                    {
                        printf("%d",a[j]);
                        break;
                    }
                j++;
                for(; j<n; j++)
                    if(xx[j] && !yy[j])
                        printf(" %d",a[j]);
                printf("\n");
                for(j=0; j<n; j++)
                    if(yy[j] && !xx[j])
                    {
                        printf("%d",a[j]);
                        break;
                    }
                j++;
                for(; j<n; j++)
                    if(yy[j] && !xx[j])
                        printf(" %d",a[j]);
                printf("\n");
                break;
            }
        }
        if(i==numm)
            printf("Case #%d:\nImpossible\n",tyu);
    }
    return 0;
}
