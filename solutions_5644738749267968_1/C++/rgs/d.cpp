#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int NMAX = 1005;
const float delta = 0.000001;

float Nnumbers[NMAX], Knumbers[NMAX];

int n;

int war() {
	set<float> hand;
	for (int i = 0; i < n; i++) hand.insert(Knumbers[i]);

	int score = 0;
	for (int i = 0; i < n; i++) {
		float x = Nnumbers[i];

		auto y = hand.lower_bound(x);
		if (y == hand.end()) y = hand.begin();
		hand.erase(y);

		if (x > *y) score++;
	}
	return score;
}

int deceitful_war() {
	sort(Nnumbers, Nnumbers+n);

	set<float> hand;
	for (int i = 0; i < n; i++) hand.insert(Knumbers[i]);

	/*
	for (int i = 0; i < n; i++) {
		cerr << Nnumbers[i] << " ";
	}
	cerr << endl;
	for (auto it = hand.begin(); it != hand.end(); it++) {
		cerr << *it << " ";
	}
	cerr << endl;
	*/

	int score = 0, l = 0;
	while (l < n) {
		auto max_y = hand.end(); max_y--;
		auto min_y = hand.begin();
		// cerr << "y " << *min_y << " " << *max_y << endl;

		if (Nnumbers[l] > *min_y) {
			hand.erase(min_y); score++;
		} else {
			hand.erase(max_y);
		}
		l++;
	}
	return score;
}

int main() {
	int t; cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> Nnumbers[i];
		for (int i = 0; i < n; i++) cin >> Knumbers[i];

		int war_score = war();
		int deceitful_war_score = deceitful_war();

		cout << "Case #" << ti << ": " << deceitful_war_score << " " << war_score << endl;
	}
}