#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

int cleanup (vector<int> &mote,vector<int> &opera, int A,int i,int N)
{
	while(i<N)
	{
		while (mote[i] < A && i < N)
		{
			A += mote[i];
			i++;
		}
		while (A <= mote[i] && i < N)
		{
			A = 2*A-1;
			opera[i]++;
		}
	}
}

int main (int argc, char* argv[])
{
	int T;
	cin >> T;
	for (int cas = 0; cas < T; cas += 1)
	{
		vector<int> mote(100,0);
		vector<int> opera(100,0);
		int A, N;
		cin >> A >> N;
		int result;
		for (int i = 0; i < N; i += 1)
		{
			cin >> mote[i];
		}
		if (A == 1)
		{
			cout << "Case #" << cas+1 << ": " << N << endl;
			continue;
		}
		sort(mote.begin(),mote.begin()+N);
		int i=0;
		i = cleanup(mote,opera,A,i,N);
		for (int i = 1; i < N; i += 1)
		{
			opera[i] = opera[i] + opera[i-1];
		}
		int opmin = N;
		for (int i = 0; i < N; i += 1)
		{
			opmin = min (opera[i] + N-i-1, opmin);
		}
	cout << "Case #" << cas+1 << ": " << opmin << endl;	}
	return 0;
}
