/*
 * Author:  Troy
 * Created Time:  2012/4/28 10:05:51
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
#define Maxn 1110
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, now;
struct Level
{
    int a, b, goal;
}d[Maxn];


int gettwo(int sum)
{
    int mx = 0, ret = -1;
    REP(i, n)
    {
        if (d[i].goal != 2 && d[i].b <= sum) 
        {
            ret = i;
            return ret;
        }
    }
    return ret;
}
int getone(int sum)
{
    int ret = -1, mx = 0;
    REP(i, n)
        if (d[i].goal == 0 && d[i].a <= sum)
        {
            //cout <<d[i].a <<" "<<mx <<" "<<ret <<endl;
            if (d[i].b > mx)
            {
                ret = i;
                mx = d[i].b;
            }
        }
    return ret;
}

int main() 
{
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small-attempt0.out", "w", stdout);
    int T, ca = 0;
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        REP(i, n)
        {
            sf("%d%d", &d[i].a, &d[i].b);
            d[i].goal = 0;
        }
        now = 0;
        int ans = 0;
        while (now < 2 * n)
        {
            int p1 = gettwo(now);
            //cout <<p1 <<endl;
            if (p1 != -1)
            {
                now += (d[p1].goal == 1 ? 1 : 2);
                d[p1].goal = 2;       
                ans++;         
                continue;
            }            
            int p2 = getone(now);
            //cout <<p2 <<endl;
            if (p2 == -1) break;
            else
            {
                d[p2].goal = 1;
                now++;
                ans++;
                continue;
            }
        }
        if (now == 2 * n) pf("Case #%d: %d\n", ++ca, ans);
        else pf("Case #%d: Too Bad\n", ++ca);
    }
    return 0;
}

