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
double nao[1100],ken[1100];
int main()
{
	int t,n;
	cin>>t;
	rep(i,t){
		cin>>n;
		rep(j,n) cin>>nao[j];
		rep(j,n) cin>>ken[j];
		sort(nao,nao+n);sort(ken,ken+n);
		int r1=0,r2=0;
		rep(j,n){
			if(ken[r1]<nao[j]) r1++;
			if(nao[r2]<ken[j]) r2++;
		}
		printf("Case #%d: %d %d\n",i+1,r1,n-r2);
	}
}
