#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream f;
	f.open(argv[1]);
	int T;
	f >> T;
	for (int t=0; t<T; t++) {
		cout << "Case #" << t+1 << ": ";
		int N, S, p;
		f >> N >> S >> p;
		int* k = new int [N];
		for (int i=0; i<N; i++) f >> k[i];
		if (p == 0) cout << N << endl;
		else if (p == 1) {
			int s = 0;
			for (int i=0; i<N; i++) s += (k[i] != 0);
			cout << s << endl;
		} else {
			int s1 = 0, s2 = 0;
			for (int i=0; i<N; i++) {
				s1 += (k[i] >= 3*p-2);
				s2 += (k[i] == 3*p-3 || k[i] == 3*p-4);
			}
			cout << (s1+(s2>S?S:s2)) << endl;		
		}
		delete[] k;
		
	}
	f.close();
}
