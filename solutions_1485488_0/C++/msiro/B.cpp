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

struct pos {
	int x;
	int y;
	int water_level;
	double min_time;
};
struct less_pos
{
bool operator()(const pos& _Left, const pos& _Right) const
{
	return (_Left.min_time < _Right.min_time);
}
};		

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
		int H,N,M;
		fin >> H;
		fin >> N;
		fin >> M;
		vector<vector<int>> ceil(N,vector<int>(M));
		vector<vector<int>> floor(N,vector<int>(M));
		FOR( i, 0, N ){
			FOR( j, 0, M ){
				fin >> ceil[i][j];
			}
		}
		FOR( i, 0, N ){
			FOR( j, 0, M ){
				fin >> floor[i][j];
			}
		}

		vector<vector<double>> min_time(N,vector<double>(M,DBL_MAX));
		double time = 0.0;
		multiset<pos, less_pos> search;
		multiset<pos, less_pos>::iterator it;

		struct pos p = {0,0,H,0.0};
		min_time[0][0] = 0.0;
		bool bNoWait = true;
		search.insert(p);

		int cnt = 0;
		while(!search.empty()){
			cnt++;
			struct pos t = *search.begin();
			search.erase(search.begin());
			if( t.x == M-1 && t.y == N-1 ){
				time = t.min_time;
				break;
			}
			int water_level = t.water_level;

			//up
			if( t.y > 0 ){
				int nx = t.x;
				int ny = t.y-1;

				if( ceil[ny][nx] - floor[ny][nx] >= 50 && ceil[ny][nx] - floor[t.y][t.x] >= 50 && ceil[t.y][t.x] - floor[ny][nx] >= 50 ){
					double tm = 0.0;
					int new_water_level = water_level;
					if( water_level == H )
						bNoWait = true;
					else
						bNoWait = false;
					if( ceil[ny][nx] - water_level <= 50 ){
						bNoWait = false;
						tm = (water_level - (ceil[ny][nx] - 50))/10.0;
						new_water_level = ceil[ny][nx] - 50;
					}
					if( bNoWait )
						tm = 0.0;
					else{
						if( new_water_level - floor[t.y][t.x] >= 20 ){
							tm += 1.0;
							new_water_level -= 10;
						}else{
							tm += 10.0;
							new_water_level -= 100;
						}
						tm += t.min_time;
					}

					if( min_time[ny][nx] > tm ){
						min_time[ny][nx] = tm;
						if( !search.empty() ){
							for( it = search.begin(); it != search.end(); it++ ){
								if( it->x == nx && it->y == ny ){
									search.erase(it);
									break;
								}
							}
						}
						struct pos np = {nx, ny, new_water_level, tm};
						search.insert(np);
					}
				}
			}

			//down
			if( t.y < N-1 ){
				int nx = t.x;
				int ny = t.y+1;

				if( ceil[ny][nx] - floor[ny][nx] >= 50 && ceil[ny][nx] - floor[t.y][t.x] >= 50 && ceil[t.y][t.x] - floor[ny][nx] >= 50 ){
					double tm = 0.0;
					int new_water_level = water_level;
					if( water_level == H )
						bNoWait = true;
					else
						bNoWait = false;
					if( ceil[ny][nx] - water_level <= 50 ){
						bNoWait = false;
						tm = (water_level - (ceil[ny][nx] - 50))/10.0;
						new_water_level = ceil[ny][nx] - 50;
					}
					if( bNoWait )
						tm = 0.0;
					else{
						if( new_water_level - floor[t.y][t.x] >= 20 ){
							tm += 1.0;
							new_water_level -= 10;
						}else{
							tm += 10.0;
							new_water_level -= 100;
						}
						tm += t.min_time;
					}

					if( min_time[ny][nx] > tm ){
						min_time[ny][nx] = tm;
						if( !search.empty() ){
							for( it = search.begin(); it != search.end(); it++ ){
								if( it->x == nx && it->y == ny ){
									search.erase(it);
									break;
								}
							}
						}

						struct pos np = {nx, ny, new_water_level, tm};
						search.insert(np);
					}
				}
			}

			//left
			if( t.x > 0 ){
				int nx = t.x-1;
				int ny = t.y;

				if( ceil[ny][nx] - floor[ny][nx] >= 50 && ceil[ny][nx] - floor[t.y][t.x] >= 50 && ceil[t.y][t.x] - floor[ny][nx] >= 50 ){
					double tm = 0.0;
					int new_water_level = water_level;
					if( water_level == H )
						bNoWait = true;
					else
						bNoWait = false;
					if( ceil[ny][nx] - water_level <= 50 ){
						bNoWait = false;
						tm = (water_level - (ceil[ny][nx] - 50))/10.0;
						new_water_level = ceil[ny][nx] - 50;
					}
					if( bNoWait )
						tm = 0.0;
					else{
						if( new_water_level - floor[t.y][t.x] >= 20 ){
							tm += 1.0;
							new_water_level -= 10;
						}else{
							tm += 10.0;
							new_water_level -= 100;
						}
						tm += t.min_time;
					}

					if( min_time[ny][nx] > tm ){
						min_time[ny][nx] = tm;
						if( !search.empty() ){
							for( it = search.begin(); it != search.end(); it++ ){
								if( it->x == nx && it->y == ny ){
									search.erase(it);
									break;
								}
							}
						}
						struct pos np = {nx, ny, new_water_level, tm};
						search.insert(np);
					}
				}
			}

			//right
			if( t.x < M-1 ){
				int nx = t.x+1;
				int ny = t.y;

				if( ceil[ny][nx] - floor[ny][nx] >= 50 && ceil[ny][nx] - floor[t.y][t.x] >= 50 && ceil[t.y][t.x] - floor[ny][nx] >= 50 ){
					double tm = 0.0;
					int new_water_level = water_level;
					if( water_level == H )
						bNoWait = true;
					else
						bNoWait = false;
					if( ceil[ny][nx] - water_level <= 50 ){
						bNoWait = false;
						tm = (water_level - (ceil[ny][nx] - 50))/10.0;
						new_water_level = ceil[ny][nx] - 50;
					}
					if( bNoWait )
						tm = 0.0;
					else{
						if( new_water_level - floor[t.y][t.x] >= 20 ){
							tm += 1.0;
							new_water_level -= 10;
						}else{
							tm += 10.0;
							new_water_level -= 100;
						}
						tm += t.min_time;
					}

					if( min_time[ny][nx] > tm ){
						min_time[ny][nx] = tm;
						if( !search.empty() ){
							for( it = search.begin(); it != search.end(); it++ ){
								if( it->x == nx && it->y == ny ){
									search.erase(it);
									break;
								}
							}
						}
						struct pos np = {nx, ny, new_water_level, tm};
						search.insert(np);
					}
				}
			}
		}


	/////////////////////////////
		fprintf(fout,"Case #%d: %lf\n", test_case, time);

		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}