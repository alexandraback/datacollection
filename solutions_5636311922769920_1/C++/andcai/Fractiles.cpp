#include <fstream>

using namespace std;

int main(){
	ifstream fin ("D-large.in");
	ofstream fout ("D-output.txt");
	int t, K, C, S;
	fin >> t;
	for (int i = 1; i <= t; i++){
		fin >> K >> C >> S;
		if (S * C < K){
			fout << "Case #" << i << ": IMPOSSIBLE\n";
		}else{
			fout << "Case #" << i << ":";
			if (S == 1){
				fout << " 1\n";
				continue;
			}
			int x = 0;
			unsigned long long v = 0;
			for (int y = 0; y < K; y++){
				v *= K;
				v += y;
				if (++x == C){
					fout << ' ' << v + 1;
					x = v = 0;
				}
			}
			if (v != 0)
				fout << ' ' << v + 1;
			fout << '\n';
		}
	}
	return 0;
}
