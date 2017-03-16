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

const int N = 55;
int ar[2*N][N];
int cnt[2505];
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
        printf("Case #%d: ",tc++);
        scanf("%d",&n);
        f(i,0,2505)
            cnt[i] = 0;
        f(i,0,2*n - 1)
            f(j,0,n)
                scanf("%d",&ar[i][j]);
        f(i,0,2*n - 1)
            f(j,0,n)
                cnt[ar[i][j]]++;
        f(i,0,2505)
            if(cnt[i]&1)
                printf("%d ",i);
        printf("\n");
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


