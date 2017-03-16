#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <Windows.h>
#include <boost/rational.hpp>
#include <boost/tokenizer.hpp>
#include <iomanip>

using namespace std;

class FileReader : public ifstream
{
public:
   FileReader( const string& filename ) { open( filename.c_str(), ios_base::in ); }
   int readInt() { int x; *this >> x; return x; }
   vector<int> readInts( int n ) { vector<int> v(n); for ( int i = 0; i < n; i++ ) v[i] = readInt(); return v; }
   double readDouble() { double x; *this >> x; return x; }
   vector<double> readDoubles( int n ) { vector<double> v(n); for ( int i = 0; i < n; i++ ) v[i] = readDouble(); return v; }
   string readLine() { char buf[32000]; getline( buf, sizeof(buf) ); return buf; }
   //vector<string> readLines( int n ) { vector<string> v; for ( int i = 0; i < n; i++ ) v.push_back( readLine() ); return v; }
   string readString() { string x; *this >> x; return x; }
   vector<string> readStrings( int n ) { vector<string> v; for ( int i = 0; i < n; i++ ) v.push_back( readString() ); return v; }
   __int64 readInt64() { __int64 x; *this >> x; return x; }
};

vector<string> parse( const string& s, const string& delimeters = " ,\t" )
{
   vector<string> ret;
   boost::tokenizer<boost::char_separator<char>> tokens( s, boost::char_separator<char>( delimeters.c_str() ) );
   copy( tokens.begin(), tokens.end(), back_inserter( ret ) );
   return ret;
}

class FileWriter : public ofstream
{
public:
   FileWriter( const string& filename ) { open( filename.c_str(), ios_base::out ); }
   //int writeInt() { int x; *this << x; return x; }
   //int writeString( const string& str ) { *this << str; }
};


double doit( FileReader& fin )
{
   int A = fin.readInt();
   int B = fin.readInt();
   vector<double> v = fin.readDoubles( A );

   double best = B+2;
   double prob = 1;

   for ( int i = 0; i <= A; i++ )
   {
      double e = (A-i) + (B-i) + 1 + (1-prob) * (B+1);
      best = min( best, e );
      if ( i < v.size() )
         prob *= v[i];
   }

   return best;
}

void main()
{
   FileReader fin( "A-large (1).in" );
   FileWriter fout( "out.txt" );
   int T = fin.readInt();
   fin.readLine();
   for ( int i = 0; i < T; i++ )
   {
      stringstream ss;
      ss << "Case #" << i+1 << ": " << setprecision( 20 ) << doit( fin ) << endl;
      fout << ss.str().c_str();
      OutputDebugStringA( ss.str().c_str() );
   }
}