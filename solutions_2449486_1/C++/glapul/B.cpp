#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 107;
int a[MAXN][MAXN];
int col[MAXN], row[MAXN];

int main()
{
    int z;
    scanf("%d",&z);
    for(int zz=1;zz<=z;zz++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i =0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
            row[i]=-1;
        for(int i=0;i<m;i++)
            col[i]=-1;
        for(int i =0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                row[i] = max(row[i],a[i][j]);
                col[j] = max(col[j],a[i][j]);
            }
        bool res=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j] < col[j] && a[i][j] < row[i])
                    res=false;
        printf("Case #%d: ",zz);
        if(res)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
