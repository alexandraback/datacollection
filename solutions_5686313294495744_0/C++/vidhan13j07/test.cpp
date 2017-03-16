#include<bits/stdc++.h>
#define sc(v) v.size()
#define eb push_back
#define pb pop_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define TC() int t;cin>>t;while(t--)
#define all(x) x.begin(),x.end()
#define mk make_pair
#define fi first
#define se second
#define endl "\n"
#define eps 1e-9
#define pw(x) (1ll<<(x))
#define trace1(x)                cout <<#x<<": "<<x<<endl;
#define trace2(x, y)             cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<string,string> pi;
typedef pair<ll,ll> pll;

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    clock_t tStart = clock();
    int tc = 1;
    int n;
    map< pi,int > mp;
    vector< pi > v;
    set< pi > vv;
    vector<string> f,rr;
    string x,y;
    set<string> a,b;
    TC()
    {
        printf("Case #%d: ", tc++);
        mp.clear();
        v.clear();
        a.clear();
        b.clear();
        scanf("%d",&n);
        f(i,0,n)
        {
            cin>>x>>y;
            v.eb(mk(x,y));
            mp[mk(x,y)] = 1;
        }
        int ans = 0;
        f(i,0,1 << n)
        {
            f.clear();
            rr.clear();
            vv.clear();
            int c = 0;
            f(j,0,n)
                if(i&(1 << j))
                {
                    f.eb(v[j].fi);
                    rr.eb(v[j].se);
                    vv.insert(v[j]);
                }
            f(j,0,sc(f))
                f(k,0,sc(rr))
                {
                    if(vv.find(mk(f[j],rr[k])) != vv.end())
                        continue;
                    if(mp[mk(f[j],rr[k])])
                        c++;
                }
            ans = max(ans,c);
        }
        printf("%d\n",ans);
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


