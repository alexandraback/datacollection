#include <iostream>
using namespace std;
int nd(int t) {
	if (t<10) return 1;
	return 1 + nd(t/10);
}
int main() 
{
	int T;
	cin >> T;	
	int c = 0;
	while(T--) {
		int A,B;
		cin >> A >> B;
		int ret = 0;
		for(int i = max(10,A); i<=B; ++i)
		for(int j = i+1; j<=B; ++j) {
			int m = i;
			int num = nd(m);
			int pow = 1;
			for(int k=0;k<num-1;++k) pow*=10;
			do {
				int d = m%10;
				m = m/10 + d*pow;
				if (m == j) {ret++;break;}
			}while(m!=i);
		}
		cout << "Case #"<<++c<<": "<<ret <<"\n";
	}
	return 0;
}
