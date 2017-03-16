#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VI num;

int doit(char ch, const string& s)
{
	int r = num[ch];
	for (unsigned i=0; i<s.size(); i++)
		num[s[i]] -= r;
	return r;
}

int main()
{
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		string S;
		cin >> S;
		num.assign(256, 0);
		for (unsigned i=0; i<S.size(); i++)
			num[S[i]]++;
		VI digits(10, 0);
		digits[0] = doit('Z', "ZERO");
		digits[2] = doit('W', "TWO");
		digits[6] = doit('X', "SIX");
		digits[8] = doit('G', "EIGHT");
		digits[3] = doit('H', "THREE");
		digits[4] = doit('R', "FOUR");
		digits[7] = doit('S', "SEVEN");
		digits[5] = doit('V', "FIVE");
		digits[9] = doit('I', "NINE");
		digits[1] = doit('O', "ONE");
		cout << "Case #" << t << ": ";
		for (int i=0; i<10; i++)
			for (int j=0; j<digits[i]; j++)
				cout << i;
		cout << endl;
	}
    return 0;
}