#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include <set>

using namespace std;

int main() {
	ofstream fout("war.out");
	ifstream fin("war.in");
	
	int t;
	fin >> t;

	for (int caseNo = 1; caseNo <= t; caseNo++){
		int n;
		fin >> n;
		set<double> a, b;
		//A is naomi
		//B is ken

		double val;
		for (int i = 0; i < n; i++){
			fin >> val;
			a.insert(val);
		}
		for (int i = 0; i < n; i++){
			fin >> val;
			b.insert(val);
		}
		set<double> bcopy(b);

		//trumping a, ie optimal for ken
		int kenPoints = 0;
		for (auto iter = a.begin(); iter != a.end(); iter++){
			//lowest value in b above the value being iterated
			auto lowestAbove = b.lower_bound(*iter);
			if (lowestAbove != b.end()){
				b.erase(lowestAbove);
				kenPoints++;
			}
		}

		int naoPoints = 0;
		for (auto iter = bcopy.begin(); iter != bcopy.end(); iter++){
			//lowest value in b above the value being iterated
			auto lowestAbove = a.lower_bound(*iter);
			if (lowestAbove != a.end()){
				a.erase(lowestAbove);
				naoPoints++;
			}
		}

		fout << "Case #" << caseNo << ": " << naoPoints << " " << n - kenPoints << endl;
	}
	return 0;
}