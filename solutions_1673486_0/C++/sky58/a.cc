#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int main()
{
	int i,j,t,a,b;
	cin>>t;
	rep(i,t){
		cin>>a>>b;double ret=2.0+b,pro=1.0,d;
		//cout<<a<<' '<<b<<endl;
		rep(j,a){
			//scanf("%f",&d);
			cin>>d;
			pro*=d;//cout<<d<<endl;
			ret<?=a-j-1+b-j+(1.0-pro)*(b+1);
		}
		printf("Case #%d: %.8f\n",i+1,ret);
	}
	return 0;
}
