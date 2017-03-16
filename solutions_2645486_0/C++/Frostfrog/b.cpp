#include <cstdio>


using namespace std;
typedef unsigned long long int lld;


int E,R,N;
int vi[10];

lld dfs(int depth, int rest)
{
    if(depth==N)return 0;
    lld max=0;
    for(int i=0;i<=rest;i++)
    {
        lld now = i * vi[depth] + dfs(depth+1,rest-i+R > E ? E :rest-i+R);
        if(now > max) max = now;
    }
    return max;
}


int main()
{
    int T, cases = 0;
    scanf("%d", &T);
    while(T--)
    {


        scanf("%d%d%d",&E,&R,&N);
        for(int i =0 ; i<N;i++)
        {
            scanf("%d",&vi[i]);
        }
        lld out = dfs(0,E);
        printf("Case #%d: %lld\n",++cases, out);
    }


    return 0;
}
