//
// c.cpp -- C
//
// Siwakorn Sriakaokul - ping128
// Written on Saturday, 13 April 2013.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <time.h>

using namespace std;

void reset(){
	// reset values for the each testcase
}

int values[15];
int ans[15];

int cx[] = {2, 3, 5, 7};
int maxxcx[4];
void solve(){
	int R, N, M, K;
	reset();
	srand (time(NULL));
	cin >> R >> N >> M >> K;
	for(int r = 0; r < R; r++ ){
		for(int i = 0; i < 4; i++ )
			maxxcx[i] = 0;
		for(int i = 0; i < K; i++ ){
			cin >> values[i];
			for(int j = 0; j < 4; j++ ){
				int ttt = values[i];
				int cnt = 0;
				while((ttt % cx[j]) == 0){
					ttt /= cx[j];
					cnt++;
				}
				maxxcx[j] = max(maxxcx[j], cnt);
			}
		}
		bool found = 0;
		for(int round = 0; round < 5000000; round++ ){
			found = true;
			int maxxMul = 1;
			int cnt2[4] = {0};
			for(int i = 0; i < N; i++ ){
				ans[i] = (rand() % (M - 1)) + 2;
				maxxMul *= ans[i];
				for(int j = 0; j < 4; j++ ){
					int ttt = ans[i];
					int cnt = 0;
					while((ttt % cx[j]) == 0){
						ttt /= cx[j];
						cnt++;
					}
					cnt2[j] += cnt;
				}
			}

			for(int i = 0; i < 4; i++ ){
				if(cnt2[i] < maxxcx[i]){
					found = false;
					break;
				}
			}
			for(int i = 0; i < K; i++ ){
				if(maxxMul < values[i]){
					found = false;
					break;
				}
			}
			if(!found) continue;

			for(int i = 0; i < K; i++ ){
				if(values[i] == 1) continue;
				int found2 = false;
				for(int j = 0; j < 1<<N; j++ ){
					int temp = 1;
					for(int k = 0; k < N; k++ ){
						if(j & (1<<k)){
							temp *= ans[k];
						}
					}
					if(temp == values[i]){
						found2 = true;
						break;
					}
				}
				if(found2 == false){
					found = false;
					break;
				}
			}
			if(found) break;
		}
		for(int i = 0; i < N; i++ ){
			cout << ans[i];
		}
		cout << endl;
	}
}


int main()
{
	int test;
	cin >> test;
	for(int tt = 0; tt < test; tt++ ){
		printf("Case #%d:\n", tt + 1);
		solve();
	}
	return 0;
}
