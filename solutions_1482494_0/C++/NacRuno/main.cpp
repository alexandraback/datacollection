#include <iostream>
#include <fstream>
#include <string>
#include <climits>
using namespace std;

int main()
{
	ifstream input;
	ofstream output;

	string inputname = "input.txt";
	string outputname = "output.txt";

	input.open(inputname.c_str());
	output.open(outputname.c_str());

	unsigned T;
	input >> T;

	for (unsigned t = 0; t < T; t++)
	{
		unsigned N, a, b;

		input >> N;

		unsigned max = N*2;
		bool bad = false;
		bool skip = false;

		output << "Case #" << t+1 << ": ";

		int * a_i;
		a_i = new int [N];
		int * b_i;
		b_i = new int [N];
		int * star_i;
		star_i = new int [N];

		int star_total = 0;
		int play = 0;

		for (unsigned i = 0; i < N; i++)
		{
			star_i[i] = 0;
		}


		for (unsigned i = 0; i < N; i++)
		{
			input >> a >> b;

			if (a > max - 2 || b > max - 1)
			{
				bad = true;
				break;
			}

			a_i[i] = a;
			b_i[i] = b;
		}

		if (bad)
		{
			output << "Too Bad" << endl;
			skip = true;
			continue;
		}

		bool doneb;
		bool donea;

		unsigned next_bmax = 0;

		while (true)
		{
			do
			{
				doneb = false;
				for (unsigned i = 0; i < N; i++)
				{
					if (b_i[i] <= star_total && star_i[i] < 2)
					{
						star_total = star_total + 2 - star_i[i];
						star_i[i] = 2;
						doneb = true;
						play++;
					}
					else
					{
						if (b_i[i] > next_bmax)
						{
							next_bmax = b_i[i];
						}
					}
					if (star_total == max)
						break;
				}
				if (star_total == max)
					break;
			} while (doneb);

			donea = false;
			for (unsigned pen = 0; pen < next_bmax; pen++)
			{
				for (unsigned i = 0; i < N; i++)
				{
					if (a_i[i] <= star_total && b_i[i] == (next_bmax-pen) && star_i[i] < 1)
					{
						star_total = star_total + 1;
						star_i[i] = 1;
						donea = true;
						play++;
						break;
					}
					if (donea)
						break;
				}
				if (star_total == max || donea)
					break;
			}
			
			if (star_total == max)
			{
				break;
			}
			if (donea == false)
			{
				output << "Too Bad" << endl;
				skip = true;
				break;
			}
		}

		if (skip == false)
			output << play << endl;
	}


	return 0;
}