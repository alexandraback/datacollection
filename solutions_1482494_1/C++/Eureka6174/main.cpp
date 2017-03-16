//#include "debug.h"
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
const double pi=acos(-1.0);//NOTES:pi
typedef long long i64;
typedef unsigned long long u64;
const int intmax=0x3f3f3f3f;//NOTES:intmax
//const i64 i64max=0x3f3f3f3f3f3f3f3fi64;//NOTES:i64max
double eps=1e-6;//NOTES:eps
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//NOTES:checkmin(
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//NOTES:checkmax(
template<class T> inline T sqr(T x){return x*x;}//NOTES:sqr
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}//NOTES:lowbit(
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}//NOTES:countbit(
template<class T> inline T checkmod(T n,T m) {return (n%m+m)%m;}//NOTES:checkMod(
inline int rand(int a, int b) {if(a >= b) return a; return rand() % (b-a) + a;}//NOTES:rand(
//Numberic Functions
template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> inline T euclid(T a,T b,T &x,T &y)//NOTES:euclide(
{if(a<0){T d=euclid(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclid(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclid(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
{if(n<=1)return false;for (T i=2;i*i<=n;i++) if (n%i==0) return false;return true;}
template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{vector<pair<T,int> > R=factorize(n);T r=n;for (int i=0;i<R.size();i++)r=r/R[i].first*(R[i].first-1);return r;}
template<class T> inline int dblcmp(T a, T b){a-=b; return a>eps?1:(a<-eps?-1:0);}//NOTES:doublecmp
#define mem(a, val) memset(a, val, sizeof(a))//memset(
#define For(i, a, b) for(int i=a; i<b; ++i)//for
#define ff(i, b) for(int i=0; i<b; ++i)

struct Node{
    int x, p;
    bool operator < (const Node & b)const
    {
        return x < b.x;
    }
};

Node s1[1100], s2[1100];
int table[1100];
int mat[1100];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cases;
    scanf("%d", &cases);
    for(int I=1; I<=cases; ++I)
    {
        int n;
        scanf("%d", &n);
        ff(i, n){
            scanf("%d%d", &s1[i].x, &s2[i].x);
            s1[i].p = s2[i].p = i;
        }
        sort(s1, s1+n);
        sort(s2, s2+n);
        ff(i, n){
            mat[s2[i].p] = i;
        }
        mem(table, 0);
        int cur = 0;
        int ans = 0;
        int p1 = 0, p2 = 0;
        priority_queue<int> Q;
        while(1)
        {
            while(p2<n && table[s2[p2].p]==2)
            {
                p2 ++;
            }
            if(p2 == n) break;
            if(s2[p2].x <= cur)
            {
                cur += 2 - table[s2[p2].p];
                table[s2[p2].p] = 2;
                ans ++;
                //printf("%d\n", s2[p2].p);
            }
            else
            {
                while(p1<n && s1[p1].x <= cur)
                {
                    if(table[s1[p1].p] == 0)
                    {
                        Q.push(mat[s1[p1].p]);
                    }
                    p1 ++;
                }
                int a = -1;
                while(!Q.empty())
                {
                    int b = Q.top();
                    if(table[s2[Q.top()].p] == 0)
                    {
                        a = Q.top();
                        break;
                    }
                    Q.pop();
                }
                if(a == -1) break;
                a = s2[a].p;
                table[a] = 1;
                cur ++;
                ans ++;
                //printf("%d\n", a);
            }
        }
        printf("Case #%d: ", I);
        if(p2 < n)
        {
            puts("Too Bad");
        }
        else{
            printf("%d\n", ans);
        }
    }
    return 0;
}
