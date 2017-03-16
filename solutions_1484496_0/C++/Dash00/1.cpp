#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<ctime>
using namespace std;
int a[505];
map<int,int> myset;
bool f1[505],f2[505];
pair<map<int,int>::iterator,bool> match;
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,n,num,sum,i,j,tmp,tt=0;
    scanf("%d",&t);
    while(t--)
    {
        tt++;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",a+i);
        myset.clear();
        num=1<<n;
        for(i=0;i<num;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
                if((1<<j)&i)
                    sum+=a[j];
            match=myset.insert(make_pair(sum,i));
            if(!match.second)
            {
                tmp=myset[sum];
                //cout<<i<<' '<<tmp<<' '<<sum<<endl;
                memset(f1,0,sizeof(f1));
                memset(f2,0,sizeof(f2));
                for(j=0;j<n;j++)
                    if((1<<j)&i)
                        f1[j]=1;
                for(j=0;j<n;j++)
                    if((1<<j)&tmp)
                        f2[j]=1;
                printf("Case #%d:\n",tt);
                for(j=0;j<n;j++)
                    if(f1[j] && !f2[j])
                    {
                        printf("%d",a[j]);
                        break;
                    }
                j++;
                for(;j<n;j++)
                    if(f1[j] && !f2[j])
                        printf(" %d",a[j]);
                puts("");
                for(j=0;j<n;j++)
				{
                    if(f2[j] && !f1[j])
                    {
                        printf("%d",a[j]);
                        break;
                    }
				}
                j++;
                for(;j<n;j++)
                    if(f2[j] && !f1[j])
                        printf(" %d",a[j]);
                puts("");
                break;
            }
        }
    }
	return 0;
}

