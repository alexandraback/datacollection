# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <iostream>
# include <algorithm>

using namespace std;

string a, b;
string oa, ob;


int main ()
{
	int nt, t, i[6], A, B, ansA, ansB, diff = 1e9;
	cin >> t;
	for (nt = 1; nt <= t; nt ++)
	{
		cin >> a >> b;
		diff = 1e9;
		oa = a;
		ob = b;
		if (a.size () == 1)
			a = "00" + a;
		else
			if (a.size () == 2)
				a = "0" + a;
		if (b.size () == 1)
			b = "00" + b;
		else
			if (b.size () == 2)
				b = "0" + b;
		for (i[0] = 0; i[0] < 10; i[0] ++)
		for (i[1] = 0; i[1] < 10; i[1] ++)
		for (i[2] = 0; i[2] < 10; i[2] ++)
		for (i[3] = 0; i[3] < 10; i[3] ++)
		for (i[4] = 0; i[4] < 10; i[4] ++)
		for (i[5] = 0; i[5] < 10; i[5] ++)
		{
			A = B = 0;
			if (a[0] == '?')
				A += 100 * i[0];
			else
				A += 100 * (a[0] - '0');
			if (a[1] == '?')
				A += 10 * i[1];
			else
				A += 10 * (a[1] - '0');
			if (a[2] == '?')
				A += 1 * i[2];
			else
				A += 1 * (a[2] - '0');
			if (b[0] == '?')
				B += 100 * i[3];
			else
				B += 100 * (b[0] - '0');
			if (b[1] == '?')
				B += 10 * i[4];
			else
				B += 10 * (b[1] - '0');
			if (b[2] == '?')
				B += 1 * i[5];
			else
				B += 1 * (b[2] - '0');
			///cout << A << " " << B << endl;
			if (abs (A - B) > diff)
				continue;
			if (abs (A - B) < diff)
			{
				diff = abs (A - B);
				ansA = A;
				ansB = B;
				continue;
			}
			if (A < ansA)
			{
				ansA = A;
				ansB = B;
				continue;
			}
			if (A == ansA && B < ansB)
			{
				ansA = A;
				ansB = B;
				continue;
			}	
		}
		cout << "Case #" << nt << ": ";
		if (oa.size () >= 3)
			cout << ansA / 100;
		if (oa.size () >= 2)
			cout << ansA / 10 % 10;
		if (oa.size () >= 1)
			cout << ansA % 10;
		cout << " ";
		if (ob.size () >= 3)
			cout << ansB / 100;
		if (ob.size () >= 2)
			cout << ansB / 10 % 10;
		if (ob.size () >= 1)
			cout << ansB % 10;
		cout << "\n";
	}
	return 0;
}

