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

int pd[1100];

bool palin(int x){
	int f[100], t = 0, a = x;
	while(x){
		f[t++] = x%10;
		x /= 10;
	}
	int mid = t/2;
	if(t%2){
		for(int i = 0; mid+i < t; i++) if(f[mid+i] != f[mid-i]) return false;
	}
	else{
		for(int i = 0; mid-(i+1) >= 0; i++) if(f[mid-(i+1)] != f[mid+i]) return false;
	}
	return true;
}

void solve(){
	CLEAR0(pd);
	
	int last = 0;
	for(int i = 1; i*i <= 1000; i++){
		while(last < i*i) pd[++last] = pd[last-1];
		if(palin(i) && palin(i*i)) pd[i*i]++;
	}
	while(last < 1001) pd[++last] = pd[last-1];
}

int ans(int a, int b){
	return pd[b]-pd[a-1];
}

int main(){
	solve();
	int t, a, b;
	scanf(" %d ", &t);
	REP(ca, t){
		scanf(" %d %d ", &a, &b);
		printf("Case #%d: %d\n", ca+1, ans(a,b));
	}
}
