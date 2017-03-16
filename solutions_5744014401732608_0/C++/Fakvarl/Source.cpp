#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	ifstream in("Bs2.in");
	ofstream out("output.txt");
	
	long long n;
	in >> n;
	for (size_t i = 0; i < n; i++)
	{
		long long B, M, left;
		in >> B >> M;
		out << "Case #" << i + 1 << ": ";
		left = M - 1;
		vector<vector<long long>> m(B);
		for (int j = 0; j < B; ++j)
		{
			m[j] = vector<long long>(B);
		}

		for (int j = 1; j < B; ++j)
		{
			m[0][j] = 1;
		}
		for (int j = B - 1; j >= 1; --j)
		{
			for (int l = j - 1; l >= 1 ; --l)
			{
				m[l][j] = 1;
				left--;
				if (left == 0)
				{
					break;
				}
				
			}

			if (left == 0)
			{
				break;
			}
		}

		if (left != 0)
		{
			out << "IMPOSSIBLE" << endl;
		}
		else
		{
			out << "POSSIBLE" << endl;
			for (size_t j = 0; j < B; j++)
			{
				for (size_t l = 0; l < B; l++)
				{
					out << m[j][l];
				}
				out << endl;
			}
		}
		

	}
}