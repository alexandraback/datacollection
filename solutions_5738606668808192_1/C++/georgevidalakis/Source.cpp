#include <fstream>
using namespace std;

bool JC[16];

void inc()
{
	unsigned int p = 1;
	while (JC[p]) JC[p++] = false;
	JC[p] = true;
}

int main()
{
	unsigned int N = 16, J = 500;
	unsigned long long int d;
	bool c;
	JC[0] = true;
	for (unsigned int i = 1; i < 7; i++) JC[i] = false;
	JC[15] = true;
	ofstream fout("coinjam.out");
	fout << "Case #1:\n";
	for (unsigned int i = 0; i < J; i++)
	{
		for (unsigned int j = 0; j < 16; j++)
		{
			if (JC[j]) fout << "11";
			else fout << "00";
		}
		for (unsigned int j = 3; j < 12; j++) fout << ' ' << j;
		fout << '\n';
		inc();
	}
	return(0);
}