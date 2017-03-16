#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

int T, N;
double naomi[1001];
double ken[1001];
bool used_war[1001];

double kenCoiche(double weight)
{
	int best_choice = -1;
	for (int i = 0; i < N; i++) {
		if ( !used_war[i] ) {
			if (best_choice < 0) best_choice = i;
			if (ken[i] > weight) {
				best_choice = i;
				break;
			}
		}
	}
	used_war[best_choice] = true;
	return ken[best_choice];
}

int main()
{
	double tmp;
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
		
		int best_war_score = 0;
		for (int i = 0; i < N; i++) {
			used_war[i] = false;
		}
		for (int i = 0; i < N; i++) {
			if (naomi[i] > kenCoiche(naomi[i])) { best_war_score++; }
		}

		reverse(ken, ken+N);
		int best_deceitful_score = 0;
		bool ok;
		for (int d = 0; d < N; d++) {
			ok = true;
			for (int i = d; i < N; i++) {
				if (naomi[i] < ken[N-1-i+d]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				best_deceitful_score = N-d;
				break;
			}
		}
		cout << "Case #" << t+1 << ": " << best_deceitful_score << " "
		     << best_war_score << endl;
	}
	return 0;
}
