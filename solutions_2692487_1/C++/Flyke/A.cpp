#include <iostream.h>
#include <fstream.h>

// Code Jam 2013
// Round 1B
// Problem A. Osmos



int main(int argc, char *argv[])
{
	int T;
	int t;
	int A;
	int answer;
	int N;
	int motes[100];
	int i;
	int a;
	int found;
	int maxmovesrequired;
	int numextramoves;
	int movecount;
	
	ifstream inFile;
	
	//inFile.open("test.in");
	if ( argc < 2 )
	{
		cout << "No input file given!" << endl;
		exit(1);
	}
	inFile.open(argv[1]);
	if ( !inFile )
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	
	inFile >> T;
	
	for (t=0;t<T;t++)
	{
		answer = 0;
		inFile >> A;
		inFile >> N;
		for (i=0;i<N;i++)
		{
			inFile >> motes[i];
		}
		
		a = A;
		
		// we absorb all we can
		// we count the remaining motes, this is the max. moves we need
		
		// A:
		// then we attempt to add a mote and we absorb all we can
		// then we check if we can complete in less moves than the max. ( by removing extras if needed )
		// if we can complete in less than max. moves - save the number
		// increase move count and until we have hit max. extra moves we loop back to A
		// and so on until we reach the max. extra moves - and we are done - the answer being the saved number

		// Absorb all possible motes
		found = 1;
		while ( found == 1 )
		{
			found = 0;
			for (i=0;i<N;i++)
			{
				if ( (a > motes[i]) && (motes[i] > 0) )
				{
					found = 1;
					a = a + motes[i];
					motes[i] = 0;
				}
			}
		}
		
		// check if complete
		found = 1;
		for (i=0;i<N;i++)
		{
			if ( motes[i] > 0 )
			{
				// not done
				found = 0;
				break;
			}
		}
		if ( found == 0 )
		{
			maxmovesrequired = 0;
			for (i=0;i<N;i++)
			{
				if ( motes[i] > 0 )
				{
					maxmovesrequired++;
				}
			}
			answer = maxmovesrequired;
			movecount = 0;
			while (movecount<=maxmovesrequired)
			{
				// add mote of max. possible size
				a = a*2-1;
				movecount++;
				// Absorb all possible motes
				found = 1;
				while ( found == 1 )
				{
					found = 0;
					for (i=0;i<N;i++)
					{
						if ( (a > motes[i]) && (motes[i] > 0) )
						{
							found = 1;
							a = a + motes[i];
							motes[i] = 0;
						}
					}
				}
		
				// check if complete
				found = 1;
				for (i=0;i<N;i++)
				{
					if ( motes[i] > 0 )
					{
						// not done
						found = 0;
						break;
					}
				}
				if ( found == 1 )
				{
					// we are actually done, check if fewer moves than best attempt
					if ( movecount < answer )
					{
						answer = movecount;
					}
					continue;
				}
				
				// removes required
				numextramoves = 0;
				for (i=0;i<N;i++)
				{
					if ( motes[i] > 0 )
					{
						numextramoves++;
					}
				}
				
				if ( movecount + numextramoves < answer )
				{
					answer = movecount + numextramoves;
				}
				
			}
		}
		
		
		
		
			
			
			
			

		
		cout << "Case #" << t+1 << ": ";
		cout << answer;
		cout << endl;
		
	}
		
		
	
	inFile.close();
	return 0;
}