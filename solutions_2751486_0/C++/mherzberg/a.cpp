#include <iostream>

using namespace std;

int solve(string word, int n)
{
	int count = 0;
	int startFrom = 0;
	int curCount = 0;
	
	for (int i = 0; i < (int) word.length(); ++i)
	{
		if (word[i] == 'a' || word[i] == 'i' || word[i] == 'e' || word[i] == 'o' || word[i] == 'u')
		{
			curCount = 0;
		}
		else
		{
			++curCount;
		}
		
		if (curCount >= n)
		{
			count += (i + 2 - startFrom - n) * (word.length() - i);
			startFrom = i - curCount + 2;
			--curCount;
		}
	}
	
	return count;
}

int main() 
{
	int cases;
	cin >> cases;
	
	for (int i = 1; i <= cases; ++i)
	{
		string word;
		int n;
		cin >> word >> n;
		
		cout << "Case #" << i << ": " << solve(word, n) << endl;
	}
	return 0;
}
