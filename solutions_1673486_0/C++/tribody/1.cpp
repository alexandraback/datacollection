#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
int main()
{
    ifstream in("small.in");
    ofstream out("small.out");
	int t, n, m, i;double p[110000];
	in >> t;
	for (int t1 = 1; t1 <= t; t1++)
	{
		in >> n >> m;
		for (i = 1; i <= n; i++)
			in >> p[i];
		double min = 1e60;
		double p1 = 1;
		for (i = 0; i <= n; i++)
		{
			int front = i;
			int length = (n - i);
			int plength = (m - i);
			double pp = (length + plength + 1) * p1 + (length + plength + 1 + m + 1) * (1 - p1);
			if (pp < min)
				min = pp;
			if (i != n)
				p1 = p1 * p[i + 1];
		}
		if (1 + m + 1 < min)
			min = 1 + m + 1;
		out << "Case #" << t1 << ": ";
		char s[100];
		sprintf(s,"%.7lf", min);
		out <<s<<endl;
	}
}
