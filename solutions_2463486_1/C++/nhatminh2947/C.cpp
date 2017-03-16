//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
// Verdict: 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

ll a[100];

void init()
{
    a[0] = 1;
    a[1] = 4;
    a[2] = 9;
    a[3] = 121;
    a[4] = 484;
    a[5] = 10201;
    a[6] = 12321;
    a[7] = 14641;
    a[8] = 40804;
    a[9] = 44944;
    a[10] = 1002001;
    a[11] = 1234321;
    a[12] = 4008004;
    a[13] = 100020001;
    a[14] = 102030201;
    a[15] = 104060401;
    a[16] = 121242121;
    a[17] = 123454321;
    a[18] = 125686521;
    a[19] = 400080004;
    a[20] = 404090404;
    a[21] = 10000200001;
    a[22] = 10221412201;
    a[23] = 12102420121;
    a[24] = 12345654321;
    a[25] = 40000800004;
    a[26] = 1000002000001;
    a[27] = 1002003002001;
    a[28] = 1004006004001;
    a[29] = 1020304030201;
    a[30] = 1022325232201;
    a[31] = 1024348434201;
    a[32] = 1210024200121;
    a[33] = 1212225222121;
    a[34] = 1214428244121;
    a[35] = 1232346432321;
    a[36] = 1234567654321;
    a[37] = 4000008000004;
    a[38] = 4004009004004;
}

int main()
{
    init();
    
    int tcs;
    read(tcs);
    fr(t,1,tcs)
    {
        ll u,v;
        read2(u,v);
        
        int cnt = 0;
        rep(i,39) if(u <= a[i] && a[i] <= v) cnt++;
        
        printf("Case #%d: ",t);
        cout << cnt << endl;
    }

    return 0;
}