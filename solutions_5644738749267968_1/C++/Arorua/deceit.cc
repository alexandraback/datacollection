#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int war(vector<float> naomi, vector<float> ken, int N)
{
	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());
	int pts = 0;
	for (int i = 0; i < N; ++i) {
		vector<float>::iterator it = 
			lower_bound(ken.begin(), ken.end(), naomi[i]);
		if (it != ken.end()) {
			ken.erase(it);
		} else {
			it = ken.begin();
			ken.erase(it);
			pts += 1;
		}
	}
	return pts;
}

int deceitwar(vector<float> naomi, vector<float> ken, int N)
{
	int pts = 0;
	sort(naomi.begin(), naomi.end());
	sort(ken.begin(), ken.end());
	for (int i = 0; i < N; ++i) {
		if (*naomi.rbegin() > *ken.rbegin()) {
			naomi.pop_back();
			ken.pop_back();
			pts += 1;
		} else if (*naomi.begin() < *ken.rbegin()) {
			// deceit
			ken.pop_back();
			naomi.erase(naomi.begin());
		}
	}
	return pts;
}

int process(int c)
{
	vector<float> naomi, ken;
	int N;
	float k;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> k;
		naomi.push_back(k);
	}
	for (int i = 0; i < N; ++i) {
		cin >> k;
		ken.push_back(k);
	}
	cout << "Case #" << c << ": " << deceitwar(naomi, ken, N)
		 << " " << war(naomi, ken, N) << endl;
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i)
		process(i);
}
