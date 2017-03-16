#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct numword
{
	string word;
	char indicator;
	char digit;
	
	numword() {}
	numword(const string& w, char c, char d) { word = w, indicator = c, digit = d; }
};

int main()
{
	const vector<numword> numwords = {
		numword("ZERO", 'Z', '0'),
		numword("TWO", 'W', '2'),
		numword("FOUR", 'U', '4'),
		numword("ONE", 'O', '1'),
		numword("THREE", 'R', '3'),
		numword("FIVE", 'F', '5'),
		numword("SIX", 'X', '6'),
		numword("SEVEN", 'S', '7'),
		numword("EIGHT", 'G', '8'),
		numword("NINE", 'I', '9')
	};
	
	int cases;
	cin >> cases;
	for (int c = 1; c <= cases; c++)
	{
		string words;
		string solution;
		cin >> words;
		// Build a frequency table
		int freqs[128] = {};
		for (char letter : words)
			freqs[letter]++;
		
		// Check for words in order
		for (const numword& nm : numwords)
		{
			int count = freqs[nm.indicator];
			solution.insert(solution.end(), count, nm.digit);
			for (char letter : nm.word)
				freqs[letter] -= count;
		}
		
		// Get non-decreasing number
		sort(solution.begin(), solution.end());
		cout << "Case #" << c << ": " << solution << endl;
	}
}
