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

char checkrow(char mat[][4], int row){
	char buf='T';
	fora(i,4){
		if (mat[row][i]=='T')
			continue;
		if (mat[row][i]=='.')
			return 'T';
		else if (mat[row][i]!=buf&&buf!='T')
			return 'T';
		else
			buf=mat[row][i];
	}
	return buf;
}

char checkcol(char mat[][4], int col){
	char buf='T';
	fora(i,4){
		if (mat[i][col]=='T')
			continue;
		if (mat[i][col]=='.')
			return 'T';
		else if (mat[i][col]!=buf&&buf!='T')
			return 'T';
		else
			buf=mat[i][col];
	}
	return buf;
}

char checkldia(char mat[][4]){
	char buf='T';
	fora(i,4){
		if (mat[i][i]=='T')
			continue;
		if (mat[i][i]=='.')
			return 'T';
		else if (mat[i][i]!=buf&&buf!='T')
			return 'T';
		else
			buf=mat[i][i];
	}
	return buf;
}
char checkrdia(char mat[][4]){
	char buf='T';
	fora(i,4){
		if (mat[i][3-i]=='T')
			continue;
		if (mat[i][3-i]=='.')
			return 'T';
		else if (mat[i][3-i]!=buf&&buf!='T')
			return 'T';
		else
			buf=mat[i][3-i];
	}
	return buf;
}

bool checkEmpty(char mat[][4]){
	fora(i,4)
	fora(j,4)
	if(mat[i][j]=='.')
		return true;
	return false;
}

int main() {
	freopen("input.in", "rt", stdin); 
	freopen("output.out", "wt", stdout); 
	char mat[4][4];
	getnum(qq);
	fora(T,qq){
		char result ='T';

		fora(i,4){
			scanf("%s",mat[i]);
		}
		fora(i,4){
			result=checkrow(mat,i);
			if(result!='T'){break;}
			result=checkcol(mat,i);
			if(result!='T'){break;}
		}
		fora(i,1){
			if(result!='T'){break;}
			result=checkrdia(mat);
			if(result!='T'){break;}
			result=checkldia(mat);
		}
		if(result=='O'){
			printf("Case #%d: O won\n",T+1);
		}else if(result=='X'){
			printf("Case #%d: X won\n",T+1);
		}else{
			if(checkEmpty(mat)){
				printf("Case #%d: Game has not completed\n",T+1);
			}else{
				printf("Case #%d: Draw\n", T+1);
			}
		}
	}



	return 0;
}