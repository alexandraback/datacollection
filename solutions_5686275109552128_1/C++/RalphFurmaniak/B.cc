
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())


int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        int D; cin >> D;
        vector<int> P(D);
        fu(d,0,D) cin >> P[d];
        int best=10000000;
        
        for(int p=1; p<=1000; p++) {
            int cur=p;
            for(int d=0; d<D; d++)
                cur += (P[d]-1)/p;
            best=min(best,cur);
        }

        cout << best << endl;
	}
}
