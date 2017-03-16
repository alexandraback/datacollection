#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int a[1919];
int main()
{
	int n,t;
	//dp[0]=0;dp[1]=1;REP(i,2,1024) dp[i]=min(dp[i-1],dp[(i+1)/2])+1;
	cin>>t;
	rep(i,t){
		cin>>n;int ret=114514;
		rep(j,n){
			cin>>a[j];
		}
		REP(j,1,1001){
			int sum=0;
			rep(k,n) sum+=(a[k]-1)/j;
			ret=min(ret,j+sum);
		}
		printf("Case #%d: %d\n",i+1,ret);
	}
}
