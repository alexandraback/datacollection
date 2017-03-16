#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <float.h>
#include <iomanip>
#include <ctime>
#include <stack>
//#define FOR( i, N ) for( int (i) = 0; (i) < (N); (i)++ )
//#define FOR_( i, start, endplusone ) for( int (i) = (start); (i) < (endplusone); (i)++ )
const double EPS = 1e-10;
const double PI = 3.141592653589793;
using namespace std;
#define ull unsigned long long
int main(){
	ifstream ifs( "B-small-attempt0.in" );
	ull T, A, B, K;
	ifs >> T;
	ofstream ofs( "out" );
	for( int i = 0; i < T; i++ ){
		ifs >> A >> B >> K;
		if( K > A || K > B ){
			ofs << "Case #" << i+1 << ": " << A*B << endl;
			continue;
		}
		ull accu = A*B - (A-K)*(B-K);
		for( ull j = K; j < A; j++ ){
			for( ull k = K; k < B; k++ ){
				if( (j&k) < K ){
					accu++;
				}
			}
		}
		ofs << "Case #" << i+1 << ": " << accu << endl;
	}
	ifs.close();

	//char buf[32];
	//for( int i = 0; i < T; i++ ){
	//	sprintf(buf,"%.7f", t[i] );
	//	ofs << "Case #" << i+1 << ": " << buf << endl;
	//}
	ofs.close();
	system( "pause" );
	return 0;
}
