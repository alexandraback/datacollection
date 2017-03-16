#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void main() {
	int t, J, P, S, K;	
	int* arrShownJP	= new int[100];
	int* arrShownJS	= new int[100];
	int* arrShownPS	= new int[100];
	string str;
	cin >> t;  // read t. cin knows that t is an int, so it reads it as such.	
	for (int i = 1; i <= t; ++i) {
		for( int v = 0; v < 100; v++ )
		{
			arrShownJP[v]	= 0;
			arrShownJS[v]	= 0;
			arrShownPS[v]	= 0;
		}
		
		cin >> J;
		cin >> P;
		cin >> S;
		cin >> K;

		int iTotCount1 = 0;
		stringstream ss1;
		for( int j = 1; j <= J; j++ )
		{	
			for( int p = 1; p <= P; p++ )
			{
				if( j % 2 == 1 )
				{
					for( int s = 1; s <= S; s++ )
					{				
						int jpVal	= j * 10 + p;
						int jsVal	= j * 10 + s;
						int psVal	= p * 10 + s;
						if( arrShownJP[jpVal] == K || arrShownJS[jsVal] == K || arrShownPS[psVal] == K )
						{
							continue;
						}
						arrShownJP[jpVal]++;
						arrShownJS[jsVal]++;
						arrShownPS[psVal]++;

						iTotCount1++;
						ss1 << j << " " << p << " " << s << endl;
					}
				}
				else
				{
					for( int s = S; s >= 1; s-- )
					{			
						int jpVal	= j * 10 + p;
						int jsVal	= j * 10 + s;
						int psVal	= p * 10 + s;
						if( arrShownJP[jpVal] == K || arrShownJS[jsVal] == K || arrShownPS[psVal] == K )
						{
							continue;
						}
						arrShownJP[jpVal]++;
						arrShownJS[jsVal]++;
						arrShownPS[psVal]++;

						iTotCount1++;
						ss1 << j << " " << p << " " << s << endl;
					}
				}
			}
		}


		cout << "Case #" << i << ": " << iTotCount1 << endl;
		cout << ss1.str();

	
    }

}