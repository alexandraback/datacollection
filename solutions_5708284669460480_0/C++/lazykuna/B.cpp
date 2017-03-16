#include <iostream>
#include <fstream>
#include <memory.h>
#include <iomanip>
using namespace std;
// use: ./A input.txt >> output.txt

ifstream in;
int n;

int k,l,s;
char kb[256];
char target[256];
double p[256];

int maxoccur;
double expect;

char tmp[256];
void mutate(int idx, double prob) {
	if (idx == s) {
		// calc occurance
		int occur = 0;
		int sl = strlen(target);
		for (int i=0; i<s-sl+1; i++) {
			if (memcmp(tmp+i, target, sl) == 0)
				occur++;
		}

		if (maxoccur < occur)
			maxoccur = occur;

		expect += occur*prob;
	} else {
		for (int i=0; i<k; i++) {
			tmp[idx] = kb[i];
			//mutate(idx+1, prob * p[tmp[idx]-'A']);
			mutate(idx+1, prob / (double)k);
		}
	}
}

void process(int idx) {
	// count and calculate
	for (int i=0; i<='Z'-'A'; i++) {
		p[i] = 0;
	}
	for (int i=0; i<k; i++) {
		p[kb[i]-'A'] ++;
	}
	for (int i=0; i<='Z'-'A'; i++) {
		p[i] /= (double)k;
		//cout << (char)(i+'A') << ": " << p[i] << "\n";
	}
	double res = 1;
	int repIdx = 0;
	// find repeating index!
	/*for (int i=1; i<l-1; i++) {
		bool same = true;
		for (int j=0; (j+i)<l; j++) {
			if (target[j+i] != target[i]) {
				same = false;
				break;
			}
		}
		if (same) {
			cout << "same: " << target[i] << "\n";
			repIdx = i;
			break;
		}
	}
	cout << "repidx: " << repIdx << "\n";

	// calculate!
	// fill L length
	int chrIdx = 0;
	for (int i=0; i<s; i++) {
		//cout << p[target[chrIdx]-'A'] << '\n';
		res *= p[target[chrIdx]-'A'];

		chrIdx++;
		if (chrIdx >= l)
			chrIdx = repIdx;
	}*/

	maxoccur = 0;
	expect = 0;
	mutate(0, 1);

	//cout << maxoccur << "\n";
	cout << fixed;
	cout << "Case #" << idx << ": " << maxoccur-expect << "\n";
}

int main(int argc, char **argv) {
	if (argc == 1) {
		cout << "please enter input.txt argv\n";
		return -1;
	}

	in.open(argv[1]);

	in >> n;

cout.precision(8);
	for (int i=0; i<n; i++) {
		in >> k >> l >> s;
		in >> kb;
		in >> target;
		process(i+1);
	}

	in.close();

	return 0;
}
