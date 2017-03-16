#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#define LL long long

using namespace std;

LL solve(string L, int n);
bool isVowel(char c);

int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("problemA-small.in");
	cout.open("problemA-small-out.txt");

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		string L;
		int n;

		cin >> L >> n;

		cout << "Case #" << t << ": " << solve(L, n) << endl;
	}

	cin.close();
	cout.close();

	return 0;
}

LL solve(string L, int n)
{
	LL res = 0;
	string s;
	int size = L.length();
	for(int i = 0; i < size; i++)
	{
		for(int j = 1; j < size - i + 1; j++)
		{
			s = L.substr(i, j);
			int ssize = s.length();
			int counter = 0;
			for(int j = 0; j < ssize; j++)
			{
				if(isVowel(s[j])) counter = 0;
				else
				{
					counter++;
					if(counter == n)
					{
						res++;
						break;
					}
				}
			}
		}
	}

	return res;
}

bool isVowel(char c)
{
	if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')
		return true;

	return false;
}
