/*
 * QualifyingD.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: Neil
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;



int T;
int K;
int N;


struct chest {
	int key_count;
	int opener;

	int keys[201];
};

int keys[201];

chest C[201];


int vis[201];

int memo1[(1 << 20) + 1];
int memo2[(1 << 20) + 1];

vector<int> sol;



int dp(int bitmask, int avail[]) {

	if(bitmask == ((1 << N) - 1))
		return 1;


	if(memo1[bitmask] != -1)
		return memo1[bitmask];

	int ans = 0;

	int ind = -1;

	for(int i = 0; i < N; i++) {
		if( ( (1 << (i)) & bitmask) == 0 && avail[C[i].opener] > 0) {

			for(int j = 0; j < C[i].key_count; j++) {
				avail[C[i].keys[j]]++;
			}

			avail[C[i].opener]--;

			ans = dp(bitmask | (1 << i),avail);

			if(ans) {
				ind = i;
				break;
			}


			for(int j = 0; j < C[i].key_count; j++) {
					avail[C[i].keys[j]]--;
				}

			avail[C[i].opener]++;

		}
	}


	memo1[bitmask] = ans;

	if(ans) {
		memo2[bitmask] = ind;
	}

	return ans;

}



void get_sol(int bitmask) {

	if(memo2[bitmask] == -1) {
		cout << endl;
		return;
	}

	cout << " " << (memo2[bitmask] + 1);


	get_sol( bitmask| (1 << memo2[bitmask]));

}


int main() {



	freopen("test.in","r",stdin);
	freopen("D.out","w",stdout);
	cin >> T;

	for(int t=1; t <= T; t++) {
		cin >> K >> N;

		memset(keys,0,sizeof(keys));
		memset(vis,0,sizeof(vis));
		memset(C,0,sizeof(C));
		memset(memo1,-1,sizeof(memo1));
		memset(memo2,-1,sizeof(memo2));

		sol.clear();

		for(int i =0 ; i < K; i++) {
			int tmp;
			cin >> tmp;

			keys[tmp - 1]++;
		}

		for(int i =0 ; i < N; i++) {
			cin >> C[i].opener;
			C[i].opener--;



			cin >> C[i].key_count;

			for(int j = 0; j < C[i].key_count; j++) {
				cin >> C[i].keys[j];
				C[i].keys[j]--;
			}
		}




		cout << "Case #" << t << ":";

		int solved = dp(0,keys);


		if(solved)
			get_sol(0);
		else
			cout << " IMPOSSIBLE" << endl;






	}

	return 0;
}



