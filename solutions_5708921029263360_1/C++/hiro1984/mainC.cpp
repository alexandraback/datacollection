#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;

int JP[10][10];
int PS[10][10];
int JS[10][10];
int JPS[10][10][10];

string solve(int J, int P, int S, int K)
{
	memset( JP , 0, 10 * 10 * sizeof(int) );
	memset( PS , 0, 10 * 10 * sizeof(int) );
	memset( JS , 0, 10 * 10 * sizeof(int) );
	memset( JPS, 0, 10 * 10 * 10 * sizeof(int) );
	stringstream ans;
	stringstream fashion;

	int n = 0;
	int minK = 0;

	while( minK < K ) {
		bool exist = false;
		for(int j = 0; j < J; j++ ) {
			for( int p = 0; p < P; p++ ) {
				for( int s = 0; s < S; s++ ) {
					if( JPS[j][p][s] == 0 && JP[j][p] <= minK && PS[p][s] <= minK && JS[j][s] <= minK && j != p && p != s && j != s ) {
						exist = true;
						JPS[j][p][s]++;
						JP[j][p]++;
						PS[p][s]++;
						JS[j][s]++;
						n++;
						fashion << '\n' << j + 1 << ' ' << p + 1 << ' ' << s + 1;
						goto loop_end;
					}
				}
			}
		}
		for(int j = 0; j < J; j++ ) {
			for( int p = 0; p < P; p++ ) {
				for( int s = 0; s < S; s++ ) {
					if( JPS[j][p][s] == 0 && JP[j][p] <= minK && PS[p][s] <= minK && JS[j][s] <= minK && ( j != p || p != s || j != s ) ) {
						exist = true;
						JPS[j][p][s]++;
						JP[j][p]++;
						PS[p][s]++;
						JS[j][s]++;
						n++;
						fashion << '\n' << j + 1 << ' ' << p + 1 << ' ' << s + 1;
						goto loop_end;
					}
				}
			}
		}
		for(int j = 0; j < J; j++ ) {
			for( int p = 0; p < P; p++ ) {
				for( int s = 0; s < S; s++ ) {
					if( JPS[j][p][s] == 0 && JP[j][p] <= minK && PS[p][s] <= minK && JS[j][s] <= minK ) {
						exist = true;
						JPS[j][p][s]++;
						JP[j][p]++;
						PS[p][s]++;
						JS[j][s]++;
						n++;
						fashion << '\n' << j + 1 << ' ' << p + 1 << ' ' << s + 1;
						goto loop_end;
					}
				}
			}
		}
		loop_end:
		if( !exist ) {
			minK++;
		}
	}

	ans << n;
	ans << fashion.str();

	return ans.str();
}

int main(int argc, char *argv[]) {

    int T, J, P, S, K;

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);

    string line;
    std::getline(ifs, line);
    T = stoi(line);

    for( int i = 1; i <= T; i++ ) {
    	std::getline(ifs, line);
    	stringstream ss(line);
    	ss >> J >> P >> S >> K;
    	ofs << "Case #" << i << ": " << solve(J, P, S, K) << endl;
    }

    ifs.close();
    ofs.close();

    return 0;
}







