#include <fstream>
#include <iostream>

using namespace std;

int main(){
	ifstream fin ("A-small-attempt0.in");
	ofstream fout ("output.txt");
	int t, n;
	fin >> t;
	for (int i = 1; i <= t; i++){
		fin >> n;
		int seen = 0, cnt = 0, tmp;
		if (n == 0){
			fout << "Case #" << i << ": INSOMNIA\n";
		}else{
			while (seen < (1 << 10) - 1){
				cnt += n;
				tmp = cnt;
				while (tmp > 0){
					seen |= 1 << (tmp % 10);
					tmp /= 10;
				}
			}
			fout << "Case #" << i << ": " << cnt << '\n';
		}
	}
	return 0;
}
