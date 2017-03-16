#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int T, N, S, P, solution, input, index;
	cin >> T;
	vector<int> googlers;
	for(int t = 1; t <= T; ++t)
	{
		googlers.clear();
		// input
		cin >> N >> S >> P;
		for(int i = 0; i < N; ++i)
		{
			cin >> input;
			googlers.push_back(input);
		}
		// computation
		solution = 0;
		sort(googlers.begin(), googlers.end());	// (<): [0] = min, [N-1] = max
		// -- great scores
		while(((index=N-1-solution) >= 0) && (googlers[index] >= P) && (((googlers[index] - P) / 2) > (P - 2)))
			++solution;
		// -- surprising scores
		//    -- two scores can't be more then 2 apart, so 1 score = P and other 2 scores = P-2
		while(((index=N-1-solution) >= 0) && (googlers[index] >= P) && (((googlers[index] - P) / 2) >= (P - 2))  && ((S--) > 0))
			++solution;
		//
		cout << "Case #" << t << ": " << solution << '\n';
	}
	return 0;
}
