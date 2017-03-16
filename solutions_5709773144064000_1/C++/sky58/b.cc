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
int ma[5][5];
int main()
{
	int t,a,fi,se;double c,f,x;
	cin>>t;
	rep(i,t){
		cin>>c>>f>>x;double ret=0.0,t=2.0;
		while(x/t>c/t+x/(t+f)){
			ret+=c/t;t+=f;
		}
		ret+=x/t;
		printf("Case #%d: %.12f\n",i+1,ret);
	}
}
