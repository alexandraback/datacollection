#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 100010;
const int M = 55;
const int K = 200010;
const int LIT = 2500;
const int INF = 1 << 30;
const int ABS(int x) {while(x < 0) x = -x; return x;}

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int a, b;
vd p, pp;
double ac;

void init()
{
    p = vd(a); pp = vd(a);
    ac = 1.0;
    for(int i = 0; i < a; i++) 
    {
        scanf("%lf", &p[i]);
        ac *= p[i];
        pp[i] = ac;
    }
}

void solve(int tcase)
{
    double res = b + 2.0;
    //option 3, cancel (1) + retype (b) + enter (1)
    double r2 = ac * (b - a + 1) + (1.0 - ac) * (2 * b - a + 2);
    //option 1, type remain and enter(b - a + 1)
        //if wrong, with p = 1 - ac, retype (b + 1)
        //if all correct, with p = ac, done
    res = min(res, r2);
    
    for(int i = 0; i < a; i++)
    {
        double p1 = pp[i], p2 = 1.0 - pp[i];
        double key1 = b + a - 2 * i - 1.0;
        double key2 = key1 + b + 1;
        double r = key1 * p1 + key2 * p2;
        
    //option 2, back to position i (a - i - 1), and retype (a - i - 1),
    //type the remain and enter (b - a + 1)
        //if wrong in [0, i], with p = 1 - pp[i], retype (b + 1)
        //if correct, with p = pp[i], done
    
        
        res = min(res, r);
    }
    
    printf("Case #%d: %.7lf\n", tcase, res);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T, tcase = 1;
    cin>>T;
    
    while(cin>>a>>b)
    {
        init();
        solve(tcase++);
    }
    
    //while(1);
}
