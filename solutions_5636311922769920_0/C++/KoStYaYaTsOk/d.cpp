#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include<string>
#include<algorithm>

using namespace std;

#define mp make_pair
#define pb push_back 
#define fi(n) for(int i = 0; i < n; i++)
#define fj(n) for(int j = 0; j < n; j++)
#define ll long long
#define itt ::iterator it = 

ifstream in;
ofstream out;

int main()
{
	int n;
	in.open("input.in");
	out.open("d_small.txt");
	in >> n;

	for (int g = 1; g <= n; g++)
	{
		out << "Case #" << g << ": ";

		int k, c, s;
		in >> k >> c >> s;

		if (s * c < k)
		{
			out << "IMPOSSIBLE" << endl;
			continue;
		}

		int k1 = 0;

		fj(s)
		{
			ll answ = 0;
			ll st = 1;

			fi(c)
			{
				answ += k1 * st;
				st *= k;
				k1++;
				if (k1 >= k) break;
			}
			out << answ + 1 << " ";
			if (k1 >= k) break;
		}
		out << endl;
	}

	return 0;
}

