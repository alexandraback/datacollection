#include      <iostream>
#include      <fstream>
#include      <list>

using namespace std;

int getMax(int n, bool bSurprising) {
	if (!bSurprising) {
		return (n / 3) + (n % 3 ? 1 : 0);
	}
	return getMax(n, false) + (n % 3 != 1 && n);
}

int main(int argc, char **argv) {
	int nTests, nPeople, nSurprising, nAtleast;
	list<int> listPeople;
	int nTmp, nResult;
	freopen("input", "r", stdin);
	cin >> nTests;

	for (int nTest = 1; nTest <= nTests; ++nTest) {
		cin >> nPeople >> nSurprising >> nAtleast;
		listPeople.clear();
		for (int nPerson = 0; nPerson < nPeople; ++nPerson) {
			cin >> nTmp;
			listPeople.push_back(nTmp);
		}

		listPeople.sort();

		nResult = 0;
		for (list<int>::const_iterator it = listPeople.begin(); it != listPeople.end(); ++it) {
			if (nSurprising && getMax(*it, true) >= nAtleast) {
				--nSurprising;
				++nResult;
			} else if (getMax(*it, false) >= nAtleast) {
				++nResult;
			}
		}

		cout << "Case #" << nTest << ": " << nResult << endl;
	}

	return 0;
}
