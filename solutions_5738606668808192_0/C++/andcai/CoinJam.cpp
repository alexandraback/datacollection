#include <fstream>
#include <iostream>

using namespace std;

int main(){
	ifstream fin ("C-small-attempt0.in");
	ofstream fout ("C-output.txt");
	unsigned int t, n, j, x, tmp, tmp2, cnt;
	fin >> t;
	for (int i = 1; i <= t; i++){
		fin >> n >> j;
		fout << "Case #" << i << ":\n";
		cnt = 0;
		for (x = n/2; x >= 2; x--){		// Quick easy relatively large divisor of n
			if (n%x == 0)
				break;
		}

		// Answers will be of form "1{0,1}^(x-2)1" repeated several times.
		unsigned long long div[9];

		for (int z = (1 << (x-1)) + 1; cnt < j; z += 2){
			if (z >= (1 << x)){
				cout << "Out of these easy solutions.\n";
				break;
			}
			for (int b = 2; b <= 10; b++){
				div[b-2] = 0;
				for (int e = x-1; e >= 0; e--){
					div[b-2] *= b;
					if (z & (1 << e))
						div[b-2]++;
				}
			}
			for (int a = 0; a < (n/x); a++){
				fout << div[8];
			}
			for (int b = 2; b <= 10; b++)
				fout << ' ' << div[b-2];
			fout << '\n';
			cnt++;
		}
	}
	return 0;
}
