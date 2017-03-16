#include <iostream>
#include <set>
using namespace std;

int T, N;


void solve(int tc)
{
	double block;
	int score1 = 0, score2 = 0;
	set<double> ken, naomi;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> block;
		naomi.insert(block);
	}

	for (int i = 0; i < N; i++) {
		cin >> block;
		ken.insert(block);
	}

	set<double>::reverse_iterator kenIt, naomiIt;
	kenIt = ken.rbegin();
	naomiIt = naomi.rbegin();

	int paired = 0;
	while (paired < N) {
		if (*kenIt < *naomiIt) {
			kenIt++;
			naomiIt++;
			score1++;
		} else {
			kenIt++;
		}

		paired++;
	}

	set<double>::reverse_iterator nit;
	set<double>::iterator kit;
	for (nit = naomi.rbegin(); nit != naomi.rend(); nit++) {
		kit = ken.upper_bound(*nit);
		if (kit == ken.end()) {
			score2++;
			ken.erase(ken.begin());
		} else {
			ken.erase(kit);
		}
	}

	cout << "Case #" << tc << ": ";
	cout << score1 << " " << score2 << endl;
}

int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}

	return 0;
}