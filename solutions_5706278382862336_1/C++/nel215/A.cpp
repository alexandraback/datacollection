#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

int solve(LL P, LL Q){
	int res = 0;
	if (P == 0)return res;
	while (P < Q){
		if (Q % 2LL == 1)return -1;
		res++;
		Q /= 2LL;
	}
	while (Q % 2LL == 0)Q /= 2LL;
	//cerr << P << " " << Q << endl;
	if (P%Q != 0)return -1;
	return res;
}

int main(){
	int T;
	scanf("%d", &T);
	REP(testCase, T){
		LL P, Q;
		scanf("%lld/%lld", &P, &Q);
		int res = solve(P, Q);
		printf("Case #%d: ", testCase+1);
		if (res == -1){
			printf("impossible\n");
		}
		else{
			printf("%d\n", res);
		}
	}
	return 0;
}