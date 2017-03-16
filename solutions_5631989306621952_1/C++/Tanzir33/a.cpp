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
string s;
int main()
{
     freopen("in.txt","r",stdin);
     freopen("out.txt","w",stdout);
    int i, j, k, cs, t;
    sf(t);
    FRE(cs,1,t)
    {
        cin >> s;
        string sltn = "";
        sltn += s[0];
        for(i = 1; i<s.sz; i++)
        {
            if(s[i] >= sltn[0])
                sltn = (s[i]) + sltn;
            else
                sltn += s[i];
        }
        pf("Case #%d: ",cs);
        cout << sltn << '\n';
    }
    return 0;
}

