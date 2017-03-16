#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

template <class T> void SWAP(T & a, T  & b) { T t = a; a = b; b = t; }
template <class T> T MAX(T a, T b) { if (a > b) return a; else return b; }
template <class T> T MIN(T a, T b) { if (a < b) return a; else return b; }
template <class T> T ABS(T a) { if (a < 0) return -a; else return a; }

using namespace std;

int main(int argc, char* argv[])
{
	string inputFileName = "C-small-attempt0.in";
	//string inputFileName = "C-large.in";
	ifstream input(inputFileName);
	int T;
	int J[101], P[101], S[101], K[101];
	input >> T;
	for (int i = 0; i < T; ++i)
	{
		input >> J[i] >> P[i] >> S[i] >> K[i];
	}
	input.close();
	ofstream output(inputFileName + ".out");
	for (int i = 0; i < T; ++i)
	{
		output << "Case #" << (i + 1) << ": ";
		vector<string> vs;
		map<pair<int, int>, int> cnt[3];
		for (int j = 1; j <= J[i]; ++j)
		{
			for (int p = 1; p <= P[i]; ++p)
			{
				for (int s = 1; s <= S[i]; ++s)
				{
					pair<int, int> key[] = { make_pair(j, p), make_pair(j, s), make_pair(p, s) };
					if (	cnt[0][key[0]] < K[i]
						&&	cnt[1][key[1]] < K[i]
						&&	cnt[2][key[2]] < K[i]
						)
					{
						char buf[100];
						sprintf(buf, "%d %d %d", j, p, s);
						vs.push_back(buf);
						++cnt[0][key[0]];
						++cnt[1][key[1]];
						++cnt[2][key[2]];
					}
				}
			}
		}
		output << vs.size() << endl;
		for (int j = 0; j < vs.size(); ++j)
		{
			output << vs[j] << endl;
		}
	}
	output.close();

	system("pause");
	return 0;
}
