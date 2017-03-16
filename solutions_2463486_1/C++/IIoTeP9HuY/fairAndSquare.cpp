#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

const char* inputFile = "C-large-1.in";
const char* outputFile = "C-large-1.out";

bool isPalindrome(long long x)
{
	string s = to_string(x);
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}

vector<long long> discover(long long R)
{
	vector<long long> fairSquares;
	for (long long i = 1; i < R; ++i)
	{
		if (isPalindrome(i) && isPalindrome(i*i))
		{
			//cout << i << endl;
			fairSquares.push_back(i*i);
		}
	}
	return fairSquares;
}

vector<long long> fairSquares;
string solveTest()
{
	long long A, B;
	cin >> A >> B;
	int inRange = 0;
	for (long long fairSquare : fairSquares)
	{
		if (A <= fairSquare && fairSquare <= B)
		{
			++inRange;
		}
	}
	return to_string(inRange);
}

int main()
{
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	fairSquares = discover(100000000);
	size_t T;
	scanf("%d\n", &T);
	for (int testNumber = 1; testNumber <= T; ++testNumber)
	{
		string verdict = solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
