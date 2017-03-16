#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int k, l, s;

int sum;
int max;

string kk, ll;
char word[10];

int matoj[10];

int countVhod()
{
	int ans = 0;
	for (size_t i = 0; i <= s - l; i++)
	{
		bool t = true;
		for (size_t j = 0; j < l; j++)
			if (word[i + j] != ll.at(j))
			{
				t = false;
				break;
			}
		if (t)
			ans++;
	}
	return ans;
}

void rec(int dep)
{
	if (dep >= s)
	{
		int cv = countVhod();
		matoj[cv] ++;

		if (cv > max)
			max = cv;

	}
	else

	for (size_t i = 0; i < kk.length(); i++)
	{
		word[dep] = kk.at(i);
		rec(dep + 1);
	}
}

int main(int argc, char** argv)
{
	int T;

	ifstream ifile;
	ifile.open("D:/contest/codejam/B-small-attempt1.in");

	ofstream ofile;
	ofile.open("D:/contest/codejam/output1.txt");

	ifile >> T;
	double ans = 0.0;

	for (size_t i = 0; i < T; i++)
	{

		ifile >> k >> l >> s;
		ifile >> kk;
		ifile >> ll;

		sum = 0;
		max = 0;
		for (size_t j = 0; j < 10; j++)
			matoj[j] = 0;

		rec(0);

		int main = 1;
		for (size_t j = 0; j < s; j++)
			main *= kk.length();

		for (size_t j = 0; j < 10; j++)
			sum += j * matoj[j];

		ans = double(max) - (double(sum) / double(main));
		ofile.precision( 7);
		ofile << "Case #" << i + 1 << ": "<< ans << endl;
	}

	ifile.close();
	ofile.close();

	return 0;
}
