#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include <string.h>

using namespace std;

void calc(int N, int S, int minS, int maxS, vector<int> &s, vector<double> &m)
{
	double bsum = 0.0;
	for ( int ans = maxS; ans <= S+maxS; ans++ ) {
		double msum = 0;
		for ( int i = 0; i < N; i++ ) {
			if ( ans - s[i] < 0 ) goto next1_;
			m[i] = (double)(ans - s[i]) * 100 / (double)S;
			msum += m[i];
			if ( msum > 100.1 ) break;
		}
		if ( abs(msum - 100.0) < 0.000001 ) return;
		if ( msum > 100.0 ) {
			if ( ans == maxS ) break;
			int rans = ans - 1;
			for ( int i = 0; i < N; i++ ) {
				m[i] = (double)(ans - s[i]) * 100 / (double)S;
				if ( s[i] == maxS ) m[i] += 100.0 - bsum;
			}
			return;
		}
		if ( msum < 100.0 ) bsum = msum;
next1_: 
		;
	}
	for ( int siki = maxS - 1; siki > minS; siki-- ) {
		for ( int ans = minS; ans <= S+maxS; ans++ ) {
			double msum = 0;
			for ( int i = 0; i < N; i++ ) {
				if ( s[i] > siki ) {
					m[i] = 0;
				 }else {
					if ( ans - s[i] < 0 ) goto next2_;
					m[i] = (double)(ans - s[i]) * 100 / (double)S;
					msum += m[i];
					if ( m[i] > 100.0 ) break;
					if ( msum > 100.1 ) break;
				}
			}
			if ( abs(msum - 100.0) < 0.000001 ) return;
#if 0
			if ( msum < 100.0 ) {
				for ( int i = 0; i < N; i++ ) {
					if ( m[i] == 0 ) {
						m[i] = 100.0 - msum;
						return ;
					}
				}
			}
#endif
next2_: 
		;
		}
	}

	cerr << "error2";

}

int main(int argc, char* argv[])
{
	int	casenum;

	cin >> casenum;
	string g;
	for ( int i = 1; i <= casenum; i++ ) {
		int N;
		cin >> N;
		vector<int>	s(N,0);
		int S = 0;
		int minS = INT_MAX;
		int maxS = 0;
		for ( int j = 0; j < N; j++ ) {
			cin >> s[j];
			S += s[j];
			if ( minS > s[j]) minS = s[j];
			if ( maxS < s[j]) maxS = s[j];
		}
		vector<double> m(N,0);
		cout << "Case #" << i << ":";
		if ( minS == maxS && minS * N == S) {
			for ( int j = 0; j < N; j++ ) {
				if ( 100 % N == 0 ) {
					m[j] = 100.0 / N;
					cout << setprecision(1) << setiosflags(ios::fixed); 
					cout << " " << m[j];
				} else {
					m[j] = 100.0 / N;
					cout << setprecision(6) << setiosflags(ios::fixed); 
					cout << " " << m[j];
				}
			}
			cout << endl;
		} else {
			calc( N, S, minS, maxS, s, m);
			cout << setprecision(6) << setiosflags(ios::fixed); 
			//cerr << "Case #" << i << ":";
			for ( int j = 0; j < N; j++ ) {
				cout << " " << m[j];
				//cerr << " " << s[j] + S * m[j]/100.0;
			}
			cout << endl;
			//cerr << endl;
		}
	}

	return 0;
}

