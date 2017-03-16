#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int c, d, v, d2, qq;

int sum;
int max;

string kk, ll;
char word[10];

int a[6];
bool aa[100000];
bool gt = false;

void rec(int dep, int sum)
{
	if (sum < 100000)
	aa[sum] = true;
	if (dep < d2)
	{
		rec(dep + 1, sum + a[dep]);
		rec(dep + 1, sum);
	}
}

void rec2(int dep)
{
	if (gt)
		return;

	if (dep >= qq)
	{
		for (size_t i = 1; i <= v; i++)
			aa[i] = false;
		d2 = d + dep;
		rec(0, 0);

		gt = true;
		for (size_t i = 1; i <= v; i++)
			if (aa[i] == false)
			{
				gt = false;
				break;
			}
	} else

	for (size_t i = 1; i <= v; i++)
	{
		bool t = true;
		for (size_t j = 0; j < d + dep; j++)
			if (i == a[j])
				t = false;

		if (t)
		{
			a[d + dep] = i;
			rec2(dep + 1);
		}
	}
}

int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/C-small-attempt0.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output1.txt");

	ifile >> T;

	for (size_t i = 0; i < T; i++)
	{
		int ans = 0;

		ifile >> c >> d>> v;
		for (size_t i = 0; i < d; i++)
			ifile >> a[i];

		gt = false;
		for (qq = 0; qq < v; qq++)
		{
			rec2(0);
			if (gt)
				break;
			ans += 1;
		}

		ofile << "Case #" << i + 1 << ": "<< ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}
