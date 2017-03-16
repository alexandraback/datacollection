
// Author : Vivek Hamirwasia (viv001)
#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define LET(x,a) __typeof(a) x(a)
#define MP make_pair
#define tr(container , it) for(LET(it,container.begin) ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >
#define MAX 1000000000
#define gi(x) scanf("%d",&x)
//_____starts____here_______
int A[3002];
int main()
{

    int t;
    cin>>t;
    int kase = 0;
    while(t--)
    {
        for(int i=0;i<=2000;i++)
            A[i] = 0;
        kase++;
        int D;
        cin>>D;
        for(int i=0;i<D;i++)
        {
            int p;
            cin>>p;
            A[p]++;
        }


        int ans = 10000;

        for(int i=1;i<=1000;i++)
        {
            int cur = 0;
            for(int j=i+1;j<=1000;j++)
            {
                int cuts = j/i;
                if(j%i==0) cuts--;
                cur += (cuts*A[j]);
            }
            ans = min(ans, cur+i);
        }

        printf("Case #%d: %d\n",kase,ans);
    }
    return 0;
}


