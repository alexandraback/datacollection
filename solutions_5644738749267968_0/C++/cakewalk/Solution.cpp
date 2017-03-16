#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
double Naomi[1000], Ken[1000], DeceitWar, War;

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		cin >> N;
		for (int i=0; i<N; i++)
			cin >> Naomi[i];
		for (int i=0; i<N; i++)
			cin >> Ken[i];
		
		sort(Naomi, Naomi+N);
		sort(Ken, Ken+N);
		
		DeceitWar = 0;
		for (int i=N-1, j=N-1; i>=0, j>=0; )
		{
			if (Naomi[i] > Ken[j])
			{
				DeceitWar++;
				i--; j--;
			}
			else
				j--;
		}
		
		War = N;
		for (int i=N-1, j=N-1; i>=0, j>=0; )
		{
			if (Ken[i] > Naomi[j])
			{
				War--;
				i--; j--;
			}
			else
				j--;
		}
		
		cout << "Case #" << t << ": " << DeceitWar << " " << War << endl;
	}
	
	return 0;
}
