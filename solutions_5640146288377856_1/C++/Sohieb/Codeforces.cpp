//============================================================================
// Name        : Codeforces.cpp
// Author      : sohieb
// Version     :
// Copyright   : Your copyright notice (c)
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>
#include<ctype.h>
#include<iomanip>
#include<bitset>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>
#include<math.h>

using namespace std;

#define all(v)         v.begin(),v.end()
#define sz(v)        ((int)((v).size()))
#define psh(x)               push_back(x)
#define mk(x,y)           make_pair(x,y)
#define ck(a)               (a<1 || a>9)
#define lop(i,n)     for(ll i=0;i<n;i++)
#define loop(i,f,l)  for(ll i=f;i<l;i++)
#define read(s)   freopen(s, "r", stdin)
#define write(s) freopen(s, "w", stdout)
#define inf                   1000000000
#define pi             3.141592653589793

typedef string            ss;
typedef long long         ll;
typedef pair <int, int>   ii;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef pair<char, int>  chi;
typedef vector<ii>       vii;
typedef vector<int>       vi;
typedef vector<vi>       vvi;
typedef vector<string>    vs;
typedef vector<ll>       vll;
typedef vector<vii>     vvii;

const double eps = (1e-7);

#define nearestpoweroftwo(s) ((ll)pw(2.0, (ll)((log((long double)s) / log(2.0)) + 0.5)))
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return ((a*b) / gcd(a, b)); }
ll pw(ll b, ll p){ if (!p) return 1; ll sq = pw(b, p / 2); sq *= sq; if (p % 2) sq *= b; return sq; }
int sd(ll x){ return x<10 ? x : x % 10 + sd(x / 10); }
ll sq(ll x){ lop(i, x)if ((ll)i*i > x) return (i - 1); return ll(1); }
//read("input.txt");write("output.txt");
//#include <bits/stdc++.h>
//using namespace std;

int T,r,c,w;


int main()
{
	read("input.txt");write("output.txt");

	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&r);
		scanf("%d",&c);
		scanf("%d",&w);

		int ans=r*(c/w)+w-1;
		if(c%w) ans++;
		printf("Case #%d: %d\n",i,ans);
	}
}


