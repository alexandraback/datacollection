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
		ulong n;
		cin >> s >> n;
		
		ulong result = 0;
		ulong cCount = 0;
		ulong lastN = -1;
		ulong sLength = (ulong)s.length();
		for (ulong i = 0; i < sLength; ++i)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				cCount = 0;
				continue;
			}
			
			cCount++;
			if (cCount == n)
			{
				ulong firstLetter = i - (n-1);
				ulong left = firstLetter - lastN;
				if (firstLetter == 0)
					left = 1;
				ulong right = sLength - i;				
				result += left * right;
				
				cCount--;
				lastN = firstLetter;
			}
		}
		
		cout << result << endl;
	}
	return 0;
}
