#include <iostream.h>
#include <fstream.h>

// Code Jam 2014
// Qualification round
// Problem B. Cookie Clicker Alpha


int main(int argc, char *argv[])
{
	int T;
	int t;
	double C, F, X;
	double answer;
	double rate;
	
	double sum;
	double deltatime;
	double nextfarm;
	double win;
	double time;
	double newrate;
	
	int running;
	
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
		inFile >> C;
		inFile >> F;
		inFile >> X;
		
		rate = 2.0f;
		
		answer = X/rate;
		sum = 0.0f;
		time = 0.0f;
		
		/*
			At current rate what comes first,
			money to win or money to buy a farm.
			if win - done
			else
				will buying get us there faster, if yes - reiterate else done
				
		*/
		
		running = 1;
		
		while (true)
		{
			nextfarm = C/rate;
			win = X/rate;
			
			if ( nextfarm < win )
			{
				newrate = rate + F;
				if ( nextfarm + X/newrate < win )
				{
					// buy a farm
					rate = newrate;
					time = time + nextfarm;
				}
				else
				{
					// no need to buy a new farm
					// run until finished
					time = time + X/rate;
					break;
				}
			}
			else
			{
				// run until finished
				time = time + X/rate;
				break;
			}
		}
		
		
		
		cout << "Case #" << t+1 << ": ";
		std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
		std::cout.precision(7);
		cout << time;
		
		cout << endl;
		
	}
		
		
	
	inFile.close();
	return 0;
}