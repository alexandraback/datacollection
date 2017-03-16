#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


string solve(vector<double> &x, vector<double> &y)
{
	ostringstream	out;
	int 			N = x.size();
	int 			start, end;
	int 			oldBest, cheatBest;
	vector<int> 	used(N, 0);

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	oldBest = 0;
	for (int i = 0; i < N; i++)
	{
		int bestIdx;

		for (bestIdx = 0; used[bestIdx]; bestIdx++);

		for (int j = bestIdx; j < N; j++)
		{
			if (used[j]) continue;
			if (y[j] > x[i])
			{
				bestIdx = j;
				break;
			}
		}

		if (x[i] > y[bestIdx]) oldBest++;
		used[bestIdx] = 1;
	}

	start 		= 0;
	end 		= N - 1;
	cheatBest 	= 0;
	for (int i = 0; i < N; i++)
	{
		if (x[i] > y[start])
		{
			start++;
			cheatBest++;
		}
		else
		{
			end--;
		}
	}

	out << cheatBest << " " << oldBest;

	return string(out.str());
}


int main()
{
	fstream 			f, g;
	int 				T, N;
	vector<double> 		x, y;

	f.open("in.txt", ios::in);
	g.open("out.txt", ios::out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> N;
		x.clear(); x.resize(N);
		y.clear(); y.resize(N);
		for (int i = 0; i < N; i++)
			f >> x[i];

		for (int i = 0; i < N; i++)
			f >> y[i];

		g << "Case #" << test << ": " << solve(x, y) << endl;
	}

	return 0;
}
