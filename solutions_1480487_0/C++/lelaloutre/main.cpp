#include <iostream>
#include <fstream>
#include <iomanip>

int main (int argc, const char * argv[])
{
    using namespace std;
    
    ifstream inf("Input.dat");
    ofstream outf("Output.dat");
    
    if ( !inf || !outf ) {
        cout << "Argh...\n";
        return 1;
    }

	outf.precision(6);
	
	unsigned int nTest;
	inf >> nTest;

	for ( unsigned int i = 0 ; i < nTest ; i++ ) 
	{		
		outf << "Case #" << (i+1)<< ": ";
		
		unsigned int n = 0;
		long double s[200];
		
		inf >> n;
		long double X = 0;

		for ( unsigned int j = 0 ; j < n ; j++ )
		{
			inf >> s[j];
			X += s[j];
		}
		
		bool redo = true;
		long double Y = 0.0;
		long double Z = 0.0;
		unsigned int m = 0;
		
		while(redo){
			redo = false;
			Y = 0.0;
			Z = 0.0;
			m = 0;

			for( unsigned int j = 0 ; j < n ; j++ )
			{
				if ( s[j] >= 0 ) 
				{
					m++;
					Z += s[j];
				}
			}
			
			Y = (X+Z) / m;
			
			for( unsigned int j = 0 ; j < n ; j++ )
			{
				if ( Y < s[j] )
				{
					s[j] = -1.0;
					cout << i+1 << ", " << j+1 <<" -\n";
					redo = true;
				}
			}
		}
		
		for( unsigned int j = 0 ; j < n ; j++ )
		{
			if( s[j] < 0 ) s[j] = 0;
			else s[j] = 100* (Y-s[j]) / X;
		}
	
		for ( unsigned int j = 0 ; j < n-1 ; j++ )
			outf << fixed << s[j] << " ";
		
		outf << s[n-1] << "\n";
	}
	
    return 0;
}

