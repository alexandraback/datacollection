#include <iostream.h>
#include <fstream.h>

// Code Jam 2013
// Round 1C
// Problem A. Consonants


int is_consonant(char ch)
{
	int retval = 1;
	
	if ( ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' )
	{
		retval = 0;
	}
	return retval;
}

int main(int argc, char *argv[])
{
	int T;
	int t;
	int L;
	int n;
	string name;
	int i,j,k,l;
	int answer;
	
	
	
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
		inFile >> name;
		inFile >> n;
		
		L = name.length();
		
		for (i=0;i<L;i++)
		{
			for (j=i;j<L;j++)
			{
				// Examine string
				l = 0;
				
				/*
				cout << "n: " << n << endl;
				for (k=i;k<=j;k++)
				{
					cout << name[k];
				}
				cout << endl;
				*/
				for (k=i;k<=j;k++)
				{
					if ( is_consonant(name[k]) )
					{
						l++;
					}
					else
					{
						l = 0;
					}
					if ( l >= n )
					{
						answer++;
						//cout << "Tada. i: " << i << ", j: " << j << endl;
						break;
					}
				}
			}
		}
		
		//cout << name.length() << endl;
		
		cout << "Case #" << t+1 << ": ";
		cout << answer;
		cout << endl;
		
	}
		
		
	
	inFile.close();
	return 0;
}