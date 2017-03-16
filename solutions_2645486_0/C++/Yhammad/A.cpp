#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<string.h>
#include<utility>
#include<stdlib.h>
#include<cstdio>
using namespace std;
int mxE;
int getMx(const vector<int>& v, int index, int E, int R, int N)
{
	E = (E > mxE)? mxE : E;
	if (index >= N)
		return 0;
	int mx = 0;
	for (int i = 0; i <= E; ++ i)
	{
		mx = max(mx, v[index] * i + getMx(v, index + 1, E - i + R, R, N));
	}
	return mx;
}
int main()
{
	ifstream in ("B-small-attempt1 (2).in");
	ofstream out ("output.txt");
	int t,E, R, N, reader;
	in >> t;
	for (int z = 1; z <= t; ++ z)
	{
		in >> E >> R >> N;
		vector<int> v;
		for (int i = 0; i < N; ++ i)
		{
			in >> reader;
			v.push_back(reader);
		}
		mxE = E;
		out << "Case #" << z << ": " << getMx(v, 0, E, R, N) << endl;
	}
	return 0;
}