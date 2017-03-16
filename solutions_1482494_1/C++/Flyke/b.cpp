#include <iostream.h>
#include <fstream.h>
#include <list.h>

/*
	Google Code Jam 2012
	Round 1A
	Problem B. Kingdom Rush
*/


int main(int argc, char* argv[])
{
	int T,t;
	
	int N;
	int n;
	
	int A[1000];
	int B[1000];
	
	int C[1000];
	
	int rank;
	int index;
	
	int stars;
	
	bool found;
	
	int answer;
	
	ifstream inFile;
	
	if ( argc < 2 )
	{
		inFile.open("test.in");
	}
	else
	{
		inFile.open(argv[1]);
	}
	
	if ( !inFile )
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	
	inFile >> T;

	for (t=0;t<T;t++)
	{
		inFile >> N;
		
		// can be optimized to just initialize N
		for (int i=0;i<1000;i++)
		{
			C[i] = 0;
		}
		
		for (n=0;n<N;n++)
		{
			inFile >> A[n];
			inFile >> B[n];
		}
		
		answer = 0;
		stars = 0;
		
		while (true)
		{
			
			// any valid plays this turn
			found = 0;
			
			// look for any level that gives 2 stars right away
			for (n=0;n<N;n++)
			{
				// skip already completed levels ( at 2 stars rating )
				if ( C[n] == 2 )
					continue;
				
				if ( stars >= B[n] )
				{
					// complete level
					
					// only award one more star if level was already completed.
					if ( C[n] == 0 )
					{
						stars = stars + 2;
					}
					else
					{
						stars = stars + 1;
					}
					C[n] = 2;
					found = 1;
					//cout << "Game gives 2 stars" << n << endl;
					break;
				}
			}
			
			if ( !found )
			{
				// don't just complete any level giving 1 star.
				// complete whe one with highest ranking for 2-stars
				// that way it is possible to reach a point where a game only has to be played once
				
				rank = 0;
				index = 0;
				for (n=0;n<N;n++)
				{
					// skip already played levels
					if ( C[n] != 0 )
						continue;
					
					if ( (B[n] > rank) && (stars >= A[n]) )
					{
						rank = B[n];
						index = n;
					}
						
				}
				
				if ( rank > 0 )
				{
					// complete level;
					C[index] = 1;
					found  = 1;
					stars++;
				}
				/*
				for (n=0;n<N;n++)
				{
					// skip already completed levels ( at 1 or 2 star rating )
					if ( C[n] != 0 )
						continue;
					
					if ( stars >= A[n] )
					{
						// complete level
						C[n] = 1;
						found = 1;
						stars++;
						//cout << "Game gives 1 star" << n << endl;
						break;
					}
				}
				*/
			}
			
			if ( !found )
			{
				// there was no level that could be completed.
				// buhu .. too bad
				break;
			}
			else
			{
				// number of plays
				answer++;
			}
		}
		
		if ( stars == N*2 )
		{
			cout << "Case #" << t+1 << ": " << answer << endl;
		}
		else
		{
			cout << "Case #" << t+1 << ": Too Bad" << endl;
		}
		
	}
	
	inFile.close();
	return 0;
}