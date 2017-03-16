#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int a[505];
map<int,int> mymap;
bool bo1[505],bo2[505];
pair<map<int,int>::iterator,bool> p;
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,n,num,sum,i,j,tmp,tt=0;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",a+i);
        mymap.clear();
        num=1<<n;
        for(i=0;i<num;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
                if((1<<j)&i)
                    sum+=a[j];
            p=mymap.insert(make_pair(sum,i));
            if(!p.second)
            {
                tmp=mymap[sum];
                //cout<<i<<' '<<tmp<<' '<<sum<<endl;
                memset(bo1,0,sizeof(bo1));
                memset(bo2,0,sizeof(bo2));
                for(j=0;j<n;j++)
                    if((1<<j)&i)
                        bo1[j]=1;
                for(j=0;j<n;j++)
                    if((1<<j)&tmp)
                        bo2[j]=1;
                printf("Case #%d:\n",tt);
                for(j=0;j<n;j++)
                    if(bo1[j] && !bo2[j])
                    {
                        printf("%d",a[j]);
                        break;
                    }
                j++;
                for(;j<n;j++)
                    if(bo1[j] && !bo2[j])
                        printf(" %d",a[j]);
                puts("");
                for(j=0;j<n;j++)
                    if(bo2[j] && !bo1[j])
                    {
                        printf("%d",a[j]);
                        break;
                    }
                j++;
                for(;j<n;j++)
                    if(bo2[j] && !bo1[j])
                        printf(" %d",a[j]);
                puts("");
                break;
            }
        }
    }
	return 0;
}
