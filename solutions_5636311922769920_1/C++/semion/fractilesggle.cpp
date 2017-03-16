#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;

	// For each case
	for (int i = 1; i <= t; ++i){
		cout << "Case #" << i << ":";

		unsigned long long numToSelect, tiles, complexity;

		cin >> tiles >> complexity >> numToSelect;

		// Each finding of L in a generation allows us to know that
		// the first letter of the section it came from was also L.
		// So, we get to know an extra tile for each generation if we do it right.
		if (numToSelect * complexity < tiles){
			cout << " IMPOSSIBLE" << endl;
			continue;
		}

		// Find the proper tiles to clean.
		int indexOfUnknown = 0;			//index in original pattern being investigated
		unsigned long long index = 0;					//index of which to clean
		while (indexOfUnknown < tiles){	//while all tiles not investigated

			index = indexOfUnknown;

			//move index down through generations, while keeping same index in pattern
			for (int i = 1; i < complexity; ++i){
				index *= tiles;
				index += indexOfUnknown;

				//if this isn't the last unknown tile, go over one in pattern to gain more info
				if (indexOfUnknown < tiles - 1){
					++index;
					++indexOfUnknown;
				}
			}

			//clean tile. You now checked all tiles up through indexOfUnknown in original
			cout << " " << index + 1;
			++indexOfUnknown;
		}
		cout << endl;
	}

	return 0;
}
