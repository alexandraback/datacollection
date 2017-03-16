#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stdint.h>
using namespace std;



class Scanner {
public:
	Scanner( FILE *fp ) { this->fp = fp; }
	string nextString() { skipWhiteSpace(); string res; while( 1 ){ char ch = (char)fgetc(fp); if( isWhiteSpcae( ch ) ) break; res.push_back( ch ); } skipWhiteSpace(); return res; }
	string nextLine() { string res; while( 1 ){ char ch = (char)fgetc(fp); if( ch == 0 || ch == '\n' ) break; if( ch == '\r' ) continue; res.push_back( ch ); } return res; }
	int nextInt() { int res; fscanf( fp, "%d", &res ); skipWhiteSpace(); return res; }
	char nextChar() { char res; fscanf( fp, "%c", &res ); skipWhiteSpace(); return res; }
	int64_t nextInt64() { int64_t res; fscanf( fp, "%lld", &res ); skipWhiteSpace(); return res; }
	double nextReal() { double res; fscanf( fp, "%lf", &res ); skipWhiteSpace(); return res; }
private:
	bool isWhiteSpcae( char ch ) { return ( ch == 0 || ch == ' ' || ch =='\t' || ch =='\n' || ch =='\r' ); }
	void skipWhiteSpace() { while( 1 ){ char ch = (char)fgetc(fp); if( ch == 0 ) return; if( isWhiteSpcae( ch ) ) continue; fseek(fp, -1, SEEK_CUR); break; } }
private:
	FILE *fp;
};

class CodeJamSolver {
public:
	CodeJamSolver() { this->resSeperator = string(" "); this->realOutputFormat = "%g"; }
	void run( string inFile, string outFile ) { FILE *fin = fopen( inFile.c_str(), "rt" ); FILE *fout = fopen( outFile.c_str(), "wt" ); doSolve( fin, fout ); fclose(fin); fclose(fout); }
	void run( string inFile ) { FILE *fin = fopen( inFile.c_str(), "rt" ); doSolve( fin, stdout ); }
	virtual ~CodeJamSolver() {}
protected:
	virtual void onStartNewTestCase() = 0;
	virtual void onScan( Scanner &scanner ) = 0;
	virtual void solve() = 0;
	void setRealOutputFormat( string format ) { this->realOutputFormat = format; }
	void report( int v ) { char buf[256] = {0,}; sprintf( buf, "%d", v ); if( resultString.empty() == false ) resultString += this->resSeperator; resultString += buf; }
	void report( const string &v ) { resultString += v; }
	void report( int64_t v )  { char buf[256] = {0,}; sprintf( buf, "%lld", v ); if( resultString.empty() == false ) resultString += this->resSeperator; resultString += buf; }
	void report( double v ) { char buf[256] = {0,}; sprintf( buf, this->realOutputFormat.c_str(), v ); if( resultString.empty() == false ) resultString += this->resSeperator; resultString += buf; }
private:
	void doSolve( FILE *fin, FILE *fout ) { Scanner scanner( fin );int tc = scanner.nextInt(); for( int i=1; i<= tc; i++ ){ onStartNewTestCase(); onScan( scanner ); resultString.clear(); solve(); fprintf( fout, "Case #%d: %s\n", i, resultString.c_str() ); } }
private:
	string resSeperator;
	string resultString;
	string realOutputFormat;
};


class Problem : public CodeJamSolver
{
public:
	int n;
	vector<int> judge;
	int x;
	
	virtual void onStartNewTestCase()
	{
		judge.clear();
		setRealOutputFormat("%.6lf");
	}
	
	virtual void onScan( Scanner &scanner )
	{
		n = scanner.nextInt();
		x = 0;
		for( int i=0; i<n; i++ ) {
			judge.push_back( scanner.nextInt() );
			x += judge.back();
		}
	}
	
	double getAnsFor( int index )
	{
		if( n == 1 ) return 0.0;
		
		double lhs = 0.0;
		double rhs = 1.0;
		double c = 0.5;
		
		for ( int t=0; t < 100; t++ ) {
			c = (lhs + rhs) / 2.0;
			
			double extra = (1.0-c) * x;
			double minV = 99999999.0;
			
			vector<double> t;
			for( int i=0; i<n; i++ ){
				if( i == index ) continue;
				t.push_back( (double)judge[i] );
			}
			
			sort( t.begin(), t.end() );
			for( size_t i=1; i<t.size(); i++ ){
				double diff = (t[i] - t[i-1]) * i;
				if( diff > extra ){
					diff = extra;
					extra = 0.0;
					
					minV = t[i-1] + diff / i;
					break;
				}
				
				extra -= diff;
			}
			
			if( extra > 0 ){
				minV = extra / t.size() + t.back();
			}
			
			
			double targetV = judge[index] + (c * x);
			
			if( targetV < minV )
				lhs = c;
			else
				rhs = c;
		}
		
		return c * 100.0;
	}
	
	virtual void solve()
	{
		for( int i=0; i< n; i++ ){
			report( getAnsFor( i ) );
		}
	}
};


int main()
{
	Problem problem;
//	problem.run( "input.txt" );
	problem.run( "B/A-large.in", "B/A-large.out" );
    return 0;
}


