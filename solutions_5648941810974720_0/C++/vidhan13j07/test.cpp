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

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    clock_t tStart = clock();
    int tc = 1;
    string s;
    int c[26];
    string ss[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int ar[10];
    TC()
    {
        printf("Case #%d: ",tc++);
        f(i,0,10)
            ar[i] = 0;
        cin>>s;
        f(i,0,26)
            c[i] = 0;
        f(i,0,sc(s))
            c[s[i] - 'A']++;
        f(i,0,sc(s))
            if(s[i] == 'Z')
                ar[0]++;
            else if(s[i] == 'O')
                ar[1]++;
            else if(s[i] == 'W')
                ar[2]++;
            else if(s[i] == 'T')
                ar[3]++;
            else if(s[i] == 'U')
                ar[4]++;
            else if(s[i] == 'F')
                ar[5]++;
            else if(s[i] == 'X')
                ar[6]++;
            else if(s[i] == 'S')
                ar[7]++;
            else if(s[i] == 'G')
                ar[8]++;
            else if(s[i] == 'I')
                ar[9]++;
        ar[1] -= (ar[0] + ar[2] + ar[4]);
        ar[3] -= (ar[2] + ar[8]);
        ar[5] -= ar[4];
        ar[7] -= ar[6];
        ar[9] -= (ar[5] + ar[6] + ar[8]);
        string ans = "";
        f(i,0,10)
            while(ar[i] > 0)
            {
                ans += ('0' + i);
                f(j,0,sc(ss[i]))
                    c[ss[i][j] - 'A']--;
                ar[i]--;
            }
        f(i,0,26)
            if(c[i] != 0)
                printf("this : %c %d\n",'A' + i,i);
        cout<<ans<<endl;
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}


