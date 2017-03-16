#include<iostream>
#include<algorithm>
#include<cstdio>
#include<memory.h>
#include<map>
using namespace std;
using namespace std;
int ans[1005];
map<int,int> mymap;
bool tmp1[1005],tmp2[1005];
pair<map<int,int>::iterator,bool> iter;
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,n,num,sum,i,j,tmp;
    scanf("%d",&T);
    for(int icas=1;icas<=T;icas++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",ans+i);
        mymap.clear();
        num=1<<n;
        for(i=0;i<num;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
			{
                if((1<<j)&i)
                    sum+=ans[j];
			}
            iter=mymap.insert(make_pair(sum,i));
            if(!iter.second)
            {
                tmp=mymap[sum];
                memset(tmp1,0,sizeof(tmp1));
                memset(tmp2,0,sizeof(tmp2));
                for(j=0;j<n;j++)
                    if((1<<j)&i)
                        tmp1[j]=1;
                for(j=0;j<n;j++)
                    if((1<<j)&tmp)
                        tmp2[j]=1;
                printf("Case #%d:\n",icas);
                for(j=0;j<n;j++)
                    if(tmp1[j] && !tmp2[j])
                    {
                        printf("%d",ans[j]);
                        break;
                    }
                j++;
                for(;j<n;j++)
                    if(tmp1[j] && !tmp2[j])
                        printf(" %d",ans[j]);
                printf("\n");
                for(j=0;j<n;j++)
                    if(tmp2[j] && !tmp1[j])
                    {
                        printf("%d",ans[j]);
                        break;
                    }
                j++;
                for(;j<n;j++)
                    if(tmp2[j] && !tmp1[j])
                        printf(" %d",ans[j]);
                printf("\n");
                break;
            }
        }
    }
	return 0;
}

