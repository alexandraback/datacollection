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

string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
// 0 2 6 8 3 7 5 4

int alpha[26];
int num[10];

void preprocess() {
}

void init() {
	rep(i,0,25)
		alpha[i] = 0;

	rep(i,0,9)
		num[i] = 0;
}

void solve(int test_case) {
	init();
	cout<<"Case #"<<test_case<<": ";

	string s;
	cin>>s;
	rep(i,0,s.length()-1) {
		alpha[s[i]-'A']++;
	}

	// 0
	int temp = alpha['Z'-'A'];
	num[0] += temp;

	rep(i,0,nums[0].length()-1)
		alpha[nums[0][i]-'A'] -= temp;

	// 2
	temp = alpha['W'-'A'];
	num[2] += temp;

	rep(i,0,nums[2].length()-1)
		alpha[nums[2][i]-'A'] -= temp;

	// 6
	temp = alpha['X'-'A'];
	num[6] += temp;

	rep(i,0,nums[6].length()-1)
		alpha[nums[6][i]-'A'] -= temp;

	// 8
	temp = alpha['G'-'A'];
	num[8] += temp;

	rep(i,0,nums[8].length()-1)
		alpha[nums[8][i]-'A'] -= temp;

	// 3
	temp = alpha['H'-'A'];
	num[3] += temp;

	rep(i,0,nums[3].length()-1)
		alpha[nums[3][i]-'A'] -= temp;

	// 7
	temp = alpha['S'-'A'];
	num[7] += temp;

	rep(i,0,nums[7].length()-1)
		alpha[nums[7][i]-'A'] -= temp;

	// 5
	temp = alpha['V'-'A'];
	num[5] += temp;

	rep(i,0,nums[5].length()-1)
		alpha[nums[5][i]-'A'] -= temp;

	// 4
	temp = alpha['U'-'A'];
	num[4] += temp;

	rep(i,0,nums[4].length()-1)
		alpha[nums[4][i]-'A'] -= temp;	

	// 1
	temp = alpha['O'-'A'];
	num[1] += temp;

	rep(i,0,nums[1].length()-1)
		alpha[nums[1][i]-'A'] -= temp;

	// 9
	temp = alpha['I'-'A'];
	num[9] += temp;

	rep(i,0,nums[9].length()-1)
		alpha[nums[9][i]-'A'] -= temp;			

	rep(i,0,9) {
		if(num[i]>0) {
			rep(j,1,num[i])
				cout<<i;
		}
	}

	cout<<endl;


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
