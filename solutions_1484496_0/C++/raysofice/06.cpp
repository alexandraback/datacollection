#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


map<int,int> m;
pair<map<int,int>::iterator,bool> p;
int a[502],n;
bool x[502],y[502];

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int T,t,s,i,k,temp,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",a+i);
        m.clear();
        t=1<<n;
        printf("Case #%d:\n",cas);
        for(i=0; i<t; i++)
        {
            s=0;
            for(k=0; k<n; k++)
                if((1<<k)&i)
                    s+=a[k];
            p=m.insert(make_pair(s,i));
            if(!p.second)
            {
                temp=m[s];
                memset(x,0,sizeof(x));
                memset(y,0,sizeof(y));
                for(k=0; k<n; k++)
                    if((1<<k)&i)
                        x[k]=1;
                for(k=0; k<n; k++)
                    if((1<<k)&temp)
                        y[k]=1;
                for(k=0; k<n; k++)
                    if(x[k] &&!y[k])
                    {
                        printf("%d",a[k]);
                        break;
                    }
                k++;
                for(; k<n; k++)
                    if(x[k] && !y[k])
                        printf(" %d",a[k]);
                puts("");
                for(k=0; k<n; k++)
                    if(y[k] && !x[k])
                    {
                        printf("%d",a[k]);
                        break;
                    }
                k++;
                for(; k<n; k++)
                    if(y[k] && !x[k])
                        printf(" %d",a[k]);
                puts("");
                break;
            }
        }
    }
    return 0;
}
