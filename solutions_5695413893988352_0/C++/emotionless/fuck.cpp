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
#define READ  freopen("B-small-attempt0 (1).in","r",stdin)

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
#define lim 200000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************


int con(string f)
{
    int ret = 0;
    int len = f.length();
    reverse(f.begin(), f.end());
    for(int i = len-1; i >= 0; i--)
    {
        ret = ret * 10 + (f[i] - '0');
    }
//    cout<<f<<" "<<ret<<endl;
    return ret;
}


int main()
{
    READ;
    WRITE;
    int  j, i, l;
    int N,  t;
    int m, cases = 1, k, n, num, u, v;
    string fst, snd;
    cin>>t;
    while(t--)
    {
        cin>>fst>>snd;
        int mn = 10000;
        string ra = "", rb = "";
        for(i = 0; i <= 9; i++)
        {
            for(j = 0; j <= 9; j++)
            {
                for(k = 0; k <= 9; k++)
                {
                    for(l = 0; l <= 9; l++)
                    {
                        for(m = 0; m <= 9; m++)
                        {
                            for(n = 0; n <= 9; n++)
                            {
                                string tmp = fst;
                                if(fst[0] == '?')
                                    tmp[0] =(char) (i+'0');
                                if(fst[1] == '?')
                                    tmp[1] =(char) (j+'0');
                                if(fst[2] == '?')
                                    tmp[2] =(char) (k+'0');
                                int a = con(tmp);
                                string as = tmp;

                                tmp = snd;
                                if(snd[0] == '?')
                                    tmp[0] =(char) (l+'0');
                                if(snd[1] == '?')
                                    tmp[1] =(char) (m+'0');
                                if(snd[2] == '?')
                                    tmp[2] =(char) (n+'0');
                                int b = con(tmp);
                                if(abs(a - b) < mn)
                                {
                                    mn = abs(a-b);
                                    ra = as;
                                    rb = tmp;
                                }
                                else if(abs(a-b) == mn && as < ra)
                                {
                                    ra = as;
                                    rb = tmp;
                                }
                                else if(abs(a-b) == mn && as == ra)
                                {
                                    rb = min(rb, tmp);
                                }
                            }
                        }

                    }
                }
            }
        }
        printf("Case #%d: ", cases++);
        cout<<ra<<" "<<rb<<endl;
    }





    return 0;
}
/*


1
5
A B
A C
B C
C A
A D

*/
