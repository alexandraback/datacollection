#include<bits/stdc++.h>

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
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\C-small-attempt2.in","r",stdin)
#define WRITE freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 200009



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


//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

#define YES printf("GABRIEL\n")
#define NO printf("RICHARD\n")

int dp[1000];
bool vis[400];
int arr[100];
int D, C, V;

void solve(int mask, int sum)
{
    if(dp[mask] != -1) return;
    vis[sum] = 1;
    dp[mask] = 1;
    for(int i = 0; i < D; i++)
    {
        if(check_bit(mask, i) == 0)
        {
            solve(set_bit(mask, i), sum + arr[i]);
        }
    }
    return;
}


int power(int a, int b)
{
    int ret = 1;
    for(int i = 0; i < b; i++)
        ret = ret * a;
    return ret;
}

int main()
{
    READ;
    WRITE;
    int i, j, k;
    int num;
    int t,m,cases = 1;
    int x, n;

    scanf("%d", &t);
    string str;
    while(t--)
    {
        cin>>C>>D>>V;
        for(i = 0; i < D; i++)
        {
            cin>>arr[i];
        }
        clr(dp, -1);
        clr(vis, false);
        solve(0, 0);
        int cnt = 0;
        for(i = 1; i <= V; i++)
        {
            if(!vis[i])
            {
                //for(j = 0; j < 10; j++)
                {
                    //if(power(2, j) == i)
                    {
                        clr(dp, -1);
                        clr(vis, false);
                        arr[D] = i;
//                        cout<<i<<endl;
                        D++;
                        solve(0, 0);
                        cnt++;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", cases++, cnt);
    }



    return 0;
}

/*


1 5 30
1 5 9 10 14



*/
