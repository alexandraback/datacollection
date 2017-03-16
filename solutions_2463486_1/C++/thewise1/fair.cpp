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
	ofstream cout ("LMl1.out");
        ifstream cin ("C-large-1.in");

	int trials;
	cin >> trials;

	long int validArr[50];
	validArr[0] = 1;
	validArr[1] = 2;
	validArr[2] = 3;
       	validArr[3] = 11;
       	validArr[4] = 22;
       	validArr[5] = 101;
	validArr[6] = 111;
	validArr[7] = 121;
	validArr[8] = 202;
	validArr[9] = 212;
	validArr[10] = 1001;
	validArr[11] = 1111;
	validArr[12] = 2002;
	validArr[13] = 10001;
	validArr[14] = 10101;
	validArr[15] = 10201;
	validArr[16] = 11011;
	validArr[17] = 11111;
	validArr[18] = 11211;
	validArr[19] = 20002;
	validArr[20] = 20102;
	validArr[21] = 100001;
	validArr[22] = 101101;
	validArr[23] = 110011;
	validArr[24] = 111111;
	validArr[25] = 200002;
	validArr[26] = 1000001;
	validArr[27] = 1001001;
	validArr[28] = 1002001;
	validArr[29] = 1010101;
	validArr[30] = 1011101;
	validArr[31] = 1012101;
	validArr[32] = 1100011;
	validArr[33] = 1101011;
	validArr[34] = 1102011;
	validArr[35] = 1110111;
	validArr[36] = 1111111;
	validArr[37] = 2000002;
	validArr[38] = 2001002;
	validArr[39] = 10000001;
	validArr[40] = 10011001;
	validArr[41] = 10100101;
	validArr[42] = 10111101;
	validArr[43] = 11000011;
	validArr[44] = 11011011;
	validArr[45] = 11100111;
	validArr[46] = 11111111;
	validArr[47] = 20000002;

	
	for (int i = 0; i < trials; i++)
	{
            	long int A;
       	        long int B;
		cin >> A >> B;

		long int scount = 0;
		long int index = 0;
		while (true)
		{
			if (palindrome(validArr[index]))
			{
				if (palindrome(validArr[index]*validArr[index]))
				{
					if (validArr[index]*validArr[index] >= A && validArr[index]*validArr[index] <= B)
					{
						scount++;
						//cout << (validArr[index] << endl;
					}
				}
			}
			if (validArr[index]*validArr[index] > B)
				break;
			index++;
		}
		cout << "Case #" << i+1 << ": " << scount << endl;
	}

	return 0;	
}
