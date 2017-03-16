#include<fstream>
using namespace std;

int main() {
	ifstream input ("in.txt");
	ofstream output ("out.txt");
	int t, n, s, p;
	input >> t;
	for (int i = 0 ; i < t; ++i) {
		int ans = 0;
		input >> n >> s >> p;
		output<< "Case #" << i+1 <<": ";
		int total[100], mod[100], div[100];
		for (int j = 0; j < n; ++j) {
			input >> total[j];
			mod[j] = total[j] % 3;
			div[j] = total[j] / 3;

			int dif = p - div[j];
			if (dif <= 0) {
				ans++;
			} else if (dif == 1) {
				if (mod[j] > 0) {
					ans++;
				} else if (s > 0 && (div[j]-1>=0) && (div[j]+1<=10)){
					ans++;
					s--;
				}
			} else if (dif == 2) {
				if (mod[j] == 2 && s >0) {
					ans++;
					s--;
				}
			}
		}
		output<<ans<<endl;
	}
}