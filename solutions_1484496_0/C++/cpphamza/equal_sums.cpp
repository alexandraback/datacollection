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

const int SIZE = 2000000;
int N, arr[20];
int table[20][4000001][2];

int get(int i, int d, int t){

	if(i >= N){
		return t && !d;
	}
	if(table[i][d+SIZE][t] != -1)
		return table[i][d+SIZE][t];

	//leave it
	bool res = get(i+1, d, t);
	if(res)
		return table[i][d+SIZE][t] = 1;

	res = get(i+1, d+arr[i], 1);
	if(res)
		return table[i][d+SIZE][t] = 2;

	res = get(i+1, d-arr[i], 1);
	if(res)
		return table[i][d+SIZE][t] = 3;

	return table[i][d+SIZE][t] = 0;
}

void print(vector<int> a, vector<int> b){
	for(int i = 0 ; i < s(a) ; i++){
		if(i)cout << " ";
		cout << a[i];
	}
	cout << endl;
	for(int i = 0 ; i < s(b) ; i++){
		if(i)cout << " ";
		cout << b[i];
	}
	cout << endl;
}

int main(){

	//freopen("1.in", "rt", stdin);
	//freopen("1.out", "wt", stdout);
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	//freopen("A-large.in", "rt", stdin);
	//freopen("A-large.out", "wt", stdout);

	int tt; scanf("%d ", &tt);
	for(int t = 0 ; t < tt ; t++){
		cerr << "Solving testcase " << t+1 << endl;
		cin >> N;
		for(int i = 0 ; i < N ; i++)
			cin >> arr[i];

		memset(table, -1, sizeof table);

		bool r = get(0, 0, 0);
		printf("Case #%d:\n", t+1);
		if(!r)
			printf("Impossible\n");
		else{
			int i = 0 , d = 0 , t = 0;
			vector<int> a, b;
			while(i < N){
				if(table[i][d+SIZE][t] == 1)
					i++;
				else if(table[i][d+SIZE][t] == 2){
					a.push_back(arr[i]);
					d += arr[i];
					t = 1;
					i++;
				} else {
					b.push_back(arr[i]);
					d -= arr[i];
					t = 1;
					i++;
				}
			}
			print(a, b);
		}
	}

	return 0;
}
