#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T;

long long euclid_gcf(long long n, long long m)
{
	if(m == 0)
		return n;
	else
		return euclid_gcf(m, n % m);
}

int main(int argc, const char* argv[])
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		long long P = 0, Q = 0;
		char c = ' ';

		fin >> P >> c >> Q;
		long long gcf = euclid_gcf(P, Q);
		P /= gcf; Q /= gcf;
		fout << "Case #" << i + 1 << ": ";
		int answer = ceil(log((long double)Q / (long double)P) / log(2.0F));
		if(pow(2.0F, (int)((double)(log((long double)Q) / log(2.0F)) + 0.5)) != Q)
			fout << "impossible" << "\n";
		else if(answer > 40)
			fout << "impossible" << "\n";
		else
			fout << answer << "\n";
	}
	return 0;
}