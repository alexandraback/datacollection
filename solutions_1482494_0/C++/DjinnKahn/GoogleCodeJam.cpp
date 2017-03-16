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


string doit( FileReader& fin )
{
   int N = fin.readInt();
   vector<int> w = fin.readInts( N*2 );
   vector<pair<int,int>> v;
   for ( int i = 0; i < N; i++ )
      v.push_back( pair<int,int>( w[i*2+1], w[i*2] ) );
   sort( v.begin(), v.end() );

   int plays = 0;
   int stars = 0;
   while ( !v.empty() )
   {
      if ( stars >= v[0].first )
      {
         plays++;
         stars += 1 + (v[0].second>=0);
         v.erase( v.begin() );
         continue;
      }
      bool ok = false;
      for ( int i = (int)v.size()-1; i >= 0; i-- )
      {
         if ( v[i].second >= 0 && stars >= v[i].second )
         {
            v[i].second = -1;
            plays++;
            stars++;
            ok = true;
            break;
         }
      }
      if ( !ok ) return "Too Bad";
   }
   stringstream ss;
   ss << plays;   
   return ss.str();
}

void main()
{
   FileReader fin( "B-small-attempt0 (2).in" );
   FileWriter fout( "out.txt" );
   int T = fin.readInt();
   fin.readLine();
   for ( int i = 0; i < T; i++ )
   {
      stringstream ss;
      ss << "Case #" << i+1 << ": " << doit( fin ) << endl;
      fout << ss.str().c_str();
      OutputDebugStringA( ss.str().c_str() );
   }
}