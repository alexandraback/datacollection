#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstdio>
#include<string.h>
#include<set>
#include<map>
using namespace std;

typedef long long Int;
#define FOR(i,a,b)  for(int i=(a);i<=(b);++i)
#define sz(s) (int)(s).size()
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)
void assert(bool x){if(!x)throw -1;}
const int inf = 1000000000;
const int MOD = 1000000007;
const double PI = acos(-1.0);


Int solve(Int r,Int t){
	Int low=0,high=min(t/(2*r),2000000000LL);
	while(low<high){
		Int mid = 1+(low+high)/2;

		Int now = mid*2*r+mid*(2*mid-1);

		if(now<=t)low=mid;else
			high=mid-1;
	}
	return high;
}

int main()
{
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int tests;scanf("%d\n",&tests);
	FOR(test,1,tests){
		Int r,t;cin>>r>>t;
		Int ans = solve(r,t);
		cout<<"Case #"<<test<<": ";
		cout<<ans<<endl;
	}
}