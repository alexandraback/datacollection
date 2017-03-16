#include <iostream.h>
#include <fstream.h>
#include <list.h>

/*
	Google Code Jam 2012
	Round 1A
	Problem A. Password Problem
*/


int main(int argc, char* argv[])
{
	int T,t;
	int A,B;
	
	int a;

	double P[100000];
	int i;
	
	double Ps;
	
	double sum;
	double answer;
	
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
		inFile >> A;
		inFile >> B;
		
		for (a=0;a<A;a++)
		{
			inFile >> P[a];
		}
		
		//	For start the best expected number of keystrokes is pressing enter right away
		answer = B + 2.0f;
		
		//  Now we need to check for backspace any given number of times, from 0 up to A
		
		// a is the number of backspaces
		for (a=0;a<A;a++)
		{
			// probability of getting it correct is now
			Ps = 1.0f;
			for (i=0;i<A-a;i++)
			{
				Ps = Ps*P[i];
			}
			// number of keypresses if correct is now B-A+1+a*2
			// and number of keypresses if there is still an error is B-A+1+a*2 + B+1 = 2B-A+2a+2
			sum = Ps*(B-A+1+2*a) + (1.0f-Ps)*(2*B+2-A+2*a);
			
			if ( sum < answer )
			{
				answer = sum;
			}
		}
		
		
		
		cout << "Case #" << t+1 << ": ";
		cout.precision(6);
		cout << fixed << answer << endl;
	}
	
	inFile.close();
	return 0;
}