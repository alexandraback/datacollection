#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ifstream input;
ofstream output;

const int Multi[5][5] = {	{0, 0, 0, 0, 0}, 
							{0, 1, 2, 3, 4}, 
							{0, 2, -1, 4, -3}, 
							{0, 3, -4, -1, 2}, 
							{0, 4, 3, -2, -1}};

const int MAXN = 10000 + 100;

int mult(int x, int y)
{
	int sign = x / abs(x) * y / abs(y);
	return sign * Multi[abs(x)][abs(y)];
}

int a[MAXN];

int l2r[MAXN], r2l[MAXN];

int Pow[10];

void singleCase(int case_num)
{
	int L, X;
	string str;
	input >> L >> X >> str;

	for (int i=0; i<L; i++)
		switch(str[i])
		{
		case 'i':
			a[i + 1] = 2; break;
		case 'j':
			a[i + 1] = 3; break;
		case 'k':
			a[i + 1] = 4; break;
		}

	l2r[0] = 1;
	for (int i=1; i<=L; i++)
		l2r[i] = mult(l2r[i - 1], a[i]); 

	r2l[L + 1] = 1;
	for (int i=L; i>0; i--)
		r2l[i] = mult(a[i], r2l[i + 1]);

	int period = r2l[1];
	Pow[0] = 1;
	for (int i=1; i<5; i++)
		Pow[i] = mult(Pow[i - 1], period);

	if (Pow[X % 4] != -1)
	{
		output << "Case #" << case_num << ": NO" << endl;
		return;
	}

	for (int left = 0; left < 4 && left < X; left++)
		for (int c1 = 1; c1 <= L; c1++) if (mult(Pow[left], l2r[c1]) == 2)
			for (int right=0; right < 4 && right < X - left; right++)
			{
				if (left + right + 1 == X)
				{
					for (int c2 = L + 1; c2 > c1 + 1; c2--)
						if (mult(r2l[c2], Pow[right]) == 4)
						{
							output << "Case #" << case_num << ": YES" << endl;
							return;
						}
				}
				else
				{
					for (int c2 = L; c2 > 0; c2--)
						if (mult(r2l[c2], Pow[right]) == 4)
						{
							output << "Case #" << case_num << ": YES" << endl;
							return;
						}
				}
			}


	output << "Case #" << case_num << ": NO" << endl;
}

int main()
{
	input.open("C-small.in");
	output.open("C-small.out");

	int T;
	input >> T;

	for (int i=0; i<T; i++)
		singleCase(i + 1);

	return 0;
}