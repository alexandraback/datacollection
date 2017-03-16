#include <cstdio>
#include <algorithm>
using namespace std;
int calc(int s1,int t1,int s2,int t2)
{
    return((720LL-s1)*t1<=(360LL-s2)*t2);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int s1,t1,s2,t2;
        bool flag=false;
        if (n==2)
            scanf("%d%*d%d%d%*d%d",&s1,&t1,&s2,&t2);
        else
        {
            int k;
            scanf("%d%d%d",&s1,&k,&t1);
            if (k==1)
                flag=true;
            s2=s1,t2=t1+1;
        }
        if (t1>t2)
        {
            swap(s1,s2);
            swap(t1,t2);
        }
        static int id=0;
        printf("Case #%d: %d\n",++id,flag?0:calc(s1,t1,s2,t2));
    }
    return(0);
}

