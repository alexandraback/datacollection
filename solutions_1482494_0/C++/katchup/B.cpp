/*
	GOOGLE CODE JAM
	Contestant 			: Alex "katchup" AUVOLAT
	Contest reference	: Code Jam 2012 round 1A
	Problem				: B. Kingdom Crush
*/



#include <iostream>
#include <vector>

using namespace std;

void one_case() {
	int N;
	cin >> N;
	vector<int> A(N, 0), B(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		cin >> B[i];
	}

	// solve problem
	int stars = 0;
	int games = 0;
	vector<int> beat(N, 0);

	while (true) {
		bool finished = true;

		int maxStarsAvail = 0, maxI = 0;
		for (int i = 0; i < N; i++) {
			if (beat[i] != 2) finished = false;

			int starsAvail = (stars >= B[i] ? 2 : (stars >= A[i] ? 1 : 0)) - beat[i];
			if (starsAvail > maxStarsAvail) {
				maxStarsAvail = starsAvail;
				maxI = i;
			} else if (starsAvail == maxStarsAvail && starsAvail == 1) {
				if (beat[i] > beat[maxI] ||
						( beat[i] == beat[maxI] && B[i]>B[maxI] )
					) {
					maxStarsAvail = starsAvail;
					maxI = i;
				}
			}
			if (maxStarsAvail == 2) break;
		}

		if (finished) break;

		if (maxStarsAvail == 0) {
			cout << "Too Bad";
			return;
		}
		stars += maxStarsAvail;
		beat[maxI] += maxStarsAvail;
		games++;
	}
	cout << games;
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

