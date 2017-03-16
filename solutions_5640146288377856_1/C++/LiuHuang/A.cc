#include <bits/stdc++.h>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
const int N = 233;
const int inf = 0x3f3f3f3f;
typedef long long ll;
#define SZ(v) ((int)(v).size())
#define pb push_back
#define ALL(v) (v).begin(), (v).end()
#define Fill(a,b) memset(a,b,sizeof(a))
#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

int main()
{
    int re,ca=1;cin>>re;
    for(ca=1;ca<=re;ca++) {

        int a, b, c;
        cin>>a>>b>>c;
        int t = b / c;
        t = t * a;
        t += c - 1;
        if (b%c) t++;
        printf("Case #%d: ", ca );
        cout<<t<<endl;
    }
}
