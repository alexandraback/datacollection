#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#define LL long long

using namespace std;

vector<LL> motes;

LL solve(LL A, LL pos);

int main()
{
	ifstream in;
	ofstream out;
	in.open("problemA-large.txt");
	out.open("problemA-large-result.txt");

	int T;
	in >> T;
	for(int t = 1; t <= T; t++)
	{
		LL A, N;
		in >> A >> N;
		motes.clear();
		for(int i = 0; i < N; i++)
		{
			LL temp;
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

LL solve(LL A, LL pos)
{
	LL size = motes.size();
	if(pos == size) return 0;
	if(A > motes[size - 1]) return 0;
	if(A > motes[pos]) return solve(A + motes[pos], pos + 1);

	LL res;
	if(A != 1) res = solve(2*A - 1, pos) + 1;
	else res = 1000;

	return min(res, size - pos);
}