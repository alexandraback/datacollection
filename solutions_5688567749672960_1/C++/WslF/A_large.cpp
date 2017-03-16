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

const int smallN= 100000000;
int dp[smallN+10];

LL pow_10[20];

LL rever(LL n)
{
    LL m= 0;
    LL n0= n;
    while (n>0)
    {
        m= m*10 + n%10;
        n/=10;
    }
    if (m<n0) return m;
    return n0-1;
}

LL solve(LL n)
{
    //LL n;
    //cin>>n;
    if (n<=smallN) return dp[n];

    if (n%10==0) return 1+solve(n-1);

    int l= 0;
    while (n>=pow_10[l]) l++;
    if (n%pow_10[(l+1)/2]==1) return 1+solve(rever(n));

    LL pw= pow_10[(l+1)/2];
    LL m= (n/pw)*pw+1;
    return n-m+solve(m);
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
 freopen("output_A_large.txt","w",stdout);
 //cout<<fixed;
 //cout<<setprecision(9);

 for (int i= 0; i<=10; i++)
    dp[i]= i;

 for (int i= 11; i<=smallN; i++)
 {
    dp[i]= min(dp[i-1],rev(i))+1;
  //  if (dp[i-1]>rev(i)) cout<<i<<endl;
 }

 pow_10[0]= 1;
 for (int i= 1; i<20; i++)
    pow_10[i]= pow_10[i-1]*10;

/*
 for (int i= 0; i<100000; i++)
 {

    cout.width(5);
    cout<<dp[i]<<" ";
    if (i%10==0) cout<<endl;

    if (i%100==0) cout<<endl;
 }
*/

 int numberOfTestCases;
 cin>>numberOfTestCases;
 for (int testCase= 1; testCase<=numberOfTestCases; testCase++)
 {
    cout<<"Case #"<<testCase<<": ";
    LL n;
    cin>>n;
    cout<<solve(n)<<endl;
 }

 return 0;
}


