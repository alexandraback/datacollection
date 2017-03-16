#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct Data
{
    int a;
    int b;
}data[1002];

int IsCompleted[1002];

bool cmp1(const Data&a, const Data&b)
{
    if(a.b!=b.b)
        return a.b<b.b;
    return a.a<b.a;
}

int main()
{
    int t,result,n,now,rest,choose;
    scanf("%d",&t);
    for(int casenum=1;casenum<=t;casenum++)
    {
        scanf("%d",&n);
        memset(IsCompleted,0,sizeof(IsCompleted));
        result=now=0;
        rest=n;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&(data[i].a),&(data[i].b));
            //printf("%d %d\n",data[i].a,data[i].b);
            if(now>=data[i].b)
            {
                now+=2;
                result++;
                i--;
                n--;
                //printf("Hello: %d\n",result);
            }
        }
        rest=n;
        sort(data,data+n,cmp1);
        bool help=true,flag;
        while(help)
        {
            help=false;
            flag=true;
            while(flag)
            {
                flag=false;
                for(int i=0;i<n;i++)
                {
                    if(IsCompleted[i]!=2 && now>=data[i].b)
                    {
                        now+=2-IsCompleted[i];
                        //printf("world: %d\n",now);
                        IsCompleted[i]=2;
                        flag=help=true;
                        rest--;
                        result++;
                    }
                }
            }
            choose=-1;
            for(int i=0;i<n;i++)
            {
                if(IsCompleted[i]==0 && now>=data[i].a)
                {
                    if(choose==-1)
                        choose=i;
                    else
                    {
                        if(data[i].b>data[choose].b)
                            choose=i;
                    }

                }
            }
            if(choose!=-1)
            {
                now++;
                //printf("e...: %d\n",now);
                help=true;
                IsCompleted[choose]=1;
                result++;
            }
        }
        if(rest==0)
            printf("Case #%d: %d\n",casenum,result);
        else
            printf("Case #%d: Too Bad\n",casenum);
    }
    return 0;
}
