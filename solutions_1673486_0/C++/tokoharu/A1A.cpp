 #include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MP make_pair

typedef long long LL;
typedef pair<int,int> PII;

int main() {
	int t,T;
	cin>>t;
	T = t;
	for(;t;t-- ) {
		int A,B;
		cin>>A>>B;
		int hoge = B+1;
		hoge += A*2;
		
		
		double Min =0;
		
		Min = B+2;
		
		
		double now = 1;
		for(; hoge>=B+1 ;hoge-=2) {
			
			double tmp = now * (double)hoge + (1-now) * (double)(hoge+B+1);
			tmp -= A;
	//		tmp++;
//			cout<<tmp<<endl;
			if(Min > tmp) Min = tmp;
			
			if(hoge!=B+1) {
				double p;
				cin>>p;
				now *= p;
				
			}
			
		}
		
		printf("Case #%d: %.10lf\n",T-t+1 , Min);
		
	}
	
	return 0;
	
}

