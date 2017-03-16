#include <iostream.h>
#include <fstream.h>

// Code Jam 2013
// Round 1C
// Problem B. Pogo



int main(int argc, char *argv[])
{
	int T;
	int t;
	int X,Y;
	int x,y;
	int index;
	char solution[100000];
	
	int i,j;
	
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
		index = 0;
		solution[index] = 0;
		
		inFile >> X;
		inFile >> Y;
		
		x = 0;
		y = 0;
		
		
		{
			while ( x != X )
			{
				
				if ( x < X )
				{
					// go west then east
					solution[index++] = 'W';
					solution[index++] = 'E';
					solution[index] = 0;
					x++;
				}
				else if ( x > X )
				{
					// go east then west
					solution[index++] = 'E';
					solution[index++] = 'W';
					solution[index] = 0;
					x--;
				}
				
				if ( index > 100000-2 )
				{
					cout << "Error" << endl;
					exit(1);
				}
			}
			
			while ( y != Y )
			{
				if ( y < Y )
				{
					// go south then north
					solution[index++] = 'S';
					solution[index++] = 'N';
					solution[index] = 0;
					y++;
				}
				else if ( y > Y )
				{
					// go north then south
					solution[index++] = 'N';
					solution[index++] = 'S';
					solution[index] = 0;
					y--;
				}
				
				if ( index > 100000-2 )
				{
					cout << "Error" << endl;
					exit(1);
				}
			}
			

		}
		
		cout << "Case #" << t+1 << ": ";
		cout << solution;
		cout << endl;
		
	}
		
		
	
	inFile.close();
	return 0;
}