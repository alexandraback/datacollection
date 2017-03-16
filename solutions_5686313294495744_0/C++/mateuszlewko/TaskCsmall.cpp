#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#define For(i, n) for(int i = 0; i <(n); i++)
using namespace std;

pair<string, string> A[1000];

bool test(int mask, int n)
{
	unordered_set<string> PresentL, PresentR;
	For (i, n)
		if ((mask & (1 << i)) == 0) {
			PresentL.insert(A[i].first);
			PresentR.insert(A[i].second);
		}
		
	For (i, n)
	{
		if ((mask & (1 << i)))
		{
			if (PresentL.find(A[i].first) == PresentL.end() or PresentR.find(A[i].second) == PresentR.end()) 
			{
				// cout << "false\n";
				return false;
			}
			// else
			// {
			// 	// cout << "found: " <<  *PresentL.find(A[i].first) << " " << *PresentR.find(A[i].second) << "\n";
			// }
		}
	}
	
	// cout << "mask: " << mask << "\n";
	return true;
}

int main()
{
	ios::sync_with_stdio(0);

	int t;
	cin >> t;

	For (i, t)
	{
		int n;
		cin >> n;
		int res = 0;
		
		For (j, n) {
			cin >> A[j].first >> A[j].second;
			// cout << "in: " << A[j].first << " " << A[j].second << "\n";
		}
			
		For (mask, 1 << n)
			if (test(mask, n))
				res = max(res, __builtin_popcount(mask));
				
		cout << "Case #" << i + 1 << ": " << res << "\n";
	}
}