//solution by Wsl_F
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <cassert>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <complex>
#include <utility>
#include <climits>
#include <cctype>
#include <x86intrin.h>



using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

LL dig[20];

LL getLower(LL n)
{
    int sz= 0;
    while (n>0)
    {
        dig[sz++]= n%10;
        n/= 10;
    }
    int i= sz-1;
    int j= 0;
    bool f= 1;
    LL m= 0;
    while (i>=0)
    {
        if (dig[i]<dig[j]) f= 0;
        if (f) m= m*10+min(dig[i],dig[j]);
        else m= m*10+dig[i];
        i--; j++;
    }
    return m;
}

int dp[1000010];

void solve()
{
    LL n;
    cin>>n;
//    LL ans= 0;
    cout<<dp[n]<<endl;
}

const int inf= 10000100;
int rev(int n)
{
    if (n%10==0) return inf;
    int n0= n;
    int m= 0;
    while (n>0)
    {
        m= m*10 + n%10;
        n/=10;
    }
    if (m<n0) return dp[m];
    else return inf;
}

int main()
{
 ios_base::sync_with_stdio(0);
 //cin.tie(0);
 srand(__rdtsc());
 // LL a[110];
 // memset(a,0,sizeof(a));

 freopen("input.in","r",stdin);
 freopen("output.txt","w",stdout);
 //cout<<fixed;
 //cout<<setprecision(9);

 for (int i= 0; i<=10; i++)
    dp[i]= i;

 for (int i= 11; i<=1000000; i++)
 {
    dp[i]= min(dp[i-1],rev(i))+1;
 }

/*
 for (int i= 0; i<30; i++)
 {
    cout<<dp[i]<<" ";
    if (!i%10) cout<<endl;
 }
*/
 int numberOfTestCases;
 cin>>numberOfTestCases;
 for (int testCase= 1; testCase<=numberOfTestCases; testCase++)
 {
    cout<<"Case #"<<testCase<<": ";
    solve();
 }

 return 0;
}


