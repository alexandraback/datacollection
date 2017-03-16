#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>

//#define USE_STDIN

using namespace std;

bool isVowels( char c )
{
	return c == 'a' ||
		   c == 'e' ||
		   c == 'i' ||
		   c == 'o' ||
		   c == 'u';
}

long long foo( char* buf, int n )
{
	int L = strlen( buf );

	int count = 0;
	int startIndex = 0;
	long long sum = 0;
	int lastIndex = 0;

	for( int i=0; i<L; i++ ){
			
		if( !isVowels(buf[i]) ){
			if( count == 0 ) startIndex = i;
			count++;
		} else{
			count = 0;
			continue;
		}

		if( count == n ){
			sum += (L-i)*(startIndex-lastIndex+1);
			lastIndex = startIndex+1;
			startIndex++;
			count--;
		}
	}

	return sum;
}

int main()
{

#ifdef USE_STDIN
	istream& in = cin;
#else
	ifstream infile;
	infile.open ("A-large.in", ifstream::in);
	istream& in = infile;
#endif

	ofstream outfile;
	outfile.open("A-large.out", ofstream::out);
	//outfile.open("A-stdin.out", ofstream::out);

    int T;
	in >> T;
	char buf[1000001];

	for( int i=0; i<T; i++ ){
		in >> buf;
		
		int n;
		in >> n;

		outfile << "Case #" << i+1 << ": ";
		outfile << foo(buf, n );
		outfile << endl;
	}
	
#ifdef USE_STDIN

#else
	infile.close();
#endif
	outfile.close();
}