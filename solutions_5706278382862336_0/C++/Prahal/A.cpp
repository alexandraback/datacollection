#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("D:\\Input.txt");
ofstream fout("D:\\Output.txt");

int T;

int main(int argc, const char* argv[])
{
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		int P = 0, Q = 0;
		char c = ' ';

		fin >> P >> c >> Q;
		fout << "Case #" << i + 1 << ": ";
		int answer = ceil(log((float)Q / (float)P) / log(2.0F));
		if(pow(2.0F, (int)((double)(log((float)Q) / log(2.0F)) + 0.5)) != Q)
			fout << "impossible" << "\n";
		else if(answer > 40)
			fout << "impossible" << "\n";
		else
			fout << answer << "\n";
	}
	return 0;
}