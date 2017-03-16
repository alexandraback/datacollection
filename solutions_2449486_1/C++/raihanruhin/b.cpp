#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>

using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define KS printf("Case %d: ",kk++)

#define MOD 1000000007
#define MX 100010


int main()
{
    READ;
    WRITE;
    int tc,kk=1,n,m,arr[110][110],colmx[110],rowmx[110];
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          cin>>arr[i][j];

        CLR(colmx);
        CLR(rowmx);

        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
          rowmx[i]=max(rowmx[i],arr[i][j]);

        for(int j=0;j<m;j++)
         for(int i=0;i<n;i++)
          colmx[j]=max(colmx[j],arr[i][j]);

        bool chk=true;

        for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         {
             if(!chk) break;
             if(arr[i][j]!=rowmx[i] && arr[i][j]!=colmx[j])
              chk=false;
         }

        printf("Case #%d: ",kk++);
        if(chk) cout<<"YES";
        else cout<<"NO";
        printf("\n");
    }
    return 0;
}

