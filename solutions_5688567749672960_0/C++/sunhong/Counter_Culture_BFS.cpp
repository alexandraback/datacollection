#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int reverse(int n)
{
    vector<int> v;
    while (n>0)
    {
        v.push_back((int)(n%10));
        n/=10;
    }
    int m=0;
    for (int i=0;i<v.size();i++)
    {
        m=10*m+v[i];
    }
    return m;
}
int step[1000001];
list<int> queue;

int main()
{    
    freopen("A-small-attempt1.in","r",stdin);
    freopen("_bfs_A_output_small.txt","w",stdout);
    int T,N;
    scanf("%d",&T);
    for (int index=1;index<=T;index++)
    {
        scanf("%d",&N);
        memset(step,0xff,sizeof(step));
        queue.clear();
        queue.push_back(1);
        step[1]=1;
        int result=(N==1)?1:-1;
        while (!queue.empty())
        {
            int u=queue.front();
            queue.pop_front();
            if (result>=0 && step[u]>=result) continue;
            for (int i=0;i<=1;i++)
            {
                int v=(i==0)?u+1:reverse(u);
                if (step[v]<0 || step[v]>step[u]+1)
                {
                    step[v]=step[u]+1;
                    queue.push_back(v);
                    if (v==N)
                    {
                        if (result<0 || result>step[v]) result=step[v];
                    }
                }
            }
        }
        printf("Case #%d: %d\n",index,result);
    }
    return 0;
}
