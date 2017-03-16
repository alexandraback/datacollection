#include "iostream"
#include "queue"
using namespace std;
struct data
{
    int level;
    int enter;
    friend bool operator < (const data&a, const data&b)
    {
        return a.enter > b.enter;
    }
};

priority_queue<data> s2queue;

struct data2
{
    int enter1;
    int enter2;
};
data2 s1array[1001];
int earned[1001];
int main()
{
    int cas;
    freopen("B-small.in","r",stdin);
    freopen("B-small.out","w",stdout);
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    scanf("%d",&cas);
    int t = 0;
    while( t < cas)
    {
        int n;
        scanf("%d",&n);
        int i;
        while(!s2queue.empty()) s2queue.pop();
        for( i =0 ; i<n; i++)
        {
            int a, b;
            scanf("%d %d",&a,&b);
            data dt;
            s1array[i].enter1 = a;
            s1array[i].enter2 = b;
            dt.level = i;
            dt.enter = b;
            s2queue.push(dt);
        }
        int now = 0;
        int ct = 0;
        memset(&earned, 0, sizeof(earned));
        while(1)
        {
            if(!s2queue.empty())
            {
                data dt = s2queue.top();
                if( earned[dt.level] == 2 )
                {
                    s2queue.pop();
                    continue;
                }
                if( now >= dt.enter)
                {
                    if( earned[dt.level] == 1)
                    {
                        now += 1;
                        earned[dt.level] = 2;
                    }
                    else
                    {
                        now += 2;
                        earned[dt.level] = 2;
                    }
                    s2queue.pop();
                    ct++;
                    continue;
                }
            }
            int pos = -1;
            int mx = -1;
            for( i=0; i< n; i++)
            {
                if( earned[i] == 0)
                {
                    if( now >= s1array[i].enter1)
                    {
                        if( mx < s1array[i].enter2)
                        {
                            mx = s1array[i].enter2;
                            pos = i;
                        }
                    }
                }
            }
            if( pos == -1)
                break;
            earned[pos] = 1;
            now+=1;
            ct++;
        }
        if(now != n * 2)
        {
            printf("Case #%d: Too Bad\n",++t);
        }
        else
        {
            printf("Case #%d: %d\n",++t,ct);
        }
    }
}