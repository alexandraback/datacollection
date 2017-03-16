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

int mi, ans1, ans2;
string p,q;
void cal(int ind1, int ind2, string a, string b, int len)
{
    if(ind1 == len and ind2 == len)
    {
        int y = atoi(a.c_str());
        int z = atoi(b.c_str());
        if(abs(y - z) < mi)
        {
            p = a;
            q = b;
            ans1 = y;
            ans2 = z;
            mi = abs(y - z);
        }
        else if(abs(y - z) == mi)
        {
            if(y < ans1)
            {
                p = a;
                q = b;
                ans1 = y;
                ans2 = z;
            }
            else if(y == ans1)
            {
                if(z < ans2)
                {
                    q = b;
                    ans2 = z;
                }
            }
        }
    }
    if(ind1 < len)
    {
        if(a[ind1] == '?')
            f(i,0,10)
            {
                a[ind1] = '0' + i;
                cal(ind1 + 1, ind2, a, b,len);
            }
        else
            cal(ind1 + 1, ind2, a, b, len);
    }
    if(ind2 < len)
    {
        if(b[ind2] == '?')
            f(i,0,10)
            {
                b[ind2] = '0' + i;
                cal(ind1, ind2 + 1, a, b,len);
            }
        else
            cal(ind1, ind2 + 1, a, b, len);
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
    #endif
    clock_t tStart = clock();
    int tc = 1, a, b;
    string c, j;
    int len;
    TC()
    {
        printf("Case #%d: ",tc++);
        cin>>c>>j;
        while(sc(c) < sc(j))
            c = "?" + c;
        while(sc(j) < sc(c))
            j = "?" + j;
        len = sc(j);
        p = a;
        q = b;
        mi = 1005;
        ans1 = 1005;
        ans2 = 1005;
        cal(0, 0, c, j, len);
        cout<<p<<" "<<q<<endl;
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


