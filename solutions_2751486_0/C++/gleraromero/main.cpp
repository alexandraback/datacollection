#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

#define uint unsigned int
#define ulong unsigned long long int

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		
		string s;
		int n;
		cin >> s >> n;
		
		int result = 0;
		int cCount = 0;
		int lastN = -1;
		int sLength = (int)s.length();
		for (int i = 0; i < sLength; ++i)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				cCount = 0;
				continue;
			}
			
			cCount++;
			if (cCount == n)
			{
				int firstLetter = i - (n-1);
				int left = firstLetter - lastN;
				if (firstLetter == 0)
					left = 1;
				int right = sLength - i;				
				result += left * right;
				
				cCount--;
				lastN = firstLetter;
			}
		}
		
		cout << result << endl;
	}
	return 0;
}
