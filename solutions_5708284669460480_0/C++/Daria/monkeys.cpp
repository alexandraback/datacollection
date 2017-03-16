#include <fstream>
#include <iomanip>

using namespace std;

double expected;
int maxOccurs;
int k, l, s, t, A, gen[30];
string target, keyboard;
double keyProb[30];
char keyChar[30];

void backtrack(int step) {
	int i;
	if (step > s) {
		double prob = 1.0;
		string temp_s = "";
		for (i = 1; i < step; i++) {
			prob *= keyProb[gen[i]];
			temp_s += keyChar[gen[i]];
		}
		int occurs = 0;
		for (i = 0; i < step-l; i++) {
			if (temp_s.substr(i, l) == target) occurs++;
		}
		expected += prob*(double)occurs;
		if (occurs > maxOccurs) maxOccurs = occurs;
		return;
	}
	for (i = 1; i <= A; i++) {
		gen[step] = i;
		backtrack(step+1);
	}
}
int main() {
	ifstream fi("banana.in");
	ofstream fo("banana.out");
	fi >> t;
	for (int T = 1; T <= t; T++) {
		fi >> k >> l >> s;
		fi >> keyboard >> target;
		expected = 0.0;
		maxOccurs = 0;
		A = 0;
		for (char c = 'A'; c <= 'Z'; c++) {
			int nr = 0;
			for (int i = 0; i < keyboard.length(); i++) {
				if (keyboard[i] == c) nr++;
			}
			if (nr > 0) {
				keyProb[++A] = (double)nr/(double)keyboard.length();
				keyChar[A] = c;
			}
		}
		backtrack(1);
		fo << setprecision(7) << fixed;
		fo << "Case #" << T << ": " << maxOccurs - expected << "\n";
	}
	return 0;
}