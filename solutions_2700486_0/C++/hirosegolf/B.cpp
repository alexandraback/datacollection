#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>
#include <sys/time.h>
#include <fstream>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define REP(i,n)  FOR(i,0,n)
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define deb(x) cerr << #x << " = " << (x) << " , ";
#define debl cerr << " (L" << __LINE__ << ")"<< endl;


#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back
#define INRANGE(x,s,e) ((s)<=(x) && (x)<(e))
#define MP(x,y) make_pair((x),(y))

double pi=3.14159265358979323846;

using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

template<typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& z){
	os << "[ ";
	REP(i,z.size())os << z[i] << ", " ;
	return ( os << "]" << endl);
}

template<typename T> std::ostream& operator<<(std::ostream& os, const set<T>& z){
	os << "set( ";
	EACH(p,z)os << (*p) << ", " ;
	return ( os << ")" << endl);
}

template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
	os << "{ ";
	EACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
	return ( os << "}" << endl);
}

template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
	return ( os << "(" << z.first << ", " << z.second << ",)" );
}

double get_time(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + tv.tv_usec*1e-6;
}

typedef unsigned int uint32_t;
struct RND{
	uint32_t x;
	uint32_t y;
	uint32_t z;
	uint32_t w;
	RND(){
		x=123456789;
		y=362436069;
		z=521288629;
		w=88675123;
	}
	void init(int seed){
		x=123456789;
		y=362436069;
		z=521288629;
		w=seed+100;
		REP(i,10)get();
	}
	uint32_t get(){
		uint32_t t;
		t=x^(x<<11);
		x=y;y=z;z=w;
		w=(w^(w>>19))^(t^(t>>8));
		return w;
	}
};
RND rnd;

ll N,X,Y;
ll L;
ll rem;

const int ML=2010;
double memo[ML][ML];

double rec(ll p0, ll p1){
    double &ret = memo[p0][p1];
    if(ret>=-0.5) return ret;
    if(p0+p1==rem){
        return ret = 1.0*(p1>=Y+1);
    }
    if(p0==L-1)return ret=rec(p0,p1+1);
    if(p1==L-1)return ret=rec(p0+1,p1);
    
    return ret=0.5*rec(p0+1,p1)+0.5*rec(p0,p1+1);
}

double cal(){
    ll m=0;
    int dn=0;
    while(true){
        ll v=1+4*m;
        if(dn+v<N){
            dn+=v;
            m+=1;
        }
        else break;
    }
    X=abs(X);
    ll tm=(X+Y)/2;
    
    L=2*m+1;
    rem = N-dn;
    deb(N);deb(X);deb(Y);deb(rem);deb(m);deb(L);debl;
    
    if(tm<m)return 1.0;
    if(tm>m)return 0.0;
    
    assert(rem<=2*L+1);
    rep(p0,ML) rep(p1,ML){
        memo[p0][p1]=-1.0;
    }
    return rec(0,0);
}

void _main(istream &inp){
	int T;
	inp >> T >>ws;
	REP(tt,T){
		cout << "Case #" << tt+1 << ": ";
        inp >> N >> X >> Y;
		printf("%.16f\n", cal());
	}
    
}

int main(){
	if(0){
		ifstream ifs("test.txt");
		_main(ifs);
	}
	else{
		_main(cin);
	}
	return 0;
}