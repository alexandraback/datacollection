#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool double_is_int(double trouble) {
   double absolute = abs( trouble );
   return absolute == floor(absolute);
}

int main()
{
	ofstream out; ifstream in;
	out.open("output.txt");
	in.open("input.txt");
	int t;
	in >> t;
	for (int j = 0; j < t; ++j)
	{
		int K, L, S;
		string keyboard, target;
		in >> K >> L >> S;
		in >> keyboard >> target;

		// if(K < L)
		// {
		// 	out << "Case #" << j+1 << ": " << "0.0" << endl;
		// 	continue;
		// }

		double k[26] = {0}, l[26] = {0};

		for (int i = 0; i < K; ++i)
		{
			k[keyboard[i] - 65]++;
		}
		for (int i = 0; i < L; ++i)
		{
			l[target[i] - 65]++;
		}

		bool keyHave = true;
		for (int i = 0; i < 26; ++i)
		{
			if(l[i] > 0)
			{
				if(k[i] == 0 )
				{
					keyHave = false;
					break;
				}
			}
		}
		if(!keyHave)
		{
			out << "Case #" << j+1 << ": " << 0.0 << endl;
			continue;
		}
		else
		{
			double  potential = (double)S/L, chances = 1.0;
			for (int i = 0; i < L; ++i)
			{
				chances *= k[(int)(target[i]-65)]/((double)K * 1.0);
			}
			out << "Case #" << j+1 << ": " << (potential - (chances*potential)) << endl;
		}
	}

}

