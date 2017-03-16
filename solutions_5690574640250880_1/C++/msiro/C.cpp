#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;
#pragma warning(disable: 4996)

#define OUTPUTLOG2(X,Y)\
{\
	char msg[1024];\
	sprintf( msg, X, Y );\
	OutputDebugString(msg);\
}
#define OUTPUTLOG OutputDebugString

#define FOR(r,a,b) for(r=(a); r<(b); r++)
#define REP(r,b) for(r=0; r<(b); r++)
#define TRV(type,cnt,it) for(type::iterator it=(cnt).begin(); it!=(cnt).end(); it++)

void main(int argc, char*argv[]) // usage: main.exe in.txt out.txt
{
	int i,j,k,l,m,n;

	ifstream fin(argv[1]);
	if( fin == NULL ){
		OUTPUTLOG2("cannot open in-file : %s\n", argv[1]);
		return;
	}
	FILE* fout = fopen(argv[2],"w");
	if( fin == NULL ){
		OUTPUTLOG2("cannot open out-file : %s\n", argv[2]);
		return;
	}

/////////////////////////////
	char line[1024];
	int CASE;
	fin >> CASE;
	for( int test_case = 1; test_case <= CASE; test_case++ ){
	/////////////////////////////
		int R,C,M;
		fin >> R;
		fin >> C;
		fin >> M;
		vector<string> ans(R, string(C, '*'));

		fprintf(fout,"Case #%d: \n", test_case);
		if( R == 1 ){
			if( M >= C ){
				fprintf(fout,"Impossible\n");
				goto end;
			}
			string ans;
			for( int i = 0; i < M; i++ )
				ans.push_back('*');
			for( int i = M; i < (C-1); i++ )
				ans.push_back('.');
			ans.push_back('c');

			fprintf(fout,"%s\n", ans.c_str());
			goto end;

		}else if( C == 1 ){
			if( M >= R ){
				fprintf(fout,"Impossible\n");
				goto end;
			}
			string ans;
			for( int i = 0; i < M; i++ )
				fprintf(fout,"*\n");
			for( int i = M; i < (R-1); i++ )
				fprintf(fout,".\n");
			fprintf(fout,"c\n");

			goto end;
		}

		if( M >= R*C ){
			fprintf(fout,"Impossible\n");
			goto end;
		}

		//////////////////////////////////////////////////////
		int nothing = R*C-M;
		int short_side = min(R, C);
		int long_side = max(R, C);
		int dots = 1;
		if( dots >= nothing ){
			goto next;
		}
		bool bTest = false;
		if( R < C ){
			for( int step = 1; step < R; step++ ){
				for( int x = 0; x < step; x++ ){
					ans[step][x] = '.';
					dots++;
					if( dots >= nothing ){
						if( x == 0 )
							bTest = true;
						goto next;
					}
				}
				for( int y = 0; y <= step; y++ ){
					ans[y][step] = '.';
					dots++;
					if( dots >= nothing ){
						if( y == 0 )
							bTest = true;
						goto next;
					}
				}
			}
			for( int x = R; x < C; x++ ){
				for( int y = 0; y < R; y++ ){
					ans[y][x] = '.';
					dots++;
					if( dots >= nothing ){
						if( y == 0 )
							bTest = true;
						goto next;
					}
				}
			}

		}else{
			for( int step = 1; step < C; step++ ){
				for( int x = 0; x < step; x++ ){
					ans[step][x] = '.';
					dots++;
					if( dots >= nothing ){
						if( x == 0 )
							bTest = true;
						goto next;
					}
				}
				for( int y = 0; y <= step; y++ ){
					ans[y][step] = '.';
					dots++;
					if( dots >= nothing ){
						if( y == 0 )
							bTest = true;
						goto next;
					}
				}
			}
			for( int y = C; y < R; y++ ){
				for( int x = 0; x < C; x++ ){
					ans[y][x] = '.';
					dots++;
					if( dots >= nothing ){
						if( x == 0 )
							bTest = true;
						goto next;
					}
				}
			}

		}
next:
		ans[0][0] = 'c';
		if( nothing == 1 )
			bTest = false;
		if( bTest ){
			int x, y;
			for( x = 0; x < C; x++ ){
				if( ans[0][x] == '*' ){
					break;
				}
			}
			x--;
			for( y = 0; y < R; y++ ){
				if( ans[y][0] == '*' ){
					break;
				}
			}
			y--;
			if( x >= y ){
				if( y < 2 || x < 3 ){
					fprintf(fout,"Impossible\n");
					goto end;
				}
				ans[1][x] = '.';
				ans[y][x-1] = '*';

			}else{
				if( x < 2 || y < 3 ){
					fprintf(fout,"Impossible\n");
					goto end;
				}
				ans[y][1] = '.';
				ans[y-1][x] = '*';
			}
		}

		for( int i = 0; i < R; i++ ){
			fprintf( fout, "%s\n", ans[i].c_str() );
		}

	/////////////////////////////
end:
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}