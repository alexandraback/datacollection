#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string S;
		cin >> S;

		map<char, int> letters;
		for (char c : S)
			letters[c]++;

		multiset<int> digits;
		while (letters['Z'] != 0)
		{
			letters['Z']--;
			letters['E']--;
			letters['R']--;
			letters['O']--;
			digits.insert(0);
		}
		while (letters['W'] != 0)
		{
			letters['T']--;
			letters['W']--;
			letters['O']--;
			digits.insert(2);
		}
		while (letters['X'] != 0)
		{
			letters['S']--;
			letters['I']--;
			letters['X']--;
			digits.insert(6);
		}
		while (letters['U'] != 0)
		{
			letters['F']--;
			letters['O']--;
			letters['U']--;
			letters['R']--;
			digits.insert(4);
		}
		while (letters['F'] != 0)
		{
			letters['F']--;
			letters['I']--;
			letters['V']--;
			letters['E']--;
			digits.insert(5);
		}
		while (letters['V'] != 0)
		{
			letters['S']--;
			letters['E']--;
			letters['V']--;
			letters['E']--;
			letters['N']--;
			digits.insert(7);
		}
		while (letters['G'] != 0)
		{
			letters['E']--;
			letters['I']--;
			letters['G']--;
			letters['H']--;
			letters['T']--;
			digits.insert(8);
		}
		while (letters['I'] != 0)
		{
			letters['N']--;
			letters['I']--;
			letters['N']--;
			letters['E']--;
			digits.insert(9);
		}
		while (letters['T'] != 0)
		{
			letters['T']--;
			letters['H']--;
			letters['R']--;
			letters['E']--;
			letters['E']--;
			digits.insert(3);
		}
		while (letters['N'] != 0)
		{
			letters['O']--;
			letters['N']--;
			letters['E']--;
			digits.insert(1);
		}

		cout << "Case #" << t + 1 << ": ";
		for (int c : digits)
			cout << c;
		cout << endl;
	}

	return 0;
}
