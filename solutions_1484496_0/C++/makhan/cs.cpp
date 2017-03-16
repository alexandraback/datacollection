#include <cstdio>
#include <algorithm>
using namespace std;
int s[21];
bool v[2000002];
int prev[2000002];
int sum;
int main()
{
    int t,n;
    scanf("%d",&t);
    for (int ti=1; ti<=t; ti++)
    {
        scanf("%d",&n);
        sum = 0;
        for (int i=0; i<n; i++)
        {
            scanf("%d",&s[i]);
            sum += s[i];
        }
        sort(s, s+n);
        for (int i=0; i<=sum; i++)
            v[i] = prev[i] = 0;
//        for (int i=0; i<n; i++)
//        {
//            v[s[i]] = 1;
//            prev[s[i]] = 0;
//        }
        printf("Case #%d:\n",ti);

        for (int i=0; i<n; i++)
            for (int j=0; j<=sum; j++)
                if ((v[j] == 1 && (j-prev[j]) != s[i]) || j == 0)
                {
                    if (v[j+s[i]])
                    {
                        printf("%d ",s[i]);
                        int x = j;
                        while(x > 0)
                        {
                            printf("%d ",x-prev[x]);
                            x=prev[x];
                        }
                        printf("\n");
                        x = j+s[i];
                        while(x > 0)
                        {
        
                            printf("%d ",x-prev[x]);
                            x=prev[x];
                        }
                        printf("\n");
                        goto zrobione;
                    }
                    else
                    {
                        v[j+s[i]] = 1;
                        prev[j+s[i]] = j;
                    }
                }
        printf("Impossible\n");
zrobione:;
    }
}
