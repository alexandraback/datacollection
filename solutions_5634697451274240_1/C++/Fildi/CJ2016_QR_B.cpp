// CJ2016_QR_B.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

void flip(char *s, int lastIndex){
	for (int i = 0; i <= lastIndex / 2; i++) {
		char ch1 = s[i];
		char ch2 = s[lastIndex - i];
		if (ch1 == '+')
			ch1 = '-';
		else
			ch1 = '+';
		if (ch2 == '+')
			ch2 = '-';
		else
			ch2 = '+';
		s[i] = ch2;
		s[lastIndex - i] = ch1;
		
	}
}
int solve(char *s) {
	int lastMinus = strlen(s) - 1;
	while (lastMinus >= 0 && s[lastMinus] == '+')
		lastMinus--;
	int result = 0;
	while (lastMinus >= 0) {
		int plusCount = 0;
		while (s[plusCount] == '+') {
			s[plusCount] = '-';
			plusCount++;
		}
		if (plusCount > 0)
			result++;
		flip(s, lastMinus);
		result++;
		while (lastMinus >= 0 && s[lastMinus] == '+')
			lastMinus--;
		
	}
	return result;


}
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		char s[200];
		//cin.getline(s, 200);
		cin >> s;
		cout << "Case #" << i + 1 << ": " << solve(s) << endl;
	}
	return 0;
}

