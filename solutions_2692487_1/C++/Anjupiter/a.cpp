/// @file
/// @brief	문제: 
///	해결법 : 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<cassert>
#include<cctype>
using namespace std;

#define rep(i,n)	for(int (i)=0;(i)<(n);(i)++)
#define repd(i,n)	for(int (i)=(n)-1;(i)>=0;(i)--)
#define REP(i,n) for (int (i)=0,_n=(n); (i) < _n; (i)++)
#define FOR(i,a,b) for (int _b=(b), (i)=(a); (i) <= _b; (i)++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))

#define CLEAR(x) memset((x),0,sizeof(x));
#define CLEARA(x) memset(&(x),0,sizeof(x));
#define FILL(x,v) memset((x),(v),sizeof(x));
#define FILLA(x,v) memset(&(x),(v),sizeof(x));

//c++ 0x
#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define rFOREACH(it,c) for(auto it=(c).rbegin();it!=(c).rend();++it)

#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 0x7fffffff
#define X first
#define Y second
#define pb push_back
#define SZ(c) (int)(c).size()
#define MP make_pair
//const double pi = acos(-1.0);
#define EPS 1e-9

#define PII pair<int,int> 
#define VI vector<int>
#define LL long long
template<typename T> inline T		gcd(T a, T b){if(a>b)swap(a,b);while(a!=0){b%=a;swap(a,b);}return b;}
template<typename T> inline T		lcm(T a, T b){return a/gcd(a,b)*b;}
//int pow(int a,int b){int c=1;while(b--)c*=a;return c;}

int a,n;
int mote[100];

int solve(int curMote,int pos){
	if(pos<n){
		//Just Eat
		if(curMote>mote[pos]){
			return solve(curMote+mote[pos],pos+1);
		}else{
			//Add Aid mote
			int op_a=0;
			{
				int gap=mote[pos]-curMote+1;//Bigger than mote
				int mote_a=curMote;
				while(mote_a<=mote[pos]){
					op_a++;
					mote_a+=mote_a-1;
				}
				op_a+=solve(mote_a+mote[pos],pos+1);
			}
			//Just remove
			int op_b=solve(curMote,pos+1)+1;
			return min(op_a,op_b);
		}
	}
	return 0;
}


//#define PROB   "D:\\Projects\\codejam\\A-small-attempt1"
#define PROB   "D:\\Projects\\codejam\\A-large"

int main(){
	freopen(PROB ".in","r",stdin);
	freopen(PROB ".out1","w",stdout);

	int T;scanf("%d",&T);
	FOR(t,1,T){
		scanf("%d %d",&a,&n);
		rep(i,n)scanf("%d",&mote[i]);
		sort(mote,mote+n);

		int res;
		if(a==1)res=n;
		else res=solve(a,0);
		if(res>n)res=n;

		fprintf(stderr,"Case #%d: %d\n",t,res);
		printf("Case #%d: %d\n",t,res);
	}
	fclose(stdout);
	return 0;
}