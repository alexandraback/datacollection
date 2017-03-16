#include <iostream>
#include <fstream>
using namespace std;

	#define cin fin
	#define cout fout
	ifstream fin("B-small-attempt0.in");
	ofstream fout("B.out");

int main() {
	int cn = 1;
	int cs; cin >> cs;
	while (cs--) {
		int N, S, P;
		cin >> N >> S >> P;
		
		int ans = 0;
		for (int i=0; i<N; ++i) {
			int n;
		    cin >> n;
		    if (n % 3 == 0) {
				if (n / 3 >= P) ans++;
				else if (S && n >= 3 && n / 3 + 1 == P) ans++, S--;
			} else if (n % 3 == 2) {
				if (n / 3 + 1 >= P) ans++;
				else if (S && n >= 2 && n / 3 + 2 == P) ans++, S--;
			} else {
				if (n / 3 + 1 >= P) ans++;
			}
		}
		cout << "Case #" << cn++ << ": " << ans << endl;
	}
	system("pause");
	return 0;
}
