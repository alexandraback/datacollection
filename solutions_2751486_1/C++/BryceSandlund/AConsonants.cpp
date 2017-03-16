//============================================================================
// Name        : AConsonants.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

bool vowel(int index, string &str)
{
	for (int i = 0; i < 5; ++i)
	{
		if (str[index] == vowels[i])
			return true;
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		string str;
		cin >> str;
		int n;
		cin >> n;

		int vCount = 0;
		long long substrs = 0;
		int prevI = -1;
		for (int i = 0; i < str.size(); ++i)
		{
			if (!vowel(i, str))
			{
				++vCount;
			}
			else
			{
				vCount = 0;
			}

			if (vCount >= n)
			{
				long long pB = i - n + 1 - max(-1, prevI - n + 1);
				long long pA = str.size() - i;
				substrs += pB * pA;
				prevI = i;
			//	cout << substrs << endl;
			}
		}
		cout << "Case #" << caseNum << ": " << substrs << endl;
	}
	return 0;
}
