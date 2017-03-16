#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <utility>

using namespace std;

bool palindrome(long int num)
{
	long int dig = 0;
	long int rev = 0;
	
	long int n = num;
	while (num > 0)
	{
		dig = num % 10;
		rev = rev * 10 + dig;
		num = num / 10;
	}
	if (n == rev)
		return true;
	return false;
}

int main()
{
	ofstream cout ("LMs.out");
        ifstream cin ("C-small-attempt0.in");

	int trials;
	cin >> trials;
	
	for (int i = 0; i < trials; i++)
	{
            	long int A;
       	        long int B;
		cin >> A >> B;

		long int scount = 0;
		long int index = 1;
		while (true)
		{
			if (palindrome(index))
			{
				if (palindrome(index*index))
				{
					if (index*index >= A && index*index <=B)
					{
						scount++;
						//cout << index << endl;
					}
				}
			}
			if (index*index > B)
				break;
			index++;
		}
		cout << "Case #" << i+1 << ": " << scount << endl;
	}

	return 0;	
}
