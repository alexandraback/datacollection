#include <algorithm>
#include "BigIntegerLibrary.hh"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void func(ifstream& in, ofstream& out)
{
	int A, N, tmp;
	in >> A >> N;
	vector<int> m;
	for (int i = 0; i < N; i++)
	{
		in >> tmp;
		m.push_back(tmp);
	}
	sort(m.begin(), m.end());
	int res = N;
	int sum = A;
	int cur_res = 0;
	for (int i = 0; i < N; i++)
	{
		while (sum <= m[i] && cur_res < 200)
		{
			sum += sum - 1;
			cur_res++;
		}
		sum += m[i];
		res = min(res, cur_res + N - i - 1);
	}

	out << res << endl;
}

int main()
{
	ifstream in;
	in.open("D:\\code_jam_in.txt");

	ofstream out;
	out.open ("D:\\code_jam_out.txt");
	out << fixed << showpoint << setprecision(7);

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		//cout << "Case #" << t << endl;
		out << "Case #" << t << ": ";
		func(in, out);
	}

	in.close();
	out.close();
	
	return 0;
}