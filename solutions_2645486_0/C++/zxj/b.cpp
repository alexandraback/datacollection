#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<list>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;


#define PB push_back
#define MP make_pair

int f[11][6];
int a[11];
int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
    int t,i,j;
    scanf("%d",&t);
    int n,e,r;
    int cas=0;
    while(t--)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(i=1;i<=n;i++)
          scanf("%d",&a[i]);
        memset(f,-1,sizeof(f));
        f[0][e]=0;
        for(i=1;i<=n;i++)
        {
            for(j=e;j>=1;j--)
            {
                if(f[i-1][j]!=-1)
                {
                    for(int k=0;k<=j;k++)
                    {
                        int d = j-k+r;
                        if(d>e)d=e;
                        f[i][d]= max(f[i][d],f[i-1][j]+k*a[i]);
                    }
                }
            }
        }
        int M =0;
        for(i=1;i<=e;i++)
          M = max(M,f[n][i]);
          printf("Case #%d: ",++cas);
        cout<<M<<endl;
    }
}
