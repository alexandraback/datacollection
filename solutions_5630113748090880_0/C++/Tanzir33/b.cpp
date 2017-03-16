#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define DBG         pf("Hi\n")
#define pf          printf
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define PI          acos(-1.00)
#define sz          size()
#define xx          first
#define yy          second
#define eps         1e-9

typedef long long int LL;
typedef double db;
int sltn[55][55], A[51+51][51], taken[51*51], n;
int call(int r)
{
    //if(r > n)
     //   return true;
    for(int i = 1; i<=2*n-1; i++)
    {
        if(!taken[i] && A[i][1] == sltn[1][r])
        {
            taken[i] = 1;
            for(int j = 1; j<=n; j++)
                sltn[j][r] = A[i][j];
            if(call(r+1))
                return true;
            taken[i] = 0;
        }
    }
    return false;
}
int main()
{
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
    int i, j, k, cs, t;
    sf(t);
    FRE(cs,1,t)
    {
        mem(sltn,0);
        sf(n);
        int cnt = 1;
        FRE(i,1,2*n-1)
        {
            FRE(j,1,n)
            sf(A[cnt][j]);
            cnt++;
        }
        int mn = 121321, nw;
        FRE(i,1,2*n-1)
        {
            if(A[i][1] < mn)
                mn = A[i][1], nw = i;
        }
        taken[nw] = 1;
        for(i = 1; i<=n; i++)
            sltn[1][i] = A[nw][i];
        call(1);
        /*for(i = 1; i<=n; i++)
        {
            for(j = 1; j<=n; j++)
                cout << sltn[i][j] <<  " " ;
            cout << endl;
        }*/
        mem(taken,0);
        int ans = -1;
        pf("Case #%d:",cs);
        FRE(i,1,n)
        {
            FRE(k,1,2*n-1)
            {
                if(!taken[k])
                {
                    int q;
                    for( q = 1; q<=n; q++)
                    {
                        if(A[k][q] != sltn[i][q])
                            break;
                    }
                    if(q > n)
                    {
                        taken[k] = 1;
                        break;
                    }
                }
            }
            if(k == 2*n)
            {
                ans = i;
                    for(int q = 1; q<=n; q++)
                            pf(" %d",sltn[i][q]);
                        break;
            }
        }
        FRE(i,1,n)
        {
            FRE(k,1,2*n-1)
            {
                if(!taken[k])
                {
                    int q;
                    for( q = 1; q<=n; q++)
                    {
                        if(A[k][q] != sltn[q][i])
                            break;
                    }
                    if(q > n)
                    {
                        taken[k] = 1;
                        break;
                    }
                }
            }
            if(k == 2*n)
            {
                ans = i;
                    for(int q = 1; q<=n; q++)
                            pf(" %d",sltn[q][i]);
                        break;
            }
        }
        puts("");
    }
        return 0;
}


