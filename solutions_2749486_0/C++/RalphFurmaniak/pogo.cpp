

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
		int X,Y;
		cin >> X >> Y;
		for(int i=0; i<abs(X); i++) cout << (X>0 ? "WE" : "EW");
		for(int i=0; i<abs(Y); i++) cout << (Y>0 ? "SN" : "NS");
		cout << endl;
        }
}
