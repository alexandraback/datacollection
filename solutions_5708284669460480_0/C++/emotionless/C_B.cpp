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
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\uva 13-01-15\\codejam\\B-small-attempt0.in","r",stdin)
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

string str, tar;
int K, L, S;
vector<string>vec;
void DFS(int id, string st)
{
    if(id == S)
    {
        vec.pb(st);
        return;
    }
    for(int i = 0; i < K; i++)
        DFS(id + 1, st + str[i]);
    return;
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
    while(t--)
    {
        cin>>K>>L>>S;
        cin>>str;
        cin>>tar;

        vec.clear();
        DFS(0, "");
        int sz = vec.size();
        int cnt = 0, mx = 0;
        for(i = 0; i < sz; i++)
        {
            int pre = cnt;
            for(j = 0; j < S; j++)
            {

                for(k = 0; k < L; k++)
                {
                    if(vec[i][j + k] != tar[k])
                        break;
                }
                if(k == L)
                    cnt++;
            }
            mx = max(mx, cnt - pre);
        }
        printf("Case #%d: ", cases++);
        if(mx == 0)
        {
            printf("0.0000000000\n");
            continue;
        }
        double ans = (double)(cnt)/(double)sz;
        cout<<setprecision(10);
        cout<< (double)mx - ans<<endl;
//        printf("%.10lf\n", (double)mx - ans);
    }



    return 0;
}

/*


3
2 4
10 5
3 12
7 7 7
3 8
4 2 1



*/
