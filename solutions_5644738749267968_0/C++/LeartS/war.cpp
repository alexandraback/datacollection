#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

int T, N;
double naomi[10];
double ken[10];
bool used_war[10];
bool used_deceitful[10];

double kenCoiche(double weight, bool deceitful)
{
	int best_choice = -1;
	for (int i = 0; i < N; i++) {
		if ( (deceitful && !used_deceitful[i]) || (!deceitful && !used_war[i]) ) {
			if (best_choice < 0) best_choice = i;
			if (ken[i] > weight) {
				best_choice = i;
				break;
			}
		}
	}
	if (deceitful) used_deceitful[best_choice] = true;
	else used_war[best_choice] = true;
	
	//cout << fixed << setprecision(7) << "kenChoice(" << weight << ", "
	//     << deceitful << ") -> " << ken[best_choice] << endl;
	return ken[best_choice];
}

int main()
{
	double tmp;
	int warscore = 0;
	int deceitfulscore = 0;
	cin >> T;
	
	for (int t = 0; t < T; t++) {

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			naomi[i] = tmp;
		}
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			ken[i] = tmp;
		}

		sort(naomi, naomi+N);
		sort(ken, ken+N);

		int war_score, deceitful_score;
		int best_war_score = 0;
		int best_deceitful_score = 0;
		// 10! = 3628000 cycles
		do {
			for (int i = 0; i < N; i++) {
				used_deceitful[i] = false;
				used_war[i] = false;
			}
			war_score = deceitful_score = 0;
			for (int i = 0; i < N; i++) {
				if (naomi[i] > kenCoiche(naomi[i], false)) { war_score++; }
				if (naomi[i] > kenCoiche(ken[N-i-1] - 0.000005, true)) {
					deceitful_score++;
				}
			}
			best_war_score = max(best_war_score, war_score);
			best_deceitful_score = max(best_deceitful_score, deceitful_score);
		} while (next_permutation(naomi, naomi+N));

		cout << "Case #" << t+1 << ": " << best_deceitful_score
		     << " " << best_war_score << endl;
	}

	return 0;
}
