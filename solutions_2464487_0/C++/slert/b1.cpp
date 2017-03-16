#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	// freopen("test.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);

	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		long double r, t;
		cin >> r >> t;

		long long n = ( -(2*r+3)+2*sqrt( (r-0.5)*(r-0.5)+2*t ) )/4+1;
		while(true){
			n--;
			long long a = ( 2*n*n+(2*r+3)*n+(2*r+1) );
			if(a<=t)break;
		}
		n++;
		cout << "Case #" << ti << ": " << n << endl;
	}

	// for(int n = 0; n < 10; n++){
	// 	cout << n << " " << ( (2*1+1)*(n+1)+2*n*(n+1) ) << endl;
	// }
	return 0;
}