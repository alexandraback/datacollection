#include <iostream>

int count[26];
int num[26];

int main()
{
	int t;
	std::cin >> t;

	for(int _ = 0;_ < t;++ _)
	{
		std::string input;
		std::cin >> input;

		for(int i = 0;i < 26;++ i)
		{
			count[i] = 0;
			num[i] = 0;
		}
		for(int i = 0;i < input.size();++ i)
			count[input[i] - 'A'] ++;

		// ZERO
		num[0] = count['Z' - 'A'];
		count['Z' - 'A'] -= num[0];
		count['E' - 'A'] -= num[0];
		count['R' - 'A'] -= num[0];
		count['O' - 'A'] -= num[0];

		// TWO
		num[2] = count['W' - 'A'];
		count['T' - 'A'] -= num[2];
		count['W' - 'A'] -= num[2];
		count['O' - 'A'] -= num[2];

		// FOUR
		num[4] = count['U' - 'A'];
		count['F' - 'A'] -= num[4];
		count['O' - 'A'] -= num[4];
		count['U' - 'A'] -= num[4];
		count['R' - 'A'] -= num[4];

		// FIVE
		num[5] = count['F' - 'A'];
		count['F' - 'A'] -= num[5];
		count['I' - 'A'] -= num[5];
		count['V' - 'A'] -= num[5];
		count['E' - 'A'] -= num[5];

		// SIX
		num[6] = count['X' - 'A'];
		count['S' - 'A'] -= num[6];
		count['I' - 'A'] -= num[6];
		count['X' - 'A'] -= num[6];

		// SEVEN
		num[7] = count['S' - 'A'];
		count['S' - 'A'] -= num[7];
		count['E' - 'A'] -= num[7];
		count['V' - 'A'] -= num[7];
		count['E' - 'A'] -= num[7];
		count['N' - 'A'] -= num[7];

		// EIGHT
		num[8] = count['G' - 'A'];
		count['E' - 'A'] -= num[8];
		count['I' - 'A'] -= num[8];
		count['G' - 'A'] -= num[8];
		count['H' - 'A'] -= num[8];
		count['T' - 'A'] -= num[8];

		// NINE
		num[9] = count['I' - 'A'];
		count['N' - 'A'] -= num[9];
		count['I' - 'A'] -= num[9];
		count['N' - 'A'] -= num[9];
		count['E' - 'A'] -= num[9];

		// THREE
		num[3] = count['R' - 'A'];
		count['T' - 'A'] -= num[3];
		count['H' - 'A'] -= num[3];
		count['R' - 'A'] -= num[3];
		count['E' - 'A'] -= num[3];
		count['E' - 'A'] -= num[3];

		// ONE
		num[1] = count['N' - 'A'];
		count['O' - 'A'] -= num[1];
		count['N' - 'A'] -= num[1];
		count['E' - 'A'] -= num[1];

		std::cout << "Case #" << _+1 << ": ";
		for(int i  = 0;i < 10;++ i)
		{
			for(int j = 0;j < num[i];++ j)
				std::cout << i;
		}
		std::cout << std::endl;

	}
	return 0;
}
