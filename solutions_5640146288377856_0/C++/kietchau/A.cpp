//==================================================================
//Author        : Nguyen Trung Hieu - vuondenthanhcong11@gmail.com
//Problem Name  :
//Discription   :
//Reference from:
//==================================================================

// -------------------- include all libraries ------------------
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

// -------------------- Redefine container ---------------------
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;

typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned uint;

// -------------------- Redefine some operator ------------------
#define forn(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rforn(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define reset(a,b)      memset((a),(b),sizeof(a))
#define fi              first
#define se              second
#define pb              push_back
#define all(x)          (x).begin(),(x).end()
#define mp(x,y)         make_pair(x,x)
#define foreach(i, c)   for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define debug(x) 	    {cerr<<#x<<" = "<<x<< endl;}
#define debugArr(a,x,y)	{cerr<<#a<<" = ";forn(_,x,y) cerr << a[_] << ' '; cerr <<endl;}

// ===================== Begin template =========================
// --------------------- Quick input output ---------------------
int in(){int x=0,c;for(;(unsigned long long)((c=getchar())-'0')>= 10;){if(c=='-')return -in();if(!~c)throw~0;}do{x=(x<<3)+(x<<1)+(c-'0');}while((unsigned long long)((c=getchar())-'0')<10);return x;}
long long in64(){long long x=0,c;for(;(unsigned long long)((c=getchar())-'0')>=10;){if(c=='-')return -in();if(!~c)throw~0;}do{x=(x<<3)+(x<<1)+(c-'0');}while((unsigned long long)((c=getchar())-'0')<10);return x;}
void out(int n){char buf[33];int i=30;if(n<0)putchar('-'),n=-n;do{buf[i--]='0'+n%10;n/=10;}while(n);while(i<30)putchar(buf[++i]);}
void out64(long long n){char buf[55];int i=50;if(n<0)putchar('-'),n=-n;do{buf[i--]='0'+n%10;n/=10;}while(n);while(i<50)putchar(buf[++i]);}

void readArray(int array1[],int len){for(int i=0;i<len;i++){array1[i]=in();}}
void read2Array(int array1[],int array2[],int len){for(int i=0;i<len;i++){array1[i]=in();array2[i]=in();}}

// ===================== End template ===========================

// --------------------- Start code ------------------------------
void solve(int r,int c, int w){

}
int solve1(int c,int w){
    return c/w+(c%w!=0)+w-1;
}
int main() {
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("A-small-attempt0.txt", "w", stdout);
	int testCase=in();
	forn(test,0,testCase){
	    int r=in(); int c=in(); int w=in();
        printf("Case #%d: %d\n",test+1,solve1(c,w));
	}
}
