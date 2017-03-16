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
int num[2525];
int main()
{
	int t,n,a;
	cin>>t;
	rep(i,t){
		cin>>n;
		memset(num,0,sizeof(num));
		rep(j,2*n-1) rep(k,n){
			cin>>a;num[a]++;
		}
		printf("Case #%d:",i+1);
		rep(j,2510){
			if(num[j]%2>0) cout<<' '<<j;
		}
		cout<<endl;
	}
}
