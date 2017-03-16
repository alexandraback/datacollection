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
	void report( int v, bool space = true ) { char buf[256] = {0,}; sprintf( buf, "%d", v ); if( resultString.empty() == false && space ) resultString += this->resSeperator; resultString += buf; }
	void report( const string &v, bool space = true ) { if( resultString.empty() == false && space ) resultString += this->resSeperator; resultString += v; }
	void report( int64_t v, bool space = true )  { char buf[256] = {0,}; sprintf( buf, "%lld", v ); if( resultString.empty() == false && space ) resultString += this->resSeperator; resultString += buf; }
	void report( double v, bool space = true ) { char buf[256] = {0,}; sprintf( buf, this->realOutputFormat.c_str(), v ); if( resultString.empty() == false && space ) resultString += this->resSeperator; resultString += buf; }
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
	int n, m;
	vector< pair<int, int> > box;
	vector< pair<int, int> > toy;
	map< pair<int,int>, int > dyn;
	
	virtual void onStartNewTestCase()
	{
		box.clear();
		toy.clear();
		dyn.clear();
	}
	
	virtual void onScan( Scanner &scanner )
	{
		n = scanner.nextInt();
		m = scanner.nextInt();
	
		for( int i=0; i<n; i++ ){
			int len = scanner.nextInt();
			int type = scanner.nextInt();
			box.push_back( make_pair(len,type) );
		}
		
		for( int i=0; i<m; i++ ){
			int len = scanner.nextInt();
			int type = scanner.nextInt();
			toy.push_back( make_pair(len,type) );
		}
	}
	
	int doSolve( int b, int t )
	{
		if( dyn.find( make_pair(b, t) ) != dyn.end() )
			return dyn[ make_pair(b, t) ];
		
		int fb = 0;
		int get = 0;
		int ft = 0;

		if( b < n-1 )
			fb = doSolve(b+1, t);

		if( t < m-1 )
			ft = doSolve(b, t+1);
		
		if( box[b].second == toy[t].second ){
			get = min<int>( box[b].first, toy[t].first );
			
			if( b < n-1 && t < m-1 )
				get += doSolve(b+1, t+1);
		}
		
		int v = max<int>( fb, max<int>( get, ft ) );
		dyn[ make_pair(b, t) ] = v;
		
		printf("%d, %d : %d\n", b, t, v );
		return v;
	}
	
	virtual void solve()
	{
		report( doSolve(0, 0) );
	}
};


int main()
{
	Problem problem;
//	problem.run( "input.txt" );
//	problem.run( "C/C-small-attempt0.in" );
	problem.run( "C/C-small-attempt0.in", "C/C-small-attempt0.out" );
//	problem.run( "C/C-large-practice.in", "C/C-large-practice.out" );
    return 0;
}


