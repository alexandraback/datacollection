#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <bitset>
#include <utility>
#include <limits>
#include <iterator>
#include <numeric>

using namespace std;

int main(int argc, char** argv){

  unsigned long T;
  cin >> T;

  for(unsigned long t=1; t<=T; ++t){
	string input;
	int n;
	cin >> input;
	cin >> n;

	int result = 0;
	int last_found = -1;

	for (int i = 0; i < input.size() - n + 1; i++)
	{
		bool ok = true;
		for (int j = 0; j < n; j++)
		{
			if (input.at(i+j) == 'a' ||
					input.at(i+j) == 'e' ||
					input.at(i+j) == 'i' ||
					input.at(i+j) == 'u' ||
					input.at(i+j) == 'o')
			{
				ok = false;
			}
		}

		if (ok)
		{
			// the substring beginning at i suffices our condition
			int left = i - (last_found+1);
			int right = input.size() - n - i;

			int temp = (left+1)*(right+1);
			result += temp;

			last_found = i;
		}

	}

    cout << "Case #" << t << ": " << result;

    cout << endl;
  }

  return 0;
}
