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

vector<int> indeces;

int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("problemA-large.in");
	//cin.open("test");
	cout.open("problemA-large-out.txt");

	int T;
	cin >> T;

	for(int t = 1; t <= T; t++)
	{
		string L;
		int n;

		cin >> L >> n;

		indeces.clear();

		cout << "Case #" << t << ": " << solve(L, n) << endl;
	}

	cin.close();
	cout.close();

	return 0;
}

LL solve(string L, int n)
{
	LL res = 0;
	int size = L.length();

	int counter = 0;
	for(int i = 0; i < size; i++)
	{
		if(isVowel(L[i])) counter = 0;
		else
		{
			if(++counter >= n)
			{
				indeces.push_back(i - n + 1);
			}
		}
	}

	int j = 0;

	int isize = indeces.size();

	for(int i = 0; i < size; i++)
	{
		while(indeces[j] < i && j < isize) j++;
		if(j >= isize) break;
		res += size - n - indeces[j] + 1;
	}

	return res;

}

bool isVowel(char c)
{
	if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')
		return true;

	return false;
}
