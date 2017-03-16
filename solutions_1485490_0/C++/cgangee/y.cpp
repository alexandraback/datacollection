#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;
#define ull unsigned long long;

const int N=100;

int i,j,k,m,n,l;
unsigned long long a[N+10][2], b[N+10][2];
unsigned long long f[N+10][N+10];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++)
	{
		scanf("%d%d", &n,&m);
		for (i=1; i<=n; i++)
			cin>>a[i][0]>>a[i][1];
		for (i=1; i<=m; i++)
            cin>>b[i][0]>>b[i][1];		  
		memset(f,0,sizeof(f));

        if (a[1][1]==a[2][1])
        {
            a[2][0]+=a[1][0];
            a[1][0]=0;
        }
        if (a[2][1]==a[3][1])
        {
            a[2][0]+=a[3][0];
            a[3][0]=0;
        }
        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
            {
                f[i][j]=f[i][j-1];
                if (a[i][1]==b[j][1])
                    f[i][j]+=b[j][0];
            }
        unsigned long long ans=0;
        for (i=0; i<=m; i++)
            for (j=i; j<=m; j++)
                ans=max(ans, min(a[1][0], f[1][i])+min(a[2][0],f[2][j]-f[2][i])+ min(a[3][0], f[3][m]-f[3][j]));

            
        if (n==3 && a[1][1]==a[3][1])
        {
            unsigned long long tmp=0;
            for (i=1; i<=m; i++) if (b[i][1]==a[1][1])
                tmp+=b[i][0];
            ans=max(ans, min(tmp, a[1][0]+a[3][0]));
        }
		printf("Case #%d: ",t);
		cout<<ans<<endl;
		
	}
	return 0;
}
