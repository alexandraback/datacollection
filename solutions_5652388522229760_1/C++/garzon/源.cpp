#include <iostream>
#include <fstream>
#define DIR "D:\\codejam\\"

#define REP(i, n) for(int i=0; i<(n); i++)

using namespace std;

int fa(int n) {
	if (n == 0) return -1;
	int counter = 0;
	bool count[10];
	int now = n;
	memset(count, false, sizeof(count));
	while (counter != 10) {
		int tmp = now;
		while (tmp) {
			int lsb = tmp % 10;
			tmp /= 10;
			if (!count[lsb]) {
				count[lsb] = true;
				counter++;
			}
		}
		if (counter == 10) break;
		now += n;
	}
	return now;
}

int main() {
	ifstream is(DIR"A-large.in");
	ofstream os(DIR"asmall_out.txt");

	int n;
	is >> n;
	REP(i, n) {
		int j;
		is >> j;
		int tmp = fa(j);
		os << "Case #" << (i + 1) << ": ";
		if (tmp == -1)
			os << "INSOMNIA";
		else
			os << tmp;
		os << endl;
	}

	return 0;
}