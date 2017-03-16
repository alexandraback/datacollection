#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

void output(int v){
	if (v == 0){
		printf("GABRIEL\n");
	} else {
		printf("RICHARD\n");
	}

}

void solve(int t){
	int x, r, c;
	printf("CASE #%d: ", t);
	cin >> x >> r >> c;
	if (r > c){
		swap(r, c);
	}
	if ((r * c) % x){
		output(1);
		return;
	}
	if (x >= 7){
		output(1);
	}
	if (x == 1){
		output(0);
	}
	if (x == 2){
		if (r == 1 && c == 1){
			output(1);
		} else {
			output(0);
		}
	}
	if (x == 3){
		if (r == 1){
			output(1);
		} else {
			output(0);
		}
	}
	if (x == 4){
		if (r <= 2){
			output(1);
		} else {
			output(0);
		}
	}
	if (x == 5){
		if (r <= 2 || r == 3 && c == 5){
			output(1);
		} else {
			output(0);
		}
	}
	if (x == 6){
		if (r <= 3){
			output(1);
		} else {
			output(0);
		}
	}
}	

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	//freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);	
	}
}
