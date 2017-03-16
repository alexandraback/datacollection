#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<long> allsol;


long reverse(long N)
{
	long rev = 0;
	long num = N;
	while(num != 0)
	{
		rev = rev * 10 + num % 10;
		num = num / 10;
	}
	return rev;
}

void solveall()
{
	const long S = 1000000;
	allsol.resize(S + 1);
	allsol[0] = 0;
	for (long i = 1; i <= S; ++i)
	{
		long revi = reverse(i);
		long revrevi = reverse(revi);
		allsol[i] = (revi < i && revrevi == i) ? min(allsol[i - 1], allsol[revi]) + 1 : allsol[i - 1] + 1;
	}
}


int solve(long N)
{
	return allsol[N];
}


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		cout << "no input file\n";
		return 0;
	}

	string fname(argv[1]);
	ifstream ifile(fname);
	ofstream ofile(fname + ".out");

	int T;
	ifile >> T;
	solveall();
	for (int i = 0; i < T; ++i)
	{
		// get the specific format 
		int N;
		ifile >> N;
		int result1 = solve(N);
		ofile << "Case #" << i + 1 << ": " << result1 << "\n";
 	}
	return 0;
}