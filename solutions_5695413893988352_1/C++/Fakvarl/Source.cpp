
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <set>


using namespace std;

long long eps = 1e18;
ifstream in("tff.in");
ofstream out("out.txt");



char isEq(char a, char b)
{
	return a == '?' || b == '?' || a == b;
}

long long check(string a)
{
	long long r = 0;
	for (int i = 0; i < (int)a.size(); i++) {
		r = r * 10 + a[i] - '0';
	}
	return r;
}



string A, B;
void makeMax(string a, string b){
	long long x = check(a);
	long long y = check(b);
	if (abs(x - y) < eps ||
		abs(x - y) == eps && a < A ||
		abs(x - y) == eps && a == A && b < B) {
		A = a;
		B = b;
		eps = abs(x - y);
	}
}

string ccl(string a, char old, char nw){
	string r = a;
	for (int i = 0; i < (int)r.size(); i++){
		if (r[i] == old) r[i] = nw;
	}
	return r;

}




int main() {

	int num;
	in >> num;
	for (int test = 1; test <= num; test++)
	{
		out << "Case #" + to_string(test) + ": ";
		eps = 1e18;
		string a, b, x, y;
		in >> a >> b;
		int n = a.size();

		int mDiff;
		for (mDiff = 0; mDiff < n && isEq(a[mDiff], b[mDiff]); mDiff++)
		{
			;
		}

		//cout << mDiff << endl;
		for (int i = 0; i < mDiff; i++)
		{
			int lA, rA, lb, rb;
			if (a[i] == '?')
			{
				lA = '0';
				rA = '9';
			}
			else
			{
				lA = rA = a[i];
			}

			if (b[i] == '?')
			{
				lb = '0';
				rb = '9';
			}
			else
			{
				lb = rb = b[i];
			}

			x = a;
			y = b;
			for (int j = 0; j < i; j++)
			{
				int c;
				if (a[j] != '?' && b[j] != '?')
				{
					c = a[j];
				}
				else
				{
					if (a[j] == '?' && b[j] == '?')
					{

						c = '0';
					}
					else
					{
						c = a[j] + b[j] - '?';
					}

				}

				x[j] = y[j] = c;
			}
			//cout << x << " " << y << endl;
			for (x[i] = lA; x[i] <= rA; x[i]++)
			{
				for (y[i] = lb; y[i] <= rb; y[i]++)
				{
					makeMax(ccl(x, '?', '0'), ccl(y, '?', '9'));
					makeMax(ccl(x, '?', '9'), ccl(y, '?', '0'));
				}
			}
		}
		makeMax(ccl(a, '?', '0'), ccl(b, '?', '9'));
		makeMax(ccl(a, '?', '9'), ccl(b, '?', '0'));

		out << A << " " << B << endl;
	}
	return 0;
}