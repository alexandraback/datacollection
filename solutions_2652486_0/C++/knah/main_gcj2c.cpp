//compiler: MSVC 2010 (C++ obviously)

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj2c"

using namespace std;

int main()
{
	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;

	int r,n,m,k;
	in >> r >> n >> m >> k;

	out << "Case #1:";

	for(int i = 0; i < r; i++)
	{
		out << "\n";
		int probabilities[9];
		int mins[9];
		for(int j = 0; j < 9; j++)
		{
			probabilities[j] = 0;
			mins[j] = 0;
		}

		for(int j = 0; j < k; j++)
		{
			int v;
			in >> v;
			for(int jj = 2; jj < 9; jj++)
			{
				int vv = v;
				if(v%jj == 0)
					probabilities[jj]++;

				int cm = 0;
				while(vv && vv%jj == 0)
				{
					cm++;
					vv /= jj;
				}

				mins[jj] = max(cm,mins[jj]);
			}
		}

		//the 'mins' value is always exact for 5 and 7. why? because fork!
		int nums_left = n-mins[5]-mins[7];
		for(int j = 0; j < mins[5]; j++)
			out << "5";
		for(int j = 0; j < mins[7]; j++)
			out << "7";

		if(nums_left == 0)
			continue;

		//what else do we have left...
		if(nums_left == mins[6] && m > 5) //hey, we can just fit all those 6s!
		{
			for(int j = 0; j < mins[6]; j++)
				out << "6";

			continue;
		}
		if(nums_left == 1) //still easy
		{
			if(mins[2])
				if(mins[4]) //we'll go for 4
					if(mins[8]) //or better for 8
						out << "8";
					else
						out << "4";
				else
					out << "2";
			else
				out << "3";

			continue;
		}

		if(mins[2] == 0) //easyyy!
		{
			for(int j = 0; j < nums_left; j++)
				out << "3";

			continue;
		}

		//if(mins[3] == 0) //hard! hard! hard!
		{
			/*if(mins[8] == 0) //no hint to 8s
			{
				if(mins[4] == 0 || probabilities[4] < probabilities[2]/4) //no hint to fours
				{
					for(int j = 0; j < nums_left; j++) //2s, for sure!
						out << "2";
				}
				else
				{
					probabilities[2] /= 2;
					float pct4 = 
				}
			} else {

			}*/

			/*if(mins[8])
			{
				probabilities[4] -= probabilities[8];
				probabilities[2] -= probabilities[8];
			}
			if(mins[4])
			{
				probabilities[2] -= probabilities[4];
			}
			if(mins[6])
			{
				probabilities[3] -= probabilities[6];
				probabilities[2] -= probabilities[6];
			}

			int psum = probabilities[2]+probabilities[3]+probabilities[4]+probabilities[6]+probabilities[8];*/
			
			for(int i = 0; m > 5 && i < mins[6]; i++)
				out << "6"; //huh?

			if(m > 5)
				nums_left -= mins[6];

			for(int i = 0; i < mins[3] && nums_left > 0; i++, nums_left--)
				out << "3"; //huh?

			for(int i = 0; m > 5 && i < mins[8] && nums_left > 0; i++, nums_left--)
				out << "8"; //huh?

			for(int i = 0; i < mins[4] && nums_left > 0; i++, nums_left--)
				out << "4"; //huh?

			for(int i = 0; i < mins[2] && nums_left > 0; i++, nums_left--)
				out << "2"; //huh?

			while(nums_left > 0 && mins[2])
			{
				out << "2";
				nums_left--;
			}

			while(nums_left > 0 && mins[3])
			{
				out << "3";
				nums_left--;
			}

			//yep, I hate 4 and 8. and 6 partially too. why? because fork!

			continue;
		}
	
		
	}

	out.close();
	return 0;
}