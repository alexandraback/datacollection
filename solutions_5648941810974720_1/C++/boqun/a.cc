#include <iostream>
#include <string>

using namespace std;

int T;
string tmp;

int S[256];
int n[10];

void count(int S[], const char *s)
{
	char c;
	while (c = *s++)
		S[c]++;

}

int zero(int *S)
{
	int result = S['Z']; 

	if (result != 0) {
		S['Z'] -= result;
		S['E'] -= result;
		S['R'] -= result;
		S['O'] -= result;
	}

	return result;
}

int six(int *S)
{
	int result = S['X']; 

	if (result != 0) {
		S['S'] -= result;
		S['I'] -= result;
		S['X'] -= result;
	}

	return result;
}

int seven(int *S)
{
	int result = S['S']; 

	if (result != 0) {
		S['S'] -= result;
		S['E'] -= result * 2;
		S['V'] -= result;
		S['N'] -= result;
	}

	return result;
}

int nine(int *S)
{
	int result = S['I']; 

	if (result != 0) {
		S['N'] -= result * 2;
		S['E'] -= result;
		S['I'] -= result;
	}

	return result;
}

int eight(int *S)
{
	int result = S['G']; 

	if (result != 0) {
		S['E'] -= result;
		S['I'] -= result;
		S['G'] -= result;
		S['H'] -= result;
		S['T'] -= result;
	}

	return result;
}

int three(int *S)
{
	int result = S['H']; 

	if (result != 0) {
		S['E'] -= result * 2;
		S['H'] -= result;
		S['T'] -= result;
		S['R'] -= result;
	}

	return result;
}

int two(int *S)
{
	int result = S['W'];

	if (result != 0) {
		S['T'] -= result;
		S['W'] -= result;
		S['O'] -= result;
	}

	return result;
}

int five(int *S)
{
	int result = S['V'];

	if (result != 0) {
		S['F'] -= result;
		S['I'] -= result;
		S['V'] -= result;
		S['E'] -= result;
	}

	return result;
}

int one(int *S)
{
	int result = S['N'];

	if (result != 0) {
		S['O'] -= result;
		S['N'] -= result;
		S['E'] -= result;
	}

	return result;
}
int four(int *S)
{
	int result = S['F'];

	return result;
}
int main()
{
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> tmp;
		
		for (int j = 0; j < 256; j++)
			S[j] = 0;

		for (int j = 0; j < 10; j++)
			n[j] = 0;

		count(S, tmp.c_str());

		n[0] = zero(S);
		n[2] = two(S);
		n[6] = six(S);
		n[7] = seven(S);
		n[5] = five(S);
		n[8] = eight(S);
		n[9] = nine(S);
		n[3] = three(S);
		n[1] = one(S);
		n[4] = four(S);

		cout << "Case #" << i << ": ";

		for (int j = 0; j < 10; j++)
			for (int k = 0; k < n[j]; k++)
				cout << j;
		cout << endl;	
	}

}




