#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

#define ulong unsigned long long int

using namespace std;

int operationsRequired(ulong A, int N, vector<ulong>& motes, int i)
{	
	if (i == N)
		return 0;
	
	if (A > motes[i])
	{
		A+=motes[i];
		return operationsRequired(A,N,motes,i+1);
	}
	
	// Si no puedo agregar nada para que A crezca, elimino el resto.
	if (A == 1)
		return N - i;
		
	int option1 = 1 + operationsRequired(A+(A-1), N, motes, i);
	int option2 = N - i;
	return min(option1, option2);
}

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cout << "Case #" << (t+1) << ": ";
		
		int N;
		ulong A;
		
		cin >> A >> N;
		vector<ulong> motes(N);
		for (int i = 0; i < N; ++i)
			cin >> motes[i];
		sort(motes.begin(), motes.end());
			
		cout << operationsRequired(A,N,motes,0);

		cout << endl;
	}
	return 0;
}
