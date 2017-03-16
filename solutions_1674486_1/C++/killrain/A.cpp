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
	int n;
	vector< vector<int> > adj;
	
	virtual void onStartNewTestCase()
	{
		adj.clear();
	}
	
	virtual void onScan( Scanner &scanner )
	{
		n = scanner.nextInt();
		adj.assign( n, vector<int>() );
		for( int i=0; i<n; i++ ) {
			adj[i].assign(n, 9999999);
			
			int size = scanner.nextInt();
			for( int k=0; k<size; k++ ){
				adj[i][ scanner.nextInt() - 1 ] = 1;
			}
		}
	}
	
	virtual void solve()
	{
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++ ) {
					if (adj[i][j] != 9999999 && (adj[i][k] + adj[k][j]) < 9999999 ){
						report("Yes");
						return;
					}
					
					if (adj[i][j] > adj[i][k] + adj[k][j]) {
						adj[i][j] = adj[i][k] + adj[k][j];
					}
				}
			}
		}
		
		report("No");
	}
};


int main()
{
	Problem problem;
//	problem.run( "input.txt" );
	problem.run( "C/A-large.in", "C/A-large.out" );
    return 0;
}


