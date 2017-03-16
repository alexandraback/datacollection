#include <iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define MAXN 1010
struct node
{
    int v1,v2,id;
    node(){}
    node(int a,int b,int c)
    {
        v1=a,v2=b,id=c;
    }
};
bool operator<(const node &a,const node &b)
{
    if(a.v1==b.v1)
    {
        if(a.v2==b.v2)
        {
            return a.id<b.id;
        }
        return a.v2<b.v2;
    }
    return a.v1>b.v1;
}
bool one[MAXN],two[MAXN];
int main()
{
//    freopen("in","r",stdin);
//    freopen("out","w",stdout);


    int t,ti;

    scanf("%d",&t);

    for(int ti=1;ti<=t;ti++)
    {
        int n;

        scanf("%d",&n);

        priority_queue<node> p1,p2;
        for(int i=0;i<n;i++)
        {
            int a,b;
            one[i]=0,two[i]=0;
            scanf("%d%d",&a,&b);
            p1.push(node(a,b,i));
            p2.push(node(b,a,i));
        }

        int res=0;
        int now=0;
        bool flag=false;
        while(!flag&&!p2.empty())
        {
//            cout<<"NOW "<<now<<endl;
            if(now>=p2.top().v1)
            {
                //可挑战该等级的2star
                if(one[p2.top().id])
                {//挑战过1等级
                    now++;
                }
                else
                {//未挑战过该等级
                    now+=2;
                }
                two[p2.top().id]=true;
//                cout<<"TWO "<<p2.top().id<<endl;
            }
            else if(!p1.empty()&&now>=p1.top().v1)
            {
                //可挑战该等级的1star
                now++;
                one[p1.top().id]=true;
//                cout<<"ONE "<<p1.top().id<<endl;
            }
            else
            {
                flag=true;
                break;
            }
            res++;
            while(!p2.empty()&&two[p2.top().id])p2.pop();
            while(!p1.empty()&&(one[p1.top().id]||two[p1.top().id]))p1.pop();
        }

        printf("Case #%d: ",ti);

        if(flag)
        {
            printf("Too Bad\n");
        }
        else
        {
            printf("%d\n",res);
        }
    }
    return 0;
}
