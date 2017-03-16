#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;
vector<int> A;
vector<int> B;

int solve(int stars,int rem, vector<int> rating)
{
	int cnt = 0;
	
	while ( rem > 0 ) {
		bool flg = false;
looping:
		for ( int i = 0; i < N; i++ ) {
			if ( B[i] <= stars && rating[i] != 2 ) {
				stars += (rating[i] == 1) ? 1 : 2;
				rating[i] = 2;
				rem--;
				cnt++;
				flg = true;
				goto looping;
			}
		}
		if ( rem == 0 ) return cnt;

		int min = INT_MAX;
		for ( int i = 0; i < N; i++ ) {
			if ( A[i] <= stars && rating[i] == 0 ) {
				rating[i] = 1;
				int c = solve( stars + 1, rem, rating);
				rating[i] = 0;
				if ( min > c && c >= 0 ) min = c;
			}
		}
		if ( min != INT_MAX ) {
			return cnt + min + 1;
		}
		if ( flg == false ) {
			return -1;
		}
	}
	return cnt;
}


int main(int argc, char* argv[])
{
	int	casenum;
	cin >> casenum;
	for ( int i = 1; i <= casenum; i++ ) {
		cin >> N;
		A.clear();
		B.clear();
		for ( int j = 0; j < N; j++ ) {
			int a, b;
			cin >> a >> b;
			A.push_back(a);
			B.push_back(b);
		} 
		vector<int> rating(N, 0);
		int cnt = solve(0,N, rating);
		char buf[512] = "Too Bad";
		if ( cnt >= N ) {
			sprintf( buf, "%d", cnt);
		}
		cout << "Case #" << i << ": " << buf << endl;
	}

	return 0;
}
