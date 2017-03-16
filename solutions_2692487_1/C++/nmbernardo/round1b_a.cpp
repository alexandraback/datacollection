/*
 * round1b_a.cpp
 *
 *  Created on: May 4, 2013
 *      Author: Neil
 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <map>

using namespace std;


#define LL long long
#define INF (1 << 28)

#define SIZE 100001
#define PII pair<int,int>
#define ENCODE(x) (x^11234124)
#define DECODE(x) (x^11234124)
int test;


int A;
int N;

int arr[SIZE];


map<int,int> memo[101];

int solve(int n, int size) {



	if(n == N) {
		return ENCODE(0);
	}


	if(memo[n][size] != 0) {
		return memo[n][SIZE];
	}

	int ans = 0;


	if(size <= 1) {
		ans = (DECODE(solve(n + 1,size))) + 1;
	} else if(size > arr[n]) {
		ans = DECODE(solve(n + 1,size + arr[n]));
	} else {
		ans = min(DECODE(solve(n + 1,size)),DECODE(solve(n,size + (size - 1)))) + 1;
	}


	memo[n][size] = ENCODE(ans);

	return ENCODE(ans);

}

int main() {



	freopen("test.in","r",stdin);

	freopen("A.out","w",stdout);

	cin >> test;





	int ans = 0;

	for(int t  = 1; t <= test; t++) {


		cin >> A >> N;

		for(int i = 0; i < N; i++) {
			cin >> arr[i];
			memo[i].clear();
		}


		sort(arr,arr + N);




		int ans = solve(0,A);


		cout << "Case #" << t << ": " << ENCODE(ans) << endl;
	}


	return 0;
}




