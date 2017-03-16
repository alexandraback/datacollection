#include<bits/stdc++.h>

#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
#define set_bit(a, b) (a|(1ll<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("A-large.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
//#define MAX (lim+7)
#define INF 100000000
#define PI acos(-1.0)

using namespace std;

///******* Template ********///

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 100000007
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

int val[1000];


int main()
{
    READ;
    WRITE;
    int  j, i;
    int N,  t;
    int m, cases = 1, k, n, num, u, v;
    cin>>t;
    string str;
    vector<int>ans;
    string tmp[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    while(t--)
    {
        ans.clear();
        clr(val, 0);
        cin>>str;
        int len = str.length();
        for(i = 0; i < len; i++)
            val[ str[i] ]++;
        int id = 0;
        while(val['Z'])
        {
            for(i = 0; i < 4; i++)
                val[ tmp[0][i] ]--;
            ans.pb(0);
        }

        while(val['W'])
        {
            for(i = 0; i < 3; i++)
                val[ tmp[2][i] ]--;
            ans.pb(2);
        }


        while(val['X'])
        {
            for(i = 0; i < 3; i++)
                val[ tmp[6][i] ]--;
            ans.pb(6);
        }

        while(val['G'])
        {
            for(i = 0; i < 5; i++)
                val[ tmp[8][i] ]--;
            ans.pb(8);
        }

        while(val['S'])
        {
            for(i = 0; i < 5; i++)
                val[ tmp[7][i] ]--;
            ans.pb(7);
        }

        while(val['H'])
        {
            for(i = 0; i < 5; i++)
                val[ tmp[3][i] ]--;
            ans.pb(3);
        }

        while(val['R'])
        {
            for(i = 0; i < 4; i++)
                val[ tmp[4][i] ]--;
            ans.pb(4);
        }


        while(val['F'])
        {
            for(i = 0; i < 4; i++)
                val[ tmp[5][i] ]--;
            ans.pb(5);
        }

        while(val['O'])
        {
            for(i = 0; i < 3; i++)
                val[ tmp[1][i] ]--;
            ans.pb(1);
        }

        while(val['I'])
        {
            for(i = 0; i < 4; i++)
                val[ tmp[9][i] ]--;
            ans.pb(9);
        }
        printf("Case #%d: ", cases++);
        sort(ans.begin(), ans.end());
        for(i = 0; i < ans.size(); i++)
        {
            cout<<ans[i];
        }
        printf("\n");


    }







    return 0;
}
/*

THREEFNVESIXSWOREVENOUZEROOEIGHTNINEETFI

*/
