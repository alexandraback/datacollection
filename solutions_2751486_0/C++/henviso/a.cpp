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
#define PI 3.14159265359

typedef unsigned long long ull;

typedef long long unsigned hash;

#define MAXN 1000010
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXN], m[MAXN];
char str[MAXN];
char mem[MAXN];
int n, t;

int val(char a){
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return 0;
	return 50;
}

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	m[0] = 0ULL;
	REP(j, MAXN){
		m[j+1] = m[j]*B + 50;
	}
}

void calc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	p[0] = 0ULL;
	REP(j, t){
		p[j+1] = p[j]*B + val(str[j]);
	}
}

void print(int a, int b){
	for(int i = a; i<=b; i++){
		printf("%c", str[i]);
	}
	printf("\n");
}

hash pre_dhash(int a, int b) {
	if (a > b) return 0;
	return m[b+1] - m[a] * power[b - a + 1];
}

hash dhash(int a, int b) {
	if (a > b) return 0;
	return p[b+1] - p[a] * power[b - a + 1];
}

int main(){
	int nc;
	precalc();
	scanf(" %d ", &nc);
	REP(ca, nc){
		scanf(" %s %d ", &str[0], &n);
		t = strlen(str);
		calc();
		hash val = m[n];
		ull ans = 0;
		ull last = -1;
		ull total = t-n+1;
		REP(i, t-n+1){
			ull frente = (ull) (((t-n) - i)+1);
			ull tras;
			//cout << "string ";
			//REPP(j, i, k+1) cout << str[j];
			//cout << endl;
			//cout << " HASH " << dhash(i, k) << " VAL " << val << endl;
			if(dhash(i, i+n-1) == val){
				//cout << " i " << i << " k " << k << endl;
				//cout << "DHASH DO K+1 " << dhash(i, k+1) << endl;
				//cout << "TOTAL EH " << total << endl;
				tras = i-(last+1)+1;
				//cout << " TRAS EH " << tras << " FRENTE EH " << frente <<endl;
				ans += tras * frente;
				last = i;
			}
		}
		printf("Case #%d: %llu\n", ca+1, ans);
	}
}
