#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int cases = 0;
	for(int i = 0; i < T; i++)
	{
		cases++;
		int A,N;
		cin >> A >> N;
		vector<int> moles(N);
		for(int j = 0; j < N; j++)
			cin >> moles[j];
		sort(moles.begin(), moles.end());
		int result = 0;
		int current = 0;
		while((current < N)&&(moles[current] < A))
		{
			A = A + moles[current];
			current++;
		}
		if(A == 1)
			result = N - current;
		else
		{
			result = 50000;
			int operations = 0;
			for(int k = current; k < N; k++)
			{
				if(A > moles[k])
					A = A + moles[k];
				else
				{
					result = min(result, operations + N - k);
					while(A <= moles[k])
					{
						operations++;
						A = A + A - 1;
					}
					A = A + moles[k];
				}
			}
			result = min(result, operations);
		}
		cout << "Case #" << cases << ": " << result << endl;
	}
}
