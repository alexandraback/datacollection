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

int R[50][50];

string solve(int B, int M)
{
	memset(R, 0, 50 * 50 * sizeof(int));
	stringstream ans;
	int num = 0;
	while( num != M ) {
		if( R[0][B-1] == 0 ) {
			R[0][B-1] = 1;
			num++;
		} else {
			for( int i = 0; i < B; i++ ) {
				for ( int j = B - 1; j > 0; j-- ) {
					if( i == j ) continue;
					if( i == 0 && R[i][j] == 0 ) {
						R[i][j] = 1;
						R[j][B-1] = 1;
						num++;
						goto end;
					}
					if( R[i][j] == 0 ) {
						R[i][j] = 1;
						num += i;
						goto end;
					}
				}
			}
			break;
		}
		end:
		;
	}

	if ( num != M ) {
		ans << "IMPOSSIBLE" << endl;;
	} else {
		ans << "POSSIBLE" << endl;
		for( int i = 0; i < B; i++ ) {
			for ( int j = 0; j < B; j++ ) {
				ans << R[i][j] << " ";
			}
			ans << endl;
		}
	}

	return ans.str();
}

int main(int argc, char *argv[]) {

    int T, B, M;

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2]);

    string line;
    std::getline(ifs, line);
    T = stoi(line);

    for( int i = 1; i <= T; i++ ) {
    	std::getline(ifs, line);
    	stringstream ss(line);
    	ss >> B >> M;
    	ofs << "Case #" << i << ": " << solve(B, M);
    }

    ifs.close();
    ofs.close();

    return 0;
}







