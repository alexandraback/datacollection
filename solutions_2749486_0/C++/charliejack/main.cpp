#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>

//#define USE_STDIN

using namespace std;

void foo( int x, int y, char* ans )
{
	int index = 0;

	for( int i=0; i<abs(x); i++ )
	{
		if( x > 0 ){
			ans[ index++ ] = 'W';
			ans[ index++ ] = 'E';
		} else{
			ans[ index++ ] = 'E';
			ans[ index++ ] = 'W';
		}
	}

	for( int i=0; i<abs(y); i++ )
	{
		if( y > 0 ){
			ans[ index++ ] = 'S';
			ans[ index++ ] = 'N';
		} else{
			ans[ index++ ] = 'N';
			ans[ index++ ] = 'S';
		}
	}

	ans[ index ] = '\0';
}

int main()
{

#ifdef USE_STDIN
	istream& in = cin;
#else
	ifstream infile;
	infile.open ("B-small-attempt0.in", ifstream::in);
	istream& in = infile;
#endif

	ofstream outfile;
	outfile.open("B-small-attempt0.out", ofstream::out);
	//outfile.open("A-stdin.out", ofstream::out);

    int T;
	in >> T;
	char ans[501];

	for( int i=0; i<T; i++ ){
		int x, y;
		
		in >> x;
		in >> y;
		foo( x, y, ans );

		outfile << "Case #" << i+1 << ": ";
		outfile << ans;
		outfile << endl;
	}
	
#ifdef USE_STDIN

#else
	infile.close();
#endif
	outfile.close();
}