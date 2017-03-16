#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
	int tn;
	cin >> tn;

	for (int ti = 0; ti < tn; ti++) {

		int n;
		int s;
		int p;
		cin >> n >> s >> p;

		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			int akt;
			cin >> akt;
			v.push_back(akt);
		}

		std::sort(v.begin(), v.end(), std::greater<int>());

		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] >= (p*3)) // 8 8 8
			{
				result++;
				continue;
			}
			if (v[i] >= (p*3-2) && (p-1>=0)) // 7 7 8
			{
				result++;
				continue;
			}
			if (s && v[i] >= (p*3-4) && (p-2>=0)) // 6 6 8
			{
				--s;
				result++;
				continue;
			}
			break;
		}		

		cerr << "Sol: " << result << endl;
		std::cout << "Case #" << ti+1 << ": " << result << endl;
	}
}

