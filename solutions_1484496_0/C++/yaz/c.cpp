#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <sstream>
#include <memory>
#include <complex>
using namespace std;

static const double EPS = 1e-5;
typedef long long ll;

#define FOR(i,a,b)	for(int i=(a);i<(int)(b);++i)
#define FORe(i,a,b)	for(int i=(a);i<=(int)(b);++i)
#define REP(i,b)	FOR(i,0,b)
#define REP1(i,b)	FORe(i,1,b)
#define ALL(c)		(c).begin(),(c).end()
#define LET(v,x)	typeof(x) v = x
#define FROMTO(it,b,e)	for(LET(it,(b));it!=(e);++it)
#define FOREACH(it,c)	FROMTO(it,(c).begin(),(c).end())

ll gcd(ll a, ll b){
	if (a && b) for(ll x; b; b = x){
		x = a % b;
		a = b;
	}
	return a;
}
ll gcd(ll a[], int n){
	return n > 0 ? accumulate(a + 1, a + n, a[0], (ll(*)(ll,ll))gcd) : 0LL;
}

ll lcm(ll a, ll b){
	return (a && b) ? a / gcd(a, b) * b : 0LL;
}
ll lcm(ll a[], int n){
	return n > 0 ? accumulate(a + 1, a + n, a[0], (ll(*)(ll,ll))lcm) : 0LL;
}

#define SCAN(p,f)	scanf("%" #f " ",p)
#define GET(t,x,f)	t x;SCAN(&x,f)
#define GETi(x)		GET(int,x,d)
#define GETl(x)		GET(ll,x,lld)
#define GETc(x)		GET(char,x,c)
#define GETf(x)		GET(float,x,f)
#define GETd(x)		GET(double,x,lf)


int summ(int arr[], int N, int key){
	int ret = 0;
	REP(i,N){
		if(key & (1 << i)) ret += arr[i];
	}
	return ret;
}
void printt(int arr[], int N, int key){
	char* s = "";
	REP(i,N){
		if(key & (1 << i)) {
			printf("%s%d", s, arr[i]);
		s = " ";
		}
	}
	printf("\n");
}

int main(){
	GETi(TTT);
	REP1(ttt, TTT){
		GETi(N);
		int arr[20] = {0};
		REP(i,N){
			GETi(S);
			arr[i]=S;
		}
		map<int, vector<int> > m;
		REP(i,1<<N){
			int s = summ(arr, N, i);
			LET(it,m.find(s));
			if(it == m.end()){
				m.insert(make_pair(s, vector<int>(1,i)));
			}else{
				it->second.push_back(i);
			}
		}
		printf("Case #%d:\n", ttt);
		bool ok = false;
		FOREACH(it,m){
			if(it->second.size() <= 1) continue;
			printt(arr, N, it->second[0]);
			printt(arr, N, it->second[1]);
			ok = true;
			break;
		}
		if(!ok){
			printf("Impossible\n");
		}
	}
	return 0;
}
