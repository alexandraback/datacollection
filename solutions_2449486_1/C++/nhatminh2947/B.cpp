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

int a[105][105],b[105][105];
int r[105],c[105];

int main()
{
    /*#ifndef ONLINE_JUDGE
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    #endif*/
    
    int tcs;
    read(tcs);
    int n,m;
    fr(t,1,tcs)
    {
        read2(n,m);
        
        fr(i,1,n) 
        {
            r[i] = 0;
            fr(j,1,m)
            {
                read(a[i][j]);
                r[i] = max(r[i],a[i][j]);
            }
        }
        
        fr(j,1,m)
        {
            c[j] = 0;
            fr(i,1,n) c[j] = max(c[j],a[i][j]);
        }
        
        bool YES = true;
        for(int i = 1 ; i <= n && YES ; i++)
            for(int j = 1 ; j <= m && YES ; j++)
                if(a[i][j] != min(r[i],c[j])) YES = false;
        printf("Case #%d: ",t);
        if(YES) puts("YES");
        else puts("NO");
    }

    return 0;
}