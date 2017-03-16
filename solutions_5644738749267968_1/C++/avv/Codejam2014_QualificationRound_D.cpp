#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include <iomanip>
#ifdef __GNUC__
#include  <tr1/unordered_map>
#define unordered_map tr1::unordered_map
#else
#include <unordered_map>
#endif

using namespace std;

#define int64 long long
#define F(vec, index) for (int index = 0; index  < vec.size(); ++index)
#define F_S(vec, index, start) for (int index = start; index  < vec.size(); ++index)



int main(int argc, char* argv[])
{

	ofstream cout ("output.txt");
	ifstream cin("input.txt");

	int T;
	cin >> T;

	for (int t = 0; t < T; ++t)
	{
		
		int N;
		cin >> N;
		
		vector<double> player1(N, 0);
		for (int i = 0; i < N; ++i)
		{
			cin >> player1[i];
		}

		vector<double> player2(N, 0);
		for (int i = 0; i < N; ++i)
		{
			cin >> player2[i];
		}
		
		sort(player2.begin(), player2.end());
		sort(player1.begin(), player1.end());

		vector<bool> seleted2(N, false);
		int player1Score = N;
		F(player1, i)
		{
			bool found = false;
			F(player2, j)
			{
				if (seleted2[j]) continue;

				if (player2[j] > player1[i])
				{
					seleted2[j] = true;
					player1Score--;
					found = true;
					break;

				}
			}
			if (!found)
			{
				F(player2, j)
				{
					if (!seleted2[j])
					{
						seleted2[j] = true;
					}
				}
			}
		}

	
		int player1ScoreType2 = 0;
		vector<bool> seleted(N, false);
		F(player2, i)
		{
			bool found = false;
			F(player1, j)
			{
				if (player2[i] < player1[j])
				{
					if (seleted[j])
					{
						continue;
					}
					seleted[j] = true;
					player1ScoreType2++;
					found = true;
					break;
				}
			}
			/*if (!found)
			{
				for (int j = seleted.size() - 1; j >= 0; --j)
				{
					if (!seleted[j])
					{
						seleted[j] = true;
					}
				}
			}*/
		}
		
		cout << "Case #" << t + 1 << ": " << player1ScoreType2 << " " << player1Score   << endl;
		
		

	}
	return 0;
}
