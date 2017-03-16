#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int V = 100;
const int INFI = 9999999;
int n;
int a[V];
int g[20 * 100000], f[20 * 100000];

int main()
{
    int test;
    scanf("%d",&test);
    
    for (int cas=1;cas<=test;cas++)
    {
        scanf("%d",&n);
        
        int sum = 0;
        for (int i=0;i<n;i++) 
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        //printf("sum = %d\n",sum);
        
        for (int i=0;i<=sum;i++) f[i] = INFI;
        f[0] = INFI+1;
        
        for (int i=0;i<=sum;i++) g[i] = f[i];
        
        
        for (int i = 0;i < n;i++) 
        {
            for (int s = 0;s <= sum-a[i];s++)
            if (f[s] != INFI)
            {
                if (g[s + a[i]] == INFI) g[s + a[i]] = i;
                if (s - a[i] >= 0 && (g[s - a[i]] == INFI || g[s - a[i]] == INFI+1)) g[s - a[i]] = i+n;
                //printf("%d f[%d] = %d %d %d\n",i, s, f[s], s+a[i], sum);
            }
            for (int s = 0;s <= sum;s++) f[s] = g[s];
            if (f[0] != INFI+1) break;
        }
        
        printf("Case #%d:\n",cas);
        if (f[0] == INFI + 1) 
        {
            printf("Impossible\n");
        }else
        {
            vector<int> s1;
            vector<int> s2;
            int x = 0;
            while (1)
            {
                int w = f[x];
                //printf("x is %d %d\n",x, w);
                if (w < n) 
                {
                    x -= a[w];
                    s1.push_back(a[w]);
                }
                else    
                {
                    x += a[w-n];
                    s2.push_back(a[w-n]);
                }
                if (x == 0) break;
            }
            
            for (int i=0;i<s1.size();i++) printf("%d ",s1[i]); puts("");
            for (int i=0;i<s2.size();i++) printf("%d ",s2[i]); puts("");
        }
    }
}
