#include <cassert>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
#define SAMPLE_NAME "B"
	if( freopen(SAMPLE_NAME "-large.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-large.out", "wt", stdout);
	} else 	if( freopen(SAMPLE_NAME "-small-attempt1.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		const int maxsz = 100;
		const int maxht = 100;
		int lawn[maxsz][maxsz] = {0};

		//cerr << '#' << case_num << endl;
		cout << "Case #" << case_num ;
		int N, M;
		cin >> N >> M;
		for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j) {
			cin >> lawn[i][j];
		}

		if(N == 1 || M == 1) {
			cout << ": YES" << endl;
		} else {
			for(int ht = 1; ht < maxht; ++ht) {
				for(int i = 0; i < N; ++i) if(lawn[i][0] == ht) {
					bool cut = true; // was cut
					for(int j = 1; j < M; ++j) cut &= (lawn[i][j] == ht);
					if(cut) for(int j = 0; j < M; ++j) lawn[i][j] = 0;
				}
				for(int j = 0; j < M; ++j) if( (lawn[0][j] == ht) || (lawn[0][j] == 0) ) {
					bool cut = true; // was cut
					for(int i = 1; i < N; ++i) cut &= ( (lawn[i][j] == 0) || (lawn[i][j] == ht) );
					if(cut) for(int i = 0; i < N; ++i) lawn[i][j] = 0;
				}
				for(int i = 0; i < N; ++i)
					for(int j = 0; j < M; ++j)
						if(lawn[i][j] == 0) lawn[i][j] = ht + 1;
			}
			bool possible = true;
			for(int i = 0; i < N; ++i)
					for(int j = 0; j < M; ++j)
						if(lawn[i][j] != maxht) { possible = false; break; }
			if(!possible) cout << ": NO" << endl;
			else cout << ": YES" << endl;
		}
	}
 	return 0;
}
