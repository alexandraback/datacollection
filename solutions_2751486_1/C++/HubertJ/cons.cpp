#include <cstdio>
#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <cassert>

using namespace std;


int main(int argc, char *argv[])
{
	int c, cases;
	cin >> cases;
	
	for(c = 1; c <= cases; c++)
	{
		int n;
		string s;
		cin >> s;
		cin >> n;

		int len = s.length();
		unsigned long long nValue = 0;
		int conseq = 0; //# consecutive consonants
		int trailing = 0;
		for (int i = 0; i < len; i++)
		{

			if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
			{
				conseq++;
			}
			else
			{
				conseq = 0;
			}
			
			trailing++;

			if (conseq == n) 
			{
				int remaining = len-1-i;
				nValue += (1+(trailing-n))*(1+remaining);
				trailing =  n-1;
				conseq = n-1;
			}
		}
		
		cout << "Case #" << c << ": " << nValue << endl;
	}
}

