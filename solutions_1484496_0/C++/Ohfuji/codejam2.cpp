#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;
vector<int> A;
vector<int> Idx;
int SA;
int SB;


inline long long mypow(long long a, long long n )
{
	if ( n == 0 ) return 1;
	if ( n % 2 ) return a * mypow( a, n - 1);
	long long x = mypow( a, n >> 1);
	return x * x;
}

bool solve()
{
	long long end = mypow(3,N);

	for ( long long c = 0; c < end; c++ ) {
		bool flg = true;
		int i = 0;
		while ( flg ) {
			flg = false;
			Idx[i]++;
			if ( Idx[i] > 2 ) {
				Idx[i] = 0;
				i++;
				flg = true;
			}
		}
		SA = 0;
		SB = 0;
		for ( int i = 0; i < N; i++ ) {
			if ( Idx[i] == 1 ) 
				SA += A[i];
			else if ( Idx[i] == 2 ) 
				SB += A[i];
		}
		if ( SA != 0 && SA == SB ) return true;
	}	
	return false;
}


int main(int argc, char* argv[])
{
	int	casenum;
	cin >> casenum;
	for ( int i = 1; i <= casenum; i++ ) {
		cin >> N;
		A.clear();
		Idx.clear();
		for ( int j = 0; j < N; j++ ) {
			int a;
			cin >> a;
			A.push_back(a);
			Idx.push_back(0);
		} 
		bool ret = solve();
		if ( ret == false ) {
			cout << "Case #" << i << ": Impossible" << endl;
		} else {
			cout << "Case #" << i << ":" << endl;
			bool first = true;
			for ( int i = 0; i < N; i++ ) {
				if ( Idx[i] == 1 ) {
					if ( first == true ) 
						first = false;
					else
						cout << " ";
					cout << A[i];
				}
			}
			cout << endl;
			first = true;
			for ( int i = 0; i < N; i++ ) {
				if ( Idx[i] == 2 ) {
					if ( first == true ) 
						first = false;
					else
						cout << " ";
					cout << A[i];
				}
			}
			cout << endl;
		}
	}

	return 0;
}
