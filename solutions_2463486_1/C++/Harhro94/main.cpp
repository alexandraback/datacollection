/*
 * File:     main.cpp
 * Author:   Hrayr [HarHro94]
 * Problem:  
 * IDE:      Visual C++ 2008
 */
//#pragma comment(linker, "/STACK:66777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <Vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define LL long long
#define LD long double

const int N = 10000007;
LL good[100];
int cnt;

bool check(LL n)
{
    int i, p=0, dig[20];
    while(n)
    {
        dig[p++]=n%10;
        n/=10;
    }
    for(i=0;i<p/2;++i)
    {
        if (dig[i]!=dig[p-i-1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
#ifdef harhro94
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int i;
    for(i=1;i<N;++i)
    {
        if (check(i))
        {
            if (check(1LL*i*i))
            {
                good[cnt++]=1LL*i*i;
            }
        }
    }
    /*
    cout << cnt << endl;
    for(i=0;i<cnt;++i)
    {
        cout << good[i] << " " << int(sqrt(good[i]+0.0)+1e-6) << endl;
    }
    */
    int test, testCnt;
    cin >> testCnt;
    for(test=1;test<=testCnt;++test)
    {
        LL a, b;
        int res=0;
        cin >> a >> b;
        for(i=0;i<cnt;++i)
        {
            if (good[i]>=a && good[i]<=b)
            {
                ++res;
            }
        }
        cout << "Case #" << test << ": " << res << endl;
    }

#ifdef harhro94
	cerr << fixed << setprecision(3) << "\nExecution time = " << clock()/1000.0 << "s\n";
#endif
	return 0;
}
