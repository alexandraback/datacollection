/*

jsrkrmciB

*/

#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define clear(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define Fora(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define output(x) cout << (x)
#define ST first
#define ND second
#define br printf("\n")
#define getnum(x) scanf("%d", &x);
#define GCJ(x,y)  printf("Case #%d: %d\n", x+1, y);
#define getline(x) 	scanf("\n%[^\n]",x);

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

const ld PI  = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

#define DEBUG

#ifdef DEBUG
#define debug(x) cout << #x << ":" << x << "\n";
#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#else
#define debug //
#define dprintf(fmt,...)
#endif

// Global Variable
int qq;
int start,end;

int intLength(int x){
	int len=1;
	while(x/10>0){
		x/=10;
		len++;
	}
	return len;
}

bool checkPalindrome(int x){
	char s[1000];
	sprintf(s,"%d",x);
	int len=intLength(x);    
	for(int i=0;i<len/2;i++)
		if(s[i]!=s[len-1-i])
			return false;
	return true;
}

int main() {
	freopen("C-small-attempt0.in", "rt", stdin); 
	freopen("output.out", "wt", stdout); 
	getnum(qq);
	fora(T,qq){
		int answer=0;
		getnum(start);
		getnum(end);
		for(int i=(int)sqrt(start);i*i<=end;i++){
			if(i*i<start)
				continue;
			if(checkPalindrome(i)&&checkPalindrome(i*i)){
				answer++;
				// cout << i << " " << i*i << endl;
			}
		}
		GCJ(T,answer);
	}
	return 0;
}