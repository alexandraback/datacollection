
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
#define eps 1e-9
#define gi(x) scanf("%d",&x)
//_____starts____here_______
int d[10],h[10],m[10];
int main()
{
    int t, kase=0;
    cin>>t;
    while(t--)
    {
        kase++;
        cout<<"Case #"<<kase<<": ";
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>d[i]>>h[i]>>m[i];

        int d1,d2,m1,m2;
        if(n==1 && h[0]==1)
        {
            cout<<"0\n";
            continue;
        }
        if(n==1)
        {
            d1 = d[0];
            d2 = d[0];
            m1 = m[0];
            m2 = m[0]+1;
        }
        if(n==2)
        {
            d1 = d[0];
            d2 = d[1];
            m1 = m[0];
            m2 = m[1];
        }

        if(d1>d2)
        {
            swap(d1,d2);
            swap(m1,m2);
        }

        if(m1==m2)
        {
            cout<<"0\n";
            continue;
        }

        long double s1 = 360.0/m1;
        long double s2 = 360.0/m2;
        if(m1>m2) // aage waala faster.
        {
            long double rel = s2-s1;
            long double ttm = (360-(d2-d1))/rel;
            long double ttc = (360-d1)/s1;

            if(ttc + eps < ttm)
            {
                cout<<"0\n";
                continue;
            }
            cout<<"1\n";
            continue;
        }

        // aage waala slower.
        long double rel  = s1-s2;
        long double t1 = (d2-d1)/rel;
        long double npos = d1+s1*t1;

        if(npos-eps>360.0)
        {
            cout<<"0\n";
            continue;
        }

        long double ttm = 360/rel;
        long double ttc = (360-npos)/s2;

        if(ttc+eps<ttm)
        {
            cout<<"0\n";
            continue;
        }
        cout<<"1\n";
    }

    return 0;
}


