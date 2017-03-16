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
        int N; cin >> N;
        string val; cin >> val;
        int tot=0;
        int extra=0;
        for(int i=0; i<=N; i++) {
            int x = val[i]-'0';
            if(x && tot<i) { extra+=i-tot; tot=i; }
            tot += x;
        }
        cout << extra << endl;
	}
}
