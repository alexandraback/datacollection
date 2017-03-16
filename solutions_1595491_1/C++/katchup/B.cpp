/*
	GOOGLE CODE JAM
	Contestant 			: Alex "katchup" AUVOLAT
	Contest reference	: Google Code Jam 2012 - Qualification Round
	Problem				: B. Dancing With The Googlers
*/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void one_case() {
	int N, S, P;
	cin >> N;
	cin >> S;
	cin >> P;
	vector<int> T(N, 0);
	for (int i = 0; i < N; i++)
		cin >> T[i];

	cerr << "(" << N << "," << S << "," << P << ") ";
	
	cerr << "{";
	for (int i = 0; i < N; i++) cerr << (i != 0 ? "," : "") << T[i];
	cerr << "} "; 
	sort(T.begin(), T.end());
	cerr << "{";
	for (int i = 0; i < N; i++) cerr << (i != 0 ? "," : "") << T[i];
	cerr << "} ";
	
	int max = 0;
	for (int i = N-1; i >= 0; i--) {
		int t = T[i];
		if (t == 0) {
			if (P == 0) max++;
			continue;
		}
		if (t % 3 == 0) {
			int score = t / 3;
			cerr << "[" << t << ";" << score << "," << score << "," << score;
			if (score >= P) {
				max++;
				cerr << "++";
			} else if (score < 10 && S > 0 && score + 1 >= P) {
				max++;
				S--;
				cerr << "++S";
			}
		} else if (t % 3 == 1) {
			int best = t / 3 + 1;
			int other = t / 3;
			cerr << "[" << t << ";" << best << "," << other << "," << other;
			if (best >= P) {
				max++;
				cerr << "++";
			}
		} else if (t % 3 == 2) {
			int best_two = t / 3 + 1;
			int worst = t / 3;
			cerr << "[" << t << ";" << best_two << "," << best_two << "," << worst;
			if (best_two >= P) {
				max++;
				cerr << "++";
			} else if (S > 0 && best_two < 10 && best_two + 1 >= P) {
				max++;
				S--;
				cerr << "++S";
			}
		}
		cerr << "] ";
	}
	cerr << " -> " << max << endl;
	cout << max;
}

int main(int argc, char *argv[]) {

	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cout << "Case #" << (i+1) << ": ";
		one_case();
		cout << endl;
	}

	return 0;
}

