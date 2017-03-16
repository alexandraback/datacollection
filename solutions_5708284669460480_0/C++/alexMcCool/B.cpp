#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main (void)
{
	ifstream in("B.in");
	ofstream out("B.out");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	int T;
	cin >> T;
	
	for (int t = 1; t <= T; t++)
	{
		int K, L, S;
		cin >> K >> L >> S;
		
		string keys;
		cin >> keys;
		
		string target;
		cin >> target;
		
		// Scan target word to see if it can overlap itself
		
		int recurIndex = 0;
		
		for (int i = 1; i < L; i++)
		{
			for (int j = 0; j < L - i; j++)
			{
				if (target[i] != target[j]) break;
				
				if (j == L - i - 1) // match!
				{
					recurIndex = i;
				}
			}
			
			if (recurIndex > 0) break;
			
		}
		
		int Max;
		
		//cout << "recurIndex: " << recurIndex << endl;
		
		if (recurIndex == 0)
		{
			Max = S / L;
		}
		else
		{
			if (S < L)
				Max = 0;
			else
			{
				Max = 1 + (S - L) / recurIndex; 
			}
		}
		
		// search through keys for duplicates
		
		map<char, int> m;
		
		for (int i = 0; i < keys.size(); i++)
		{
			m[keys[i]]++;
		}
		
		// Check that it is actually possible to make target
		bool poss = true;
		for (int i = 0; i < L; i++)
		{
			//cout << "target[i]: " << target[i] << ", m[target[i]]: " << m[target[i]] << endl;
			if (m[target[i]] == 0)
			{
				poss = false;
				break;
			}
		}
		
		double ans;
		double E = 0;
		if (poss)
		{
			// create state vector
			
			vector<double> state(L, 0);
			state[0] = 1;
			
			
			
			for (int i = 0; i < S; i++)
			{
				// completion prob.
				double pComplete = state[L-1] * double(m[target[L-1]]) / double(K);
				E += pComplete;
				
				for (int j = L-1; j > 0; j--)
				{
					state[j] = state[j-1] * double(m[target[j-1]]) / double(K);
				}
			}
			
			ans = Max - E;
		}
		else
		{
			ans = 0;
		}
			
		cout << "Case #" << t << ": ";
		//cout << "Max: " << Max << ", E: " << E << endl;
		//cout << setprecision(9);
		cout << scientific << ans << endl;
		
		
	}
	
	return 0;
	
}