#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

// defines
#define ll long long int
#define REP(a,b) for(int (a)=0;a<(int)b;a++)
#define FOR(a,b,c) for(int (a)=b;a<(int)c;a++)
#define MP(A,B) make_pair(A,B)
#define PB push_back
#define S(a) scanf("%d",&a);
#define SCH(a) scanf("%s",a);
#define foreach(a,b) for(__typeof(b).begin() a  = b.begin(); a != b.end();a++)
#define debug(a) cout<<a<<endl;
#define INIT(a) memset(a,0,sizeof(a))

using namespace std;

long double p[100000];
long double prob[100000];
long double best =0;


int main(){
	int T;
	S(T);
	
	REP(t,T){
		int A, B;
		S(A);S(B);
		REP(n, A){
			scanf("%Lf",&p[n]);
		}
		
		// give up
		best = 1+B+1;
		
		prob[0] = p[0];
		for(int n=1;n<A;n++){
			prob[n]=prob[n-1]*p[n];
		}
		
		for(int n=0;n<A;n++){
			long double val = n+ (B-A+n+1)*prob[A-1-n]+(B-A+n+1+B+1)*(1.0-prob[A-1-n]);
			best = min(best,val);
		}
		
		printf("Case #%d: %.8Lf\n",t+1,best);
		
	}
}
