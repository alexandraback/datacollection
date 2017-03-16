#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int calcWarTot(const vector<double>& naomi, const vector<double>& ken) {
	int n = naomi.size();
	vector<bool> kenTaken(n, false);

	// war tot
	int warCount = 0;
	for (int j = 0; j < n; ++j) {
		double Nchosen = naomi[j];

		// get smallest
		double Kchosen;
		int Kchoseni;
		for (int k = 0; k < n; ++k) {
			if (kenTaken[k])
				continue;
			Kchosen = ken[k];
			Kchoseni = k;
			break;
		}

		// look for best greedy choice
		for (int k = n-1; k > -1; --k) {
			if (kenTaken[k])
				continue;
			if (!(ken[k] > Nchosen))
				break;
			Kchosen = ken[k];
			Kchoseni = k;
		}

		kenTaken[Kchoseni] = true;

		// cout << Kchosen << " " << Nchosen << endl;

		// update naomi's points
		if (!(Kchosen > Nchosen))
			warCount++;

	}

	// cout << "ANS" << warCount << endl;
	return warCount;
}

int calcDeceitTot(const vector<double>& naomi, const vector<double>& ken) {
	int n = naomi.size();
	vector<bool> kenTaken(n, false);

	// war tot
	for (int j = 0; j < n; ++j) {
		double Nactual = naomi[j];
		double Nchosen = Nactual;

		// if naomi only has winners left, that is the answer!
		int keni = 0;
		int naoi = j;
		while (keni < n) {
			if (kenTaken[keni]) {
				++keni;
				continue;
			}

			// cout << keni << " " << naoi << " " << ken[keni] << " " << naomi[naoi] << endl;

			if (ken[keni] > naomi[naoi]) 
				break;

			++keni;
			++naoi;
		}
		// cout << keni << " " << naoi << "------------" << endl;

		if (keni == n && naoi == n)
			return n-j;


		// find kens biggest
		double Klargest;
		for (int k = n-1; k > -1; --k) {
			if (kenTaken[k])
				continue;
			Klargest = ken[k];
			break;
		}

		// have naomi lie
		Nchosen = Klargest - 0.000001;

		// cout << "nc " << Nchosen << " " << Nactual << endl;

		// get smallest
		double Kchosen;
		int Kchoseni;
		for (int k = 0; k < n; ++k) {
			if (kenTaken[k])
				continue;
			Kchosen = ken[k];
			Kchoseni = k;
			break;
		}

		// look for best greedy choice
		for (int k = n-1; k > -1; --k) {
			if (kenTaken[k])
				continue;
			if (!(ken[k] > Nchosen))
				break;
			Kchosen = ken[k];
			Kchoseni = k;
		}

		kenTaken[Kchoseni] = true;


	}

	// cout << "ANS" << warCount << endl;
	return 0;
}

int main() {
	int kases;
	cin >> kases;

	for (int i = 0; i < kases; ++i) {

		int n;
		cin >> n;


		// get the blocks for naomi and ken
		vector<double> naomi;
		vector<double> ken;

		double in;

		for (int j = 0; j < n; ++j) {
			cin >> in;
			naomi.push_back(in);
		}

		for (int j = 0; j < n; ++j) {
			cin >> in;
			ken.push_back(in);
		}

		// sort asc
		sort(ken.begin(), ken.end());
		sort(naomi.begin(), naomi.end());

		printf("Case #%d: %d %d\n", i+1, calcDeceitTot(naomi, ken), calcWarTot(naomi, ken));

		

	}

	return 0;
}