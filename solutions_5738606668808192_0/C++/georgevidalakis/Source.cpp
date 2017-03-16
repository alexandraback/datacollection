#include <fstream>
#include <math.h>
using namespace std;

bool JC[16];
unsigned long long int DS[9];

unsigned long long int ctb(unsigned int b)
{
	unsigned long long int r = 0, m = 1;
	for (unsigned int i = 0; i < 16; i++)
	{
		if (JC[i]) r += m;
		if (i < 15) m *= b;
	}
	return(r);
}

unsigned long long int gd(unsigned long long int n)
{
	if (n % 2 == 0) return(2);
	unsigned long long int l = (unsigned long long int) (sqrt(n) + 0.5);
	for (unsigned long long int i = 3; i <= l; i += 2) if (n % i == 0) return(i);
	return(0);
}

void inc()
{
	unsigned int p = 1;
	while (JC[p]) JC[p++] = false;
	JC[p] = true;
}

int main()
{
	unsigned int N = 16, J = 50, f = 0, cb;
	unsigned long long int d;
	bool c;
	JC[0] = true;
	for (unsigned int i = 1; i < 16; i++) JC[i] = false;
	JC[15] = true;
	ofstream fout("coinjam.out");
	fout << "Case #1:\n";
	while (f < J)
	{
		c = true;
		cb = 2;
		while (c && cb < 11)
		{
			d = gd(ctb(cb));
			if (d) DS[cb - 2] = d;
			else c = false;
			cb++;
		}
		if (c)
		{
			f++;
			for (int i = N - 1; i >= 0; i--)
			{
				if (JC[i]) fout << '1';
				else fout << '0';
			}
			for (unsigned int i = 0; i < 9; i++) fout << ' ' << DS[i];
			fout << '\n';
		}
		if (f < J) inc();
	}
	fout.close();
	return(0);
}