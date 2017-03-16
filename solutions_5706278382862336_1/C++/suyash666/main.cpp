#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)                              for (i=a;i<b;i++)
#define FORL(i,size)                            for (i=0;i<size;i++)
#define FORR(i,size)                            for (i=size-1;i>=0;i--)
#define s(n)                                    scanf("%d",&n)
#define p(n)                                    printf("%d\n",n)
#define ps(n)                                   printf("%s\n",n)
#define sd(n)                                   int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define mp(a,b)                                 make_pair(a,b)
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int> > > TG;
int i, j, k;

int main() {

    int T = 1;
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //T = g_fi.ReadNext();
    cin>>T;

    FOR(k, 1, T+1) {
        char ch;
        cout<<"Case #"<<k<<": ";
        ll p;
        ll q;
        cin>>p;
        cin>>ch;
        cin>>q;
        ll g = __gcd(p,q);
        p/=g;
        q/=g;
        if(q & (q-1))
        {
            cout<<"impossible"<<endl;
            continue;
        }
        int ans=1;
        ll r=1;
        while(1)
        {
            r<<=1;
            if(r*p>=q)
                break;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}