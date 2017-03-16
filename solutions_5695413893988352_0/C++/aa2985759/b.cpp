#include<string.h>
#include<stdio.h>
#include<string>
#include<pthread.h>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include <queue>
#include <time.h>
#include <fcntl.h>

using namespace std;

int a[110][110];
int ans;
bool same;

void upd(int n)
{
    if (ans>=0&&ans!=n)
        same=false;
    else
        ans=n;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ii=1;ii<=t;ii++)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);

        same=true;
        ans=-1;
        for (int i=1;i<=n;i++)
        {
            int s=0;
            for (int j=1;j<=n;j++)
                s+=a[i][j];
            upd(s);

            s=0;
            for (int j=1;j<=n;j++)
                s+=a[j][i];
            upd(s);
        }
        int s=0;
        for (int i=1;i<=n;i++)
            s+=a[i][i];
        upd(s);
        s=0;
        for (int i=1;i<=n;i++)
            s+=a[n-i+1][i];
        upd(s);

        printf("Case #%d: %d\n", ii, same);
    }
}

