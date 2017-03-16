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
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<cassert>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int sarr[3] = {1,1,2}, narr[3] = {0,1,1};
const int SIZE = 500;
int arr[SIZE], table[SIZE][SIZE];
int N, S, P;

int get(int i, int s){

	if(i >= N)
		return s == S ? 0 : -1e9;
	if(table[i][s] != -1)
		return table[i][s];

	int best = 0;

	//surprising
	if(s < S){
		int v1 = arr[i] >= 3 ? arr[i]/3+sarr[arr[i]%3] : arr[i];
		int c1 = v1 >= P;
		c1 += get(i+1, s+1);
		best = max(best, c1);
	}

	//not surprising
	int v1 = arr[i] >= 3 ? arr[i]/3+narr[arr[i]%3] : min(arr[i], 1);
	int c1 = v1 >= P;
	c1 += get(i+1, s);
	best = max(best, c1);

	return table[i][s] = best;
}

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small-attempt0.out", "wt", stdout);
	//freopen("B-large.in", "rt", stdin);
	//freopen("B-large.out", "wt", stdout);

	int tt; scanf("%d ", &tt);
	for(int t = 0 ; t < tt ; t++){
		cerr << "Solving testcase " << t+1 << endl;

		cin >> N >> S >> P;
		for(int i = 0 ; i < N ; i++)
			cin >> arr[i];

		memset(table, -1, sizeof table);
		cout << "Case #" << t+1 << ": " << get(0, 0) << endl;
	}

	return 0;
}
