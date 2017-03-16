#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int tc_, n, s[205];
double S, lo, hi, md;

int doit(double d, int id){
	double v = s[id] + S * d, use = d;
	FOR(i,0,n)
	if (i != id && s[i] < v) use += (v - s[i]) / S;
	return use >= 1 - 1e-12;
}

int main(){
	scanf("%d", &tc_);
	FOE(tc,1,tc_){
		scanf("%d", &n);
		S = 0;
		FOR(i,0,n) scanf("%d", &s[i]), S += s[i];
		
		printf("Case #%d:", tc);
		FOR(i,0,n){
			lo = 0;
			hi = 1;
			FOR(itr,0,400){
				md = (lo + hi) / 2;
				if (doit(md, i)) hi = md;
				else lo = md;
			}
			printf(" %.9f", (lo + hi) * 50);
		}
		puts("");
	}
	return 0;
}
