/*****************************************************************************************/
/*																		     			 */
/*  					Adarsh Pugalia 										 			 */
/*																			 			 */
/*****************************************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <limits.h>


/* Data types and structures. */
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
/* Data structure helpers. */ 
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
#define has(it,s) if(it!=s.end())
 
/* Input output defines. */
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n) 
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define plf(n) printf("%0.9lf", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

/* constraints. */ 
#define max_size 100005
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)

#define bcnt __builtin_popcount 

ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
ll pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }
 
using namespace std;

void preprocess() {
}

ll ans = 0;
map<pii, ll> sp;
map<pii, ll> pj;
map<pii, ll> sj;
vector<int> v;

ll s, p, j, k;

void compute(ll ss, ll pp, ll jj) {
	map<pii, ll>::iterator it;
	it = sp.find(mp(ss, pp));
	if(it!=sp.end() && it->s==k)
		return;

	it = pj.find(mp(pp, jj));
	if(it!=pj.end() && it->s==k)
		return;

	it = sj.find(mp(ss, jj));
	if(it!=sj.end() && it->s==k)
		return;

	ans++;
	v.pb(jj); v.pb(pp); v.pb(ss);
	it = sp.find(mp(ss, pp));
	if(it==sp.end())
		sp[mp(ss, pp)] = 1;
	else
		it->s++;

	it = pj.find(mp(pp, jj));
	if(it==pj.end())
		pj[mp(pp, jj)] = 1;
	else
		it->s++;

	it = sj.find(mp(ss, jj));
	if(it==sj.end())
		sj[mp(ss, jj)] = 1;
	else
		it->s++;	
}

void jacket(ll ss, ll pp) {
	rep(i,1,j)
		compute(ss, pp, i);
}

void pant(ll ss) {
	rep(i,1,p)
		jacket(ss, i);
}

void shirt() {
	rep(i,1,s)
		pant(i);
}

void init() {
	sp.clear(); pj.clear(); sj.clear();
	ans = 0;
	v.clear();
}

void solve(int test_case) {
	init();
	cout<<"Case #"<<test_case<<": ";
	cin>>j>>p>>s>>k;
	shirt();
	cout<<ans<<endl;
	for(int i=0; i<v.size(); i+=3) {
		cout<<v[i]<<" "<<v[i+1]<<" "<<v[i+2]<<endl;
	}
	
}	

int main() {
	preprocess();
	int t = 1;
	sd(t);
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
