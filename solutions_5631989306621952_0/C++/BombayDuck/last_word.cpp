#include <iostream>
#include <string>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++)
	{
		string word, last_word;
		cin >> word;

		last_word = word[0];
		for(int j = 1; j < word.length(); j++)
		{
			if(word[j] >= last_word[0])
			{
				last_word = word[j] + last_word;
			} 
			else
			{
				last_word = last_word + word[j];
			}
		}
		cout << "Case #" << (i + 1) << ": " << last_word << endl;
	}
	return 0;
}
