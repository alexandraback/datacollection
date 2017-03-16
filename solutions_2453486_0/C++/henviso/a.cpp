#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = a; i>-1; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 2000000000
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

char b[10][10];

bool won(char x){
	REP(i, 4){
		int p = 0, t = 0;
		REP(j, 4){
			if(b[i][j] == x) p++;
			else if(b[i][j] == 'T') t++;
		}
		if(p == 4 || (t == 1 && p == 3)) return true;
	}
	REP(j, 4){
		int p = 0, t = 0;
		REP(i, 4){
			if(b[i][j] == x) p++;
			else if(b[i][j] == 'T') t++;
		}
		if(p == 4 || (t == 1 && p == 3)) return true;
	}
	int p = 0, t = 0;
	REP(i, 4){
		if(b[i][i] == x) p++;
		else if(b[i][i] == 'T') t++;
	}
	if(p == 4 || (t == 1 && p == 3)) return true;
	p = 0, t = 0;
	REP(i, 4){
		if(b[i][3-i] == x) p++;
		else if(b[i][3-i] == 'T') t++;
	}
	if(p == 4 || (t == 1 && p == 3)) return true;
	return false;
}

bool draw(){
	REP(i, 4)
	REP(j, 4) if(b[i][j] == '.') return false;
	return true;
}

int main(){
	int t;
	scanf(" %d ", &t);
	REP(ca, t){
		REP(i, 4) REP(j, 4) scanf(" %c ", &b[i][j]);
		if(won('X')) printf("Case #%d: X won\n", ca+1);
		else if(won('O')) printf("Case #%d: O won\n", ca+1);
		else if(draw()) printf("Case #%d: Draw\n", ca+1);  
		else printf("Case #%d: Game has not completed\n", ca+1);
	}
}
