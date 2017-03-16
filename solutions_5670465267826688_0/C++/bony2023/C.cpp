// Author : Bony Roopchandani
// 

// INCLUDES
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// MACROS
#define all(a) a.begin(), a.end()
#define bg begin()
#define en end()
#define ff first
#define in(a) freopen(a, "r", stdin)
#define ll long long
#define mp make_pair
#define nl printf("\n")
#define out(a) freopen(a, "w", stdout)
#define pb push_back
#define pf(a) printf("%d ",a)
#define pfi(a) printf("%d\n",a)
#define pfl(a) printf("%lld\n",(ll)a)
#define pfs(a) printf("%s\n",a)
#define rep(i, n) for(int i=0; i<n; i++)
#define repd(i, a, b) for(int i=a; i>=b; i--)
#define repl(i, n) for(ll i=0; i<n; i++)
#define repld(i, a, b) for(ll i=a; i>=b; i--)
#define replt(i, a, b) for(ll i=a; i<=b; i++)
#define rept(i, a, b) for(int i=a; i<=b; i++)
#define sfi(a) scanf("%d",&a)
#define sfl(a) scanf("%lld",&a)
#define sfs(a) scanf("%s",a)
#define ss second
#define sz size()

// CONSTS
const double EPS = (1e-11);
const double PI = acos(-1.0);
const int INF = 9999999;
const int MOD = (1e9 + 7);

// TYPEDEFS
typedef list < int > LI;
typedef list < ll > LLL;
typedef map < int, bool > MIB;
typedef map < int, int > MII;
typedef map < int, ll > MIL;
typedef map < ll, int > MLI;
typedef pair < int, int > PII;
typedef pair < int, PII > PIII;
typedef pair < int, PIII > PIIII;
typedef pair < int, ll > PIL;
typedef pair < ll, int > PLI;
typedef set < int > SI;
typedef set < ll > SLL;
typedef vector < int > VI;
typedef vector < ll > VLL;
typedef vector < string > VS;

int S[300][300], a[300][300];

void init() {
	S['1']['1']=1, a['1']['1']='1';
	S['1']['i']=1, a['1']['i']='i';
	S['1']['j']=1, a['1']['j']='j';
	S['1']['k']=1, a['1']['k']='k';
	
	S['i']['1']=1, a['i']['1']='i';
	S['i']['i']=-1, a['i']['i']='1';
	S['i']['j']=1, a['i']['j']='k';
	S['i']['k']=-1, a['i']['k']='j';
	
	S['j']['1']=1, a['j']['1']='j';
	S['j']['i']=-1, a['j']['i']='k';
	S['j']['j']=-1, a['j']['j']='1';
	S['j']['k']=1, a['j']['k']='i';
	
	S['k']['1']=1, a['k']['1']='k';
	S['k']['i']=1, a['k']['i']='j';
	S['k']['j']=-1, a['k']['j']='i';
	S['k']['k']=-1, a['k']['k']='1';
}

int main(void) {
	in("C-small.in");
	out("C-small.out");
	init();
	int T, cs=1; sfi(T);
	while(T--) {
		int n, po, sign=1; sfi(n), sfi(po);
		string s, ss; cin>>s;
		rep(i, po) {
			ss+=s;
		}
		bool i=0, j=0, k=0;
		char curr=ss[0];
		printf("Case #%d: ", cs++);
		rept(I, 1, ss.sz) {
			if(not i and curr=='i' and sign==1) {
				i=true;
				curr='1';
			}
			else if(not j and curr=='j' and sign==1 and i) {
				j=true;
				curr='1';
			}
			else if(not k and curr=='k' and sign==1 and i and j) {
				k=true;
				curr='1';
			}
			if(I<ss.sz) {
				sign*=S[curr][ss[I]];
				curr=a[curr][ss[I]];
			}
		}
		if(i and j and k and curr=='1' and sign==1) 
			puts("YES");
		else
			puts("NO");
	}
	return (0);
}