// Google Code Jam 2012
// Problem A. Safety in Numbers

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_N 200


int main(int argc, char* argv[])
{
	//freopen("sample.in", "r", stdin);
	int T;
	cin >> T;
	for(int t=0; t<T; t++)
	{
		int N;
		cin >> N;

		vector<int> J;
		int X=0;
		for(int i=0; i<N; i++) 
		{
			int s;
			cin >> s;
			J.push_back(s);
			X += s;
		}
		vector<int> sortedJ = J;
		sort(sortedJ.begin(), sortedJ.end());

		cout << "Case #" << t+1 << ": ";
		for(int i=0; i<N; i++)
		{
			int threshold = J[i];
			double S;
			while(true)
			{
				S = X;
				int n = 0;
				for(int j=0; j<N; j++)
					if(J[j] <= threshold) {
						S+= J[j];
						n++;
					}
				S /= n;

				int min = X;
				for(int j=0; j<N; j++)
					if(J[j] > threshold && J[j] < S) {
						if(min > J[j]) min = J[j];
					}
				if(min != X) threshold = min;
				else break;
			}
			double Yi = (S - J[i]) / X;
			if(Yi < 0) Yi=0;
			cout.precision(8);
			cout << 100*Yi ; // <<"(" << threshold <<"," << S << ")";
			if(i < N-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}

