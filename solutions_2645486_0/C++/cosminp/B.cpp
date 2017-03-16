#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX_SIZE 	10001

fstream 	f, g;
int64_t		E, R, N;
int64_t		v[MAX_SIZE];


int64_t solve(int a, int b, int64_t current_energy, int64_t remaining_energy, int64_t &rem)
{
	int 	max_idx = -1;
	int64_t max_gain = 0;
	int64_t energy = 0;

	if (a > b) return 0;

	for (int i = a; i <= b; i++)
	{
		if ( (max_idx == -1) || (v[max_idx] < v[i]) )
		{
			max_idx = i;
		}
	}

	energy   = min(
			       min(E, (current_energy + (max_idx - a))),
			       current_energy + (b - a + 1)*R - remaining_energy
			      );

	max_gain = energy * v[max_idx]
	         + solve(a, max_idx - 1, min(E, current_energy - energy + R), energy, rem)
	         + solve(max_idx + 1, b, R, remaining_energy, rem);

	return max_gain;
}


int main()
{
	int		T;
	int64_t F;

	f.open("in.txt",  ios :: in);
	g.open("out.txt", ios:: out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> E >> R >> N;
		for (int i = 0; i < N; i++)
		{
			f >> v[i];
		}

		g << "Case #" << test << ": " << solve(0, N-1, E, 0, F) << endl;
	}

	f.close();
	g.close();

	return 0;
}
