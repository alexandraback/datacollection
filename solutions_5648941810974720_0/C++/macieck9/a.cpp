#include<iostream>

using namespace std;

int T[260];

char A[10] = {'Z', 'X', 'S', 'V', 'F', 'W', 'R', 'H', 'O', 'I'};
int B[10] = {0, 6, 7, 5, 4, 2, 3, 8, 1, 9};
string C[10] = {"ZERO", "SIX", "SEVEN", "FIVE", "FOUR", "TWO", "THREE", "EIGHT", "ONE", "NINE"};

int ans[10];

int main()
{
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++)
	{
		string S;
		cin >> S;
		for (int i = 0; i < S.size(); i++) T[S[i]]++;
		
		for (int i = 0; i < 10; i++)
		{
			ans[B[i]] += T[A[i]];
			int x = T[A[i]];
			for (int j = 0; j < C[i].size(); j++)
				T[C[i][j]] -= x;
		}
		cout << "Case #" << t << ": ";
		for (int i = 0; i < 10; i++)
			while(ans[i])
			{
				cout << i;
				ans[i]--;
			}
		cout << "\n";
	}
	
	
	
	return 0;
}
