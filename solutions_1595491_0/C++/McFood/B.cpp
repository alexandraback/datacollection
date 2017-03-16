#include <iostream>
#include <string>
#include <map>

using namespace std;

#define for0(i,n) for( int i = 0; i < (n); i++)


void main()
{

	int T;
	cin >> T;

	for0( CASE, T)
	{
		int N;
		int S;
		int p;
		int pcount;
		int count;
		cin >> N >> S >> p;
		count = 0;
		pcount = 0;
		for0(GOOGLER, N)
		{

			int score;
			cin >> score;
			if(score == 0) //exceptional zero case
			{
				if(p == 0) {count++;}
				continue;
			}
			if (p - score/3  <= 0) //well above
			{
				count++;
				continue;
			}
			switch (p - score/3 ) //need to manipulate scores possibly
			{
				case 1:
					if(score % 3 > 0)
					{
						count++;
					} else
					{
						pcount++;
					}
					break;
				case 2:
					if(score % 3 == 2) {pcount++;}
					break;
			}

		}

		int total = count + ((pcount < S) ? pcount : S);
		cout << "Case #" << CASE + 1 << ": " << total << endl;
	}

}