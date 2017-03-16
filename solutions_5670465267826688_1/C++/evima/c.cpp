// Enjoy your stay.

#include <bits/stdc++.h>

#define long long long
#define LOOPVAR_TYPE long

#define all(x) (x).begin(), (x).end()
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define sz(x) ((LOOPVAR_TYPE)(x).size())
#define foreach(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i, n) _rep2(i, 0, n)
#define _rep2(i, a, b) for(LOOPVAR_TYPE i = (LOOPVAR_TYPE)(a); i < (LOOPVAR_TYPE)(b); i++)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)

#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pb push_back

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long INF = 1070000000LL;
const long MOD = 1000000007LL;

using namespace std;

typedef istringstream iss;
typedef stringstream sst;
typedef pair<LOOPVAR_TYPE, LOOPVAR_TYPE> pi;
typedef vector<LOOPVAR_TYPE> vi;

#include <sys/time.h>
long getTime(){
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec * 1000000LL + t.tv_usec;
}

long L, X;
string s;

typedef tuple<int,int,int,int> qu;

const qu O = mt(1,0,0,0);
const qu I = mt(0,1,0,0);
const qu J = mt(0,0,1,0);
const qu K = mt(0,0,0,1);

qu mul(qu a, qu b){
	int a1 = get<0>(a);
	int ai = get<1>(a);
	int aj = get<2>(a);
	int ak = get<3>(a);
	int b1 = get<0>(b);
	int bi = get<1>(b);
	int bj = get<2>(b);
	int bk = get<3>(b);
	return mt(a1*b1-ai*bi-aj*bj-ak*bk, a1*bi+ai*b1+aj*bk-ak*bj,
		a1*bj-ai*bk+aj*b1+ak*bi, a1*bk+ai*bj-aj*bi+ak*b1);
}

void main2(){
	cin>>L>>X>>s;
	vector<qu> v;
	rep(i,L){
		if(s[i] == 'i') v.pb(I);
		if(s[i] == 'j') v.pb(J);
		if(s[i] == 'k') v.pb(K);
	}
	vector<qu> w;
	rep(t,min(8,X)){
		rep(i,L){
			w.pb(v[i]);
		}
	}
	int from = 0;
	qu q = O;
	while(from < sz(w) && q != I){
		q = mul(q, w[from++]);
	}
	q = O;
	int to = sz(w) - 1;
	while(to >= 0 && q != K){
		q = mul(w[to--], q);
	}
	if(from == sz(w) || to == -1 || from > to){
		cout<<"NO"<<endl;
		return;
	}
	//cout<<from<<" "<<to<<endl;

	q = O;
	if(from / L == to / L){
		rep(i,from,to+1){
			q = mul(q, w[i]);
		}
	}
	else{
		while(from % L != 0){
			q = mul(q, v[from++ % L]);
		}
		X -= from / L;
		qu qR = O;
		while((to+L) % L != L-1){
			qR = mul(v[to-- % L], qR);
		}
		X -= (sz(w) - 1 - to) / L;
		
		qu qM = O;
		rep(i,L){
			qM = mul(qM, v[i]);
		}
		rep(i,X%4){
			q = mul(q, qM);
		}
		q = mul(q, qR);
	}
	cout<<(q == J ? "YES" : "NO")<<endl;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		main2();
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
