#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

string problemFile = "C-large-1";

//Globals
fstream input;
fstream output;
int CaseNum; //track what case # we are up to
vector<string> allSmallPalindromes; //Up to the size we are attempting to do, sqrt(10^14) = 10^7
vector<long long> allSmallPalindromesNum;

//Declarations
void SolveInstance();

template <class T>
void LoadVector(vector<T>& v, int n) 
{
	int i, x;
	for (i = 0; i < n; ++i)
	{
		input >> x;
		v.push_back(x);
	}
}

//Returns the length of a number when written in base 10
int GetNumberLength(long long num)
{
	int length = 0;
	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return length;
}

vector<string> GetAllPalindromes(int minLen, int maxLen);
vector<string> GetPalindromsOfLengthAdd1(vector<string> basePalindromes);
bool IsPalindrome(long long x);

int main()
{
	input.open(problemFile+".in", ios::in);
	output.open(problemFile+".out", ios::out);

	allSmallPalindromes = GetAllPalindromes(1, 8);
	for(vector<string>::iterator iter = allSmallPalindromes.begin(); iter != allSmallPalindromes.end(); ++iter)
	{
		allSmallPalindromesNum.push_back(stoll(*iter));
	}

	int T;
	input >> T;
	for (CaseNum = 1; CaseNum <= T; ++CaseNum)
	{
		SolveInstance();
	}

	return 0;
}

void SolveInstance()
{
	long long A,B;
	input >> A >> B;

	long result = 0;

	//Lower and upper bounds for the square root component (smaller number)
	long long lowerBoundSmall = (long long)ceil(sqrt(A));
	long long upperBoundSmall = (long long)floor(sqrt(B));

	for(vector<long long>::iterator iter = allSmallPalindromesNum.begin(); iter != allSmallPalindromesNum.end(); ++iter)
	{
		long long smallPalindrome = *iter;
		if (smallPalindrome < lowerBoundSmall)
			continue;
		if (smallPalindrome > upperBoundSmall)
			break;

		if(IsPalindrome(smallPalindrome * smallPalindrome))
			result++;
	}

	
	output << "Case #" << CaseNum << ": " << result << endl;
}

//Get all palindromes of length a to length b (length = num of digits), in string form
vector<string> GetAllPalindromes(int minLen, int maxLen)
{
	vector<string> result;
	
	//Start with base palindromes from 1-9
	vector<string> curPalindromes;
	int curLen = 1;
	for(char i = '1'; i <= '9'; ++i)
	{
		string s(1,i);
		curPalindromes.push_back(s);
	}

	while (curLen <= maxLen)
	{
		if(curLen >= minLen)
			result.insert(result.end(), curPalindromes.begin(), curPalindromes.end());

		curPalindromes = GetPalindromsOfLengthAdd1(curPalindromes);
		curLen++;
	}

	return result;
}

//For each palindrome in basePalindromes, returns the set of palindromes off the base but with 1 extra digit
//Assumes all palindromes in basePalindromes are of same len
vector<string> GetPalindromsOfLengthAdd1(vector<string> basePalindromes)
{
	vector<string> result;
	for (vector<string>::iterator iter = basePalindromes.begin(); iter != basePalindromes.end(); ++iter)
	{
		string basePalindrome = *iter;

		//If even length, then can add any number in the middle.
		if(basePalindrome.length() % 2 == 0)
		{
			for(char i = '0'; i <= '9'; ++i)
			{
				string newPalindrome = basePalindrome;
				string s(1,i);
				newPalindrome.insert(basePalindrome.length() / 2, s);
				result.push_back(newPalindrome);
			}
		}
		else //Odd length, need to split middle char into 2x middle char
		{
			string newPalindrome = basePalindrome;
			char middle = basePalindrome[basePalindrome.length()/2];
			string s(1,middle);
			newPalindrome.insert(basePalindrome.length() / 2, s);
			result.push_back(newPalindrome);
		}
	}

	return result;
}

bool IsPalindrome(long long x)
{
	char buf[102];
	sprintf(buf, "%lli", x);

	int length;
	for (int i = 0; i < sizeof(buf); ++i)
	{
		if (buf[i] == '\0')
		{
			length = i;
			break;
		}
	}

	//Check palindromeness
	for (int i = 0; i < (length+1)/2; ++i)
	{
		if (buf[i] != buf[length - 1 - i])
			return false;
	}

	return true;
}