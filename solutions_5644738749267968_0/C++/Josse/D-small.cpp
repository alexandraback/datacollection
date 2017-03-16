#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
	int N;
	cin >> N;
	deque<double> NaomiA(N), NaomiB, KenA(N), KenB;
	for (int i = 0; i < N; i++)
		cin >> NaomiA[i];
	sort(NaomiA.begin(), NaomiA.end());
	NaomiB = NaomiA;
	for (int i = 0; i < N; i++)
		cin >> KenA[i];
	sort(KenA.begin(), KenA.end());
	KenB = KenA;
	int scoreA = 0;
	for (int i = 0; i < N; i++) {
		if (NaomiA[0] < KenA[0])
			KenA.pop_back();
		else {
			KenA.pop_front();
			scoreA++;
		}
		NaomiA.pop_front();
	}
	int scoreB = 0;
	for (int i = 0; i < N; i++) {
		if (NaomiB[N - 1 - i] < KenB[N - 1 - i])
			KenB.pop_back();
		else {
			KenB.pop_front();
			scoreB++;
		}
		NaomiB.pop_back();
	}
	cout << scoreA << " " << scoreB << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}
	return 0;
}
