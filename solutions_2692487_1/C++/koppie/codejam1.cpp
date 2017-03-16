//============================================================================
// Name        : codejam1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		long long A;
		int N;
		cin >> A >> N;
		vector<int> motes;
		int tmp;
		for (int i = 0; i < N; ++i){
			cin >> tmp;
			motes.push_back(tmp);
		}
		sort(motes.begin(), motes.end());
		int result = N;
		int prev = N;
		if (A == 1){
			cout << "Case #" << t << ": " << N << endl;
			continue;
		}
		for(vector<int>::iterator iter = motes.begin(); iter != motes. end(); ++iter){
			int numberNewMotes = 0;
			while(A <= *iter){
				A = 2*A -1;
				++ numberNewMotes;
			}
			A += *iter;
			prev = prev - 1 + numberNewMotes;
			*iter = prev;
		}

		for(vector<int>::iterator iter = motes.begin(); iter != motes. end(); ++iter){
			if (*iter < result)
				result = *iter;
		}
		cout << "Case #" << t << ": " << result << endl;
	}
	return 0;
}
