#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <queue>
#include <map>

using namespace std;
typedef unsigned long long int LL;

int main()
{
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int B;
		LL M;
		cin >> B >> M;
		
		cout << "Case #" << (t+1) << ": ";
		
		LL m = (1 << (B-2));
		if(M > m)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << "POSSIBLE" << endl;
			if(M == m)
			{
				cout << "0";
				for(int i = 1; i < B; i++)
					cout << "1";
				cout << endl;
				
				for(int i = 1; i < B; i++)
				{
					for(int j = 0; j <= i; j++)
						cout << "0";
					for(int j = i + 1; j < B; j++)
						cout << "1";
					cout << endl;
				}
			
			}
			else
			{
				vector<bool> dec(B);
				int i = B - 1;
				for(LL x = M; x > 0 && i > 0; x /= 2, i--)
				{
					dec[i] = ((x % 2) == 1);
				}
				cout << "0";
				for(int i = 1; i < B-1; i++)
					cout << ((dec[i+1])? "1" : "0");
				cout << "0";
				cout << endl;

				

				for(int i = 1; i < B; i++)
				{
					for(int j = 0; j <= i; j++)
						cout << "0";
					for(int j = i + 1; j < B; j++)
						cout << "1";
					cout << endl;
				}
			}
		}			
	}
	
	return 0;
}
