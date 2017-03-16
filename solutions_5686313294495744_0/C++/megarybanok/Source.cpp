#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


void main() {

	FILE *str, *abc;
	freopen_s(&str, "input.txt", "r", stdin);
	freopen_s(&abc, "out.txt", "w", stdout);

	int t;
	cin >> t;
	
	for (int tt = 0; tt < t; tt++) {
		cout << "Case #" << tt + 1 << ": ";
		
		int n;
		cin >> n;
		int a1 = 0, a2 = 0;
		map <string, bool > first, second;
		for (int i = 0; i < n; i++) {
			

			string a, b;
			cin >> a >> b;
			
			if (!first[a]) { first[a] = true; a1++; }
			if (!second[b]) { second[b] = true; a2++; }

			
		}
		cout << n - max(a1, a2) << endl;

	}
		
}