#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))


void Solve()
{
	int A, B, K; cin >> A >> B >> K;
	int res = 0;
	for(int i=0; i<A; ++i)
		for(int j=0; j<B; ++j){
			bool won = false;
			for(int k=0; k<K; ++k){
				int q = i&j;
				//cout << i << " & " << j << " = " << q << 
				//	"==" << k << (q==k ? "+":"-") << endl; 
				if(q==k){won = true; break;}
			}
			if(won) ++res;
		}
	cout << res;
	return;
}

int main()
{
	int n; cin >> n;
	FOR(t, n){
		cout << "Case #" << t+1 << ": ";
		Solve();
		cout << endl;
	}
	return 0;
}
