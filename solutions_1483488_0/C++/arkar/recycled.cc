#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <complex>
#include <stack>
#include <cctype>
#include "assert.h"
#include <cstdlib>
#include <iostream>

#define PB push_back
#define MP make_pair
#define FR(i,n) for( long long i = 0; i < n; i ++ )
#define FOR(i,a,n) for(long long i = a; i < n; i ++)
#define FREACH(it,v) for( typeof(v.end()) it = v.begin(); it != v.end(); it ++ )
#define EPS 1e-9
using namespace std;
typedef long long ll;

int pw;
int r(int j, int lw, int hg) {
	int cp=j/10, cp2=j%10;
	int pwcp=pw;	
	int nwpw=1;
	int cnt=0;
	set<int> rep;
	while(cp>0) {
		int nw=cp+cp2*pwcp;
		if(nw > j && nw >= lw && nw <= hg)  {
			if(rep.find(nw)==rep.end()) {
				rep.insert(nw);
				cnt++;				
			}
		}
		nwpw*=10;
		cp2 += nwpw*(cp%10);
		cp/=10;
		pwcp/=10;
	}
	return cnt;
}

int main() {
	
	int T;
	cin >> T;
	FR(i,T) {		
		int A,B;
		cin >> A >> B;
		pw=1;
		int cp=A;
		while(cp>9) {
			pw*=10;
			cp/=10;
		}
		int res=0;		
		// this is the smallest of the pair
		for(int j=A;j<=B;j++) {
			res+=r(j,A,B);
		}
		cout << "Case #" << i+1 << ": " << res << endl;
	}
}