#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	int t;
	string S;

	cin >> t;
	for (int a0 = 1; a0<=t; a0++)
	{
		cin >> S;
		string K;
		int l = S.length();
		
		K = S[0];	
		for (int i=1;i<l;i++)
		{
			if (K[0] <= S[i])
				K = S[i] + K;
			else
				K = K + S[i]; 
		}

		cout << "Case #" << a0 << ": " << K << endl;
	}

	return 0;
}
