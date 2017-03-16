#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const int MAXN = 100000 + 200;


int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int T; cin >> T;
	
	for(int cas = 0; cas < T; cas++){
		printf("Case #%d: ", cas + 1);
		int A, B;
		double p[MAXN], ans = (1e50);
		cin >> A >> B;
		for(int i = 1; i <= A; i++){
			cin >> p[i];
		}
		for(int i = A + 1; i >= 1; i--){
			double pro = 1, tmp = 0;
			for(int j = 1; j < i; j++){
				pro *= p[j];
			}
			tmp += pro * (A - i + B - i + 3);
			tmp += (1 - pro) * (A - i + 2 * B - i + 4);
			ans = min(ans, tmp);
		}
		ans = min(ans, B + 2.0);
		printf("%lf\n", ans);
	}
}