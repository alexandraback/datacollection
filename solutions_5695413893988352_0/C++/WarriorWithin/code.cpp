/*****************************************************************************************/
/*																		     			 */
/*  					Adarsh Pugalia 										 			 */
/*																			 			 */
/*****************************************************************************************/
 
#include <bits/stdc++.h>

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

void init() {
}

bool check(int i, string j) {
	int n = j.length();
	int pos = n-1;
	while(n--) {
		int cur = i%10;
		if(j[pos]!='?' && ((j[pos]-'0')!=cur))
			return false;

		i /= 10;
		pos--;
	}

	return true;
}

void solve(int test_case) {
	init();
	cout<<"Case #"<<test_case<<": ";

	string x, y;

	cin>>x>>y;

	int min_dif = -1, C = -1, J = -1;
	int n = x.length();

	int last = 0;
	if(n==1) {
		last = 9;
	}
	else if(n==2) {
		last = 99;
	}
	else {
		last = 999;
	}

	rep(i,0,last) {
		rep(j,0,last) {
			if(check(i, x) && check(j,y)) {
				if(min_dif==-1 || min_dif>abs(i-j)) {
					min_dif = abs(i-j);
					C = i, J = j;
				}
				else if(min_dif==abs(i-j)) {
					if(C>i || (C==i && J>j)) {
						C = i, J = j;
					}
				}
			}
		}
	}

	n = x.length();
	string X = "", Y = "";
	while(n--) {
		X += ((C%10) + '0');
		C /= 10;
	}

	n = x.length();
	while(n--) {
		Y += ((J%10) + '0');
		J /= 10;
	}

	reverse(X.begin(), X.end());
	reverse(all(Y));
	cout<<X<<" "<<Y<<endl;
}

int main() {
	preprocess();
	int t = 1;
	sd(t);

	// cout<<check(1, "1?")<<endl;
	// return 0;
 
	rep(i,1,t) {
		solve(i);
	}
	return 0;
}
