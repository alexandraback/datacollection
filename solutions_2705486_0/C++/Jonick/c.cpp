#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
#include <fstream>
#include <set>

using namespace std;

ifstream dicts( "dictionary.txt" );

set<string> ss;

const int INF = 6000;

void solveTest()
{
	string s;
	cin >> s;
	vector< vector<int> > dp( s.length() + 1, vector<int>( 6, INF ) );
	dp[0][5] = 0;
	for( int i = 0; i < s.length(); i++ ) {
		for( int p1 = 0; p1 < 5; p1++ ) {
			for( int p2 = 5; p2 < 10; p2++ ) {
				if( p2 - p1 < 5 ) continue;
				for( char c1 = 'a'; c1 <= 'z'; c1++ ) {
					for( char c2 = 'a'; c2 <= 'z'; c2++ ) {
						for( int len = 1; len <= 10; len++ ) {
							if( len + i > s.length() ) continue;
							string subst = s.substr( i, len );
							int nPos = subst.length();
							bool isOver = false;
							int count = 0;
							if( p1 < subst.length() ) {
								if( subst[p1] != c1 ) {
									count++;
								}
								subst[p1] = c1;
								nPos = subst.length() - p1;
								isOver = true;
							}
							if( p2 < subst.length() ) {
								if( subst[p2] != c2 ) {
									count++;
								}
								subst[p2] = c2;
								nPos = subst.length() - p2;
								isOver = true;
							}
							if( ss.find( subst ) != ss.end() ) {
								for( int j = 0; j <= 5; j++ ) {
									if( p1 + j < 5 ) continue;
									int newPos = nPos;
									if( !isOver ) {
										newPos = j + subst.length();
									}
									newPos = min(newPos, 5);
									dp[i + subst.length()][newPos] = min( dp[i + subst.length()][newPos], dp[i][j] + count );
								}
							}
						}
					}
				}
			}
		}
	}
	int res = INF;
	for( int i = 0; i < dp[s.length()].size(); i++ ) {
		res = min( res, dp[s.length()][i] );
	}
	cout << res << endl;
}

void readDict()
{
	string s;
	int len = 0;
	int count = 0;
	while( !dicts.eof() ) {
		dicts >> s;
		count++;
		if( count % 10000 == 0 ) {
			cerr << count << endl;
		}
		len = max( len, (int)s.length() );
		ss.insert(s);
	}
	cerr << len << endl;
}

void run()
{
	int tn;
	cin >> tn;
	readDict();
	for( int i = 0; i < tn; i++ ) {
		cout << "Case #" << (i+1) << ": ";
		solveTest();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	run();
	return 0;
}