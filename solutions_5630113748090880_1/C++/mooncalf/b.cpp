#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, n, h;
	
	cin >> t;
	
	for (int i = 0; i < t; ++i){
		cin >> n;
		int nums = (2*n-1)*n;
		int heights[2501] = {0}; 
		for (int j = 0; j < nums; ++j) {
			cin >> h;
			++heights[h];
		}
		cout << "Case #" << i + 1 << ": "; 
		for (int j = 1; j < 2501; ++j) {
			if (heights[j] % 2) cout << j << " ";
		}
		cout << endl;
	}

	return 0;
}
