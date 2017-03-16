//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<cstring>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big unsigned long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int E, R, N, arr[100];
int table[100][100];

int get(int i, int rem){
	if(i >= N)return 0;
	if(table[i][rem] != -1)return table[i][rem];

	int best = 0;
	for(int j = 0 ; j <= rem ; j++){
		int current = j*arr[i]+get(i+1, min(E, rem-j+R));
		best = max(current, best);
	}

	return table[i][rem] = best;
}

int main(){

	//freopen("1.in", "rt", stdin);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);

	int TT; cin >> TT;
	for(int t = 1 ; t <= TT ; t++){
		cin >> E >> R >> N;
		for(int i = 0 ; i < N ; i++)
			cin >> arr[i];

		memset(table, -1, sizeof table);
		cout << "Case #" << t << ": " << get(0, E) << endl;
	}

	return 0;
}
