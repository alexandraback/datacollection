#include <iostream> 
#include <stdio.h>
#include <string> 

using namespace std;

int alph[24];

int main()
{
	int T;
	cin >> T;
	string s;
	for(int t=1; t<=T; t++) {
		cin >> s;
		for(int i=0; i<s.length(); i++) {
			alph[s[i] - 65]+=1;
		}
		cout << "Case #" << t << ": ";	
		int zeros = alph['Z' - 65];
		alph['Z' - 65] -=zeros;
		alph['E' - 65] -= zeros;
		alph['R' - 65] -= zeros;
		alph['O' - 65] -= zeros;
		
		int twos = alph['W' - 65];
		alph['T' - 65] -= twos;
		alph['W' - 65] -= twos;
		alph['O' - 65] -= twos;

		int fours = alph['U' - 65];
		alph['F' - 65] -= fours;
		alph['O' - 65] -= fours;
		alph['U' - 65] -= fours;
		alph['R' - 65] -= fours;
		
		int six = alph['X' - 65];
		alph['S' - 65] -= six;
		alph['I' - 65] -= six;
		alph['X' - 65] -= six;
		
		int eight = alph['G' - 65];
		alph['E' - 65] -= eight;
		alph['I' - 65] -= eight;
		alph['G' - 65] -= eight;
		alph['H' - 65] -= eight;
		alph['T' - 65] -= eight;
		
		int ones = alph['O' - 65];
		alph['O' - 65] -= ones;
		alph['N' - 65] -= ones;
		alph['E' - 65] -= ones;
		
		int five = alph['F' - 65];
		alph['F' - 65] -= five;
		alph['I' - 65] -= five;
		alph['V' - 65] -= five;
		alph['E' - 65] -= five;

		int seven = alph['V' - 65];
		alph['S' - 65] -= seven;
		alph['E' - 65] -= seven;
		alph['V' - 65] -= seven;
		alph['E' - 65] -= seven;
		alph['N' - 65] -= seven;
		
		int three = alph['T' - 65];
		alph['T' - 65] -= three;
		alph['H' - 65] -= three;
		alph['R' - 65] -= three;
		alph['E' - 65] -= three;
		alph['E' - 65] -= three;

		int nine = alph['I' - 65];
		alph['N' - 65] -= nine;
		alph['I' - 65] -= nine;
		alph['N' - 65] -= nine;
		alph['E' - 65] -= nine;

		for(int i=0; i<zeros; i++)
			printf("0");
		for(int i=0; i<ones; i++)
			printf("1");
		for(int i=0; i<twos; i++)
			printf("2");
		for(int i=0; i<three; i++)
			printf("3");
		for(int i=0; i<fours; i++)
			printf("4");
		for(int i=0; i<five; i++)
			printf("5");
		for(int i=0; i<six; i++)
			printf("6");
		for(int i=0; i<seven; i++)
			printf("7");
		for(int i=0; i<eight; i++)
			printf("8");
		for(int i=0; i<nine; i++)
			printf("9");
		cout << endl;
	}
	return 0;
}
