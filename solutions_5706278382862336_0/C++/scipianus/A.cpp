#include <fstream>
#include <cstring>
using namespace std;
int T, ns;
long long P, Q, C, put[44];
char s[110];

inline long long Cmmdc(long long a, long long b)
{
	long long r;
	while(b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t, i, j;
	put[0] = 1;
	for(i = 1; i <= 43; ++i)
		put[i] = 2LL * put[i - 1];
	ifstream fin("A.in");
	ofstream fout("A.out");
	fin >> T;
	for(t = 1; t <= T; ++t)
	{
		fin >> (s + 1);
		ns = strlen(s + 1);
		P = Q = 0;
		i = 1;
		while(s[i] != '/')
		{
			P = P * 10LL + s[i] - '0';
			i++;
		}
		i++;
		while(i <= ns && '0' <= s[i] && s[i] <= '9')
		{
			Q = Q * 10LL + s[i] - '0';
			i++;
		}
		C = Cmmdc(P, Q);
		P /= C;
		Q /= C;
		j = 0;
		while(put[j + 1] <= Q)
			j++;
		if(put[j] != Q)
			fout << "Case #" << t << ": impossible\n";
		else
		{
			i = 0;
			while(put[i + 1] <= P)
				i++;
			fout << "Case #" << t << ": " << (j - i) << "\n";
		}
	}
	fin.close();
	fout.close();
	return 0;
}
