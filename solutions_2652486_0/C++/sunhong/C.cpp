#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;

vector<int> res;    
int v[10];
int a[10];
int R,N,M,K;
class Record
{
public:
    int mask,value;
};
list<Record> queue;
bool used[10000];
bool exist[10000];

bool check()
{
    queue.clear();
    Record r,s,t;
    memset(used,false,sizeof(used));
    memset(exist,false,sizeof(exist));
    for (int i=0;i<N;i++)
    {
        r.mask=(1<<i);
        r.value=v[i];
        queue.push_back(r);
        used[r.mask]=true;
        exist[r.value]=true;
    }
    while (!queue.empty())
    {
        s=queue.front();
        //printf("s= %d %d\n",s.mask,s.value);
        queue.pop_front();
        for (int i=0;i<N;i++)
        {
            int tmp=(s.mask&(1<<i));
            if (tmp>0) continue;
            if (used[tmp]) continue;
            r.mask=s.mask+(1<<i);
            r.value=s.value*v[i];
            queue.push_back(r);
            used[r.mask]=true;
            exist[r.value]=true;
        }
    }
    for (int i=0;i<K;i++)
    {
        if (a[i]!=1 && !exist[a[i]]) return false;
    }
    return true;
}
void search(int depth)
{
    if (res.size()>0) return;
    if (depth>=N)
    {
        //for (int i=0;i<N;i++) printf("%d ",v[i]); printf("\n");
        if (check())
        {
            for (int i=0;i<N;i++) res.push_back(v[i]);
        }
        return;
    }
    for (int i=2;i<=M;i++)
    {
        v[depth]=i;
        search(depth+1);
    }
}
int main()
{
    int T;
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C_output_small.txt","w",stdout);
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%d%d%d%d",&R,&N,&M,&K);
        printf("Case #%d:\n",cases);
        for (int i=0;i<R;i++)
        {
            for (int j=0;j<K;j++)
            {
                scanf("%d",&a[j]);
            }
            res.clear();
            search(0);
            for (int i=0;i<res.size();i++) printf("%d",res[i]);
            printf("\n");
        }
    }
    return 0;
}
