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
typedef long double ld;

int main() {
	int T;
	cin >> T;
	FR(i,T) {
		cout << "Case #" << i+1 << ": ";
		int A,B;
		cin >> A >> B;
		ld p_i;		
		// At the beginning it is 2*(B-A) + (End - A) + (1-p=1)*whole thing
		// Then the first part decreases by two, the p gets multiplied
		// precision errors are fine because this is the value we care about
		ld ans=B+2;
		ld p=1.0;
		FR(i,A){
			ans=min(ans,2*(A-i)+(B-A)+1+(1-p)*(B+1));
			cin>>p_i;
			p*=p_i;
		}
		ans=min(ans,(B-A)+1+(1-p)*(B+1));		
		cout.setf(ios::fixed);
		cout.precision(12);
		cout << ans << endl;
	}
}