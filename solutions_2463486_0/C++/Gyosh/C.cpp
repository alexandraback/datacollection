#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <map>

#define REP(a,b) for (int a=0; a<b; a++)
#define FOR(a,b,c) for (int a=b; a<=c; a++)
#define FORD(a,b,c) for (int a=b; a>=c; a--)
#define RESET(a,b) memset(a, b, sizeof a)

#define INF 1023123123
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PII pair<int,int> 
#define PDD pair<double,double>

#define __ puts("")

using namespace std;

int nkasus;
vector<LL> lis;
LL a,b;
char sc[500];

bool isPalin(LL x){
	sprintf(sc, "%lld", x);
	int le = strlen(sc);
	
	REP(i,le>>1){
		if (sc[i] != sc[le-i-1]) return 0;
	}
	return 1;
}

int main(){
	FOR(i,1,10000000){
		if (isPalin(i) && isPalin((LL)i*i)){
			lis.PB((LL)i*i);
		}
	}
	
	/*
	REP(i,lis.size()){
		printf("%lld\n", lis[i]);
	}
	*/
	
	scanf("%d", &nkasus);
	REP(jt,nkasus){
		scanf("%lld%lld", &a, &b);
		
		printf("Case #%d: %d\n", jt+1, upper_bound(lis.begin(), lis.end(), b) - upper_bound(lis.begin(), lis.end(), a-1));
	}
	return 0;
}
