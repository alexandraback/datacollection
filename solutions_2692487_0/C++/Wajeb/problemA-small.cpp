#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

vector<int> motes;

int solve(int A, int pos);

int main()
{
	ifstream in;
	ofstream out;
	in.open("problemA-small.txt");
	out.open("problemA-small-result.txt");

	int T;
	in >> T;
	for(int t = 1; t <= T; t++)
	{
		int A, N;
		in >> A >> N;
		motes.clear();
		for(int i = 0; i < N; i++)
		{
			int temp;
			in >> temp;
			motes.push_back(temp);
		}
		sort(motes.begin(), motes.end());

		out << "Case #" << t << ": " << solve(A, 0) << endl;
	}

	in.close();
	out.close();

	return 0;
}

int solve(int A, int pos)
{
	int size = motes.size();
	if(pos == size) return 0;
	if(A > motes[size - 1]) return 0;
	if(A > motes[pos]) return solve(A + motes[pos], pos + 1);

	int res;
	if(A != 1) res = solve(2*A - 1, pos) + 1;
	else res = 1000;

	return min(res, size - pos);
}