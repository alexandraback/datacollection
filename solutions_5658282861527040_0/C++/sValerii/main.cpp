/* 
 * File:   main.cpp
 * Author: sValerii
 *
 * Created on May 3, 2014, 7:10 PM
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define forr(i,a,b) for (int i=a; i<=b; i++)
#define ford(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define sqr(q) q*q
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

string st[120];
char s[120];
int main(int argc, char** argv) {
    freopen("b.txt","w",stdout);
    //freopen("b.in","r",stdin);
    int tnum;
    scanf("%d",&tnum);
    rep(tc,tnum) {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int ans=0;  
        rep(i,n) rep(j,m) 
            if ((i&j) < k) ans++;
        printf("Case #%d: %d\n",tc+1,ans);    
    }
    return 0;
}


