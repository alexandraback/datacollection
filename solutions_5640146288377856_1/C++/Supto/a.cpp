/* Supto
   Dept. Of CSE
   University Of Dhaka
*/
//#include<bits/stdc++.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define pb push_back
#define ins insert
#define ff first
#define ss second
#define ll long long int
#define sss stringstream
#define oss ostringstream
#define iss istringstream
#define llu long long unsigned

#define _sq(a) (a)*(a)
#define gcd(a,b)    __gcd(a,b)
#define lcm(a,b) ((a)*((b)/gcd(a,b)))
#define mem(a) memset(a, 0, sizeof(a))
#define _set(a) memset(a,-1,sizeof(a))
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define ctz(x) __builtin_ctz(x) //number of trailing zeroes in a digit
#define ctzl(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(n)
#define clzl(x) __builtin_clzll(x) //number of leading zeroes in a digit
//If Long Long (mask & (1LL << k))
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask ,k) (mask & (~(1<<k)))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

using namespace std;
#define pi acos(-1.0)
#define inf 1000000000
#define EPS 1e-9
#define MAX 30005
#define MAXL 15
//const ll mod = 1000003;
//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {-1,-1,-1,0,0,1,1,1};
//int dy[] = {-1,0,1,-1,1,-1,0,1};

int main()
{
    READ("A-large.in");
    WRITE("output.txt");
    //ios_base::sync_with_stdio(false);
    int ncase, tcase = 1, r, w, c;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%d %d %d", &r, &c, &w);
        if(w == 1) printf("Case #%d: %d\n", tcase++, r*c);
        else
        {
            int ans = 0;
            int tmp = c/w;
            ans += (r-1)*tmp;
            ans += (tmp-1);
            ans += w;
            if(c-(tmp*w) > 0) ans++;
            printf("Case #%d: %d\n", tcase++, ans);
        }
    }
    return 0;
}
