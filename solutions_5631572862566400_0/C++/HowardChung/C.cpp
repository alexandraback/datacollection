#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
    return a>b? a : b;
}

bool preCheck(const bool *has, const int *bff, int n)
{
    for(int i = 1; i <= n; i++)
    {
        if( has[i] && !has[ bff[i] ] )
            return false;
    }
    return true;
}

bool check(const vector<int> &p, const int *bff)
{
    int N = p.size();
    for(int i = 0; i < N; i++)
    {
        if( p[(i+1)%N] != bff[p[i]] && p[(i-1)%N] != bff[p[i]] )
            return false;
    }
    return true;
}

int solve(const vector<int> &p, const int *bff)
{
    /*for(int i = 0; i < p.size(); i++)
        printf("%d ",p[i]);
    puts("");*/
    if( !check(p,bff) )
        return -1;
    return p.size();
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("aout.txt","w",stdout);

    int T;
    scanf("%d",&T);

    for(int cases = 1; cases <= T; cases++)
    {
        int bff[1010];
        int ans = 0;

        int n;
        scanf("%d",&n);


        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d",&bff[i]);
        }

        for(int i = 0; i < (1<<n); i++)
        {
            vector<int> p;
            bool has[1010];
            memset(has,false,sizeof(has));

            for(int j = 0; j < n; j++)
            {
                if( (i&(1<<j)) != 0 )
                {
                    p.push_back(j+1);
                    has[j+1] = true;
                }
            }

            if( !preCheck(has,bff,n) )
                continue;

            sort(p.begin(),p.end());
            do
            {
                ans = max(ans,solve(p,bff));
            }while(next_permutation(p.begin(),p.end()));
        }

        printf("Case #%d: %d\n",cases,ans);
    }

    return 0;
}
