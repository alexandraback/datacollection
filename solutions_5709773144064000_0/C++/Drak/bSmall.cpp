#include <bits/stdc++.h>
using namespace std;
#define msg(x) cout<<#x<<" = "<<x<<endl;
int main() {
    ios_base::sync_with_stdio(0);
	int T;
	double c, f, x;
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%lf %lf %lf", &c, &f, &x);
		double tiempo = 0.0, inc = 2.0;
		while( true ) {
			double a, b, incB = inc + f;
			a = x / inc;
			b = c / inc + x / incB;
			if( a <= b ) {
				tiempo += a;
				break;
			}
			tiempo += ( c / inc );
			inc += f;
		}
		printf("Case #%d: %.9lf\n", caso, tiempo);
	}    
    return 0;
}