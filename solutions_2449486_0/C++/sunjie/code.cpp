#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int mp[110][110],row[110],co[110];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=0;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        int n,m;
        scanf("%d%d",&n,&m);
        int i,j;
        for(i=0;i<n;i++)
        {
            row[i]=0;
            for(j=0;j<m;j++)
            {
                scanf("%d",&mp[i][j]);
                row[i]=max(row[i],mp[i][j]);
            }
        }
        for(i=0;i<m;i++)
        {
            co[i]=0;
            for(j=0;j<n;j++)
            {
                 co[i]=max(co[i],mp[j][i]);
            }
        }
        int flag=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mp[i][j]<row[i]&&mp[i][j]<co[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(flag)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }





    fclose(stdin);
    fclose(stdout);
    return 0;
}
