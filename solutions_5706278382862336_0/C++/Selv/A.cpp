#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define SORT(X) sort(X.begin(),X.end())
#define fi first
#define se second

char x;

int te;
void test(){
	int p=0,q=0;
	while(true){
		scanf("%c", &x);
		if(x == '/') break;
		p = p*10 + x-'0'; 
	}
	while(true){
		scanf("%c", &x);
		if(x == '\n') break;
		q = q*10 + x-'0'; 
	}
	int Q = __gcd(q,p);
	p = p/Q;
	q = q/Q;
	printf("Case #%d: ",++te);
	if(__builtin_popcount(q) != 1) {
		printf("impossible\n");
		return;
	}
	for(int i = 1; i <= 40; i++){
		if( (q>>i) <= p) {
			printf("%d\n",i);
			break;
		}
	}
}

int main () {
	int n;
	scanf("%d ",&n);
	while(n--){
		test();
	}
}

