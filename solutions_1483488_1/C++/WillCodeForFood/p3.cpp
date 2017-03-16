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
		for(int i = max(A,10); i <= B; ++i) {
			int m = i;
			int num = nd(i);
			int mult = 1;
			for(int j = 0;j < num-1; ++j) mult *= 10;
			do {
				int d = m%10;
				m = m/10 + mult*d;
				if (m > i && m >=A && m <= B) ++ret;
			} while(m!=i);
		}
		cout << "Case #"<<++c<<": "<<ret <<"\n";
	}
	return 0;
}
