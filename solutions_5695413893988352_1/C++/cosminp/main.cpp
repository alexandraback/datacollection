#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
using namespace std;

int main()
{
	ifstream 	f("in.txt");
	ofstream 	g("out.txt");
	int 		T, N;
	string 		a, b;

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> a >> b;

		string aa = a, bb = b;
		N = a.length();

		if (a[N-1] == '?' && b[N-1] == '?')
			a[N-1] = b[N-1] = '0';
		else if (a[N-1] == '?')
			a[N-1] = b[N-1];
		else if (b[N-1] == '?')
			b[N-1] = a[N-1];

		for (int i = N - 2; i >= 0 ; i--)
		{
			vector< pair<int, int> > c;

			if (a[i] == '?' && b[i] == '?')
			{
				c.push_back(make_pair('0', '0'));
				c.push_back(make_pair('0', '1'));
				c.push_back(make_pair('1', '0'));
			}
			else if (a[i] == '?')
			{
				if (b[i] != '0') c.push_back(make_pair(b[i]-1, b[i]));
				c.push_back(make_pair(b[i], b[i]));
				if (b[i] != '9') c.push_back(make_pair(b[i]+1, b[i]));
			}
			else if (b[i] == '?')
			{
				if (a[i] != '0') c.push_back(make_pair(a[i], a[i]-1));
				c.push_back(make_pair(a[i], a[i]));
				if (a[i] != '9') c.push_back(make_pair(a[i], a[i]+1));
			}
			else
			{
				c.push_back(make_pair(a[i], b[i]));
			}

			uint64_t 	diff = 1e18;
			string 		x, y;
			for (pair<int, int> d : c)
			{
				string u, v;

				if (d.first == d.second)
				{
					u 	 = string(a.begin() + i, a.end());
					u[0] = d.first;
					v 	 = string(b.begin() + i, b.end());
					v[0] = d.second;
				}
				else if (d.first > d.second)
				{
					u 	 = string(aa.begin() + i, aa.end());
					u[0] = d.first;
					replace(u.begin(), u.end(), '?', '0');
					v 	 = string(bb.begin() + i, bb.end());
					v[0] = d.second;
					replace(v.begin(), v.end(), '?', '9');
				}
				else
				{
					u 	 = string(aa.begin() + i, aa.end());
					u[0] = d.first;
					replace(u.begin(), u.end(), '?', '9');
					v 	 = string(bb.begin() + i, bb.end());
					v[0] = d.second;
					replace(v.begin(), v.end(), '?', '0');
				}

				uint64_t va = stoll(u);
				uint64_t vb = stoll(v);
				uint64_t vd = (va > vb) ? (va - vb) : (vb - va);

				if (vd < diff)
				{
					x = u;
					y = v;
					diff = vd;
				}
			}

			for (int j = i; j < N; j++)
			{
				a[j] = x[j-i];
				b[j] = y[j-i];
			}
		}

		g << "Case #" << test << ": " << a << " " << b << endl;
	}

	return 0;
}
