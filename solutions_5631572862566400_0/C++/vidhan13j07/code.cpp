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
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;

inline bool EQ(double a,double b) { return fabs(a - b) < 1e-9; }
inline void set_bit(int & n, int b) { n |= pw(b); }
inline void unset_bit(int & n, int b) { n &= ~pw(b); }

const int N = 1e3+5;
int ar[N], ans;
bool vis[N];
bool check(int n,int *pos)
{
    //if(ar[1] != pos[2] and ar[1] != pos[n])
      //  return 0;
    f(i,2,n - 1)
        if(ar[i] != pos[i - 1] and ar[i] != pos[i + 1])
            return 0;
    return 1;
}
int ff(int n, int *pos, bool *vis, int start)
{
    f(i,1,n + 1)
        if(!vis[i])
        {
            pos[start] = i;
            vis[i] = 1;
            if(start >= 3)
            {
                f(j,1,start + 1)
                    printf("%d ",pos[j]);
                printf("\n");
                if(check(start, pos))
                {
                    ff(n, pos, vis, start + 1);
                    if(ar[1] == pos[2] or ar[1] == pos[start])
                        ans = max(ans,start);
                }
            }
            else
                ff(n, pos, vis, start + 1);
            vis[i] = 0;
        }
}
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    clock_t tStart = clock();
    int tc = 1,n;
    TC()
    {
        //printf("Case #%d: ",tc++);
        printf("\n\n\n");
        scanf("%d",&n);
        f(i,1,n + 1)
        {
            scanf("%d",&ar[i]);
            vis[i] = 0;
        }
        int pos[n + 1];
        ans = 0;
        ff(n, pos, vis, 1);
        printf("%d\n",ans);
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


