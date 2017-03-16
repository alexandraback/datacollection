#include <bitset>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <deque>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <complex>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
int range_max[(1 << 18)];
int value[(1 << 17)];
int R;
int E;
void init(){
	for(int i=0;i<(1 << 17); i++){
		range_max[i + (1 << 17)] = value[i]; 
	}
	for(int i=(1 << 17) - 1; i > 0; i--){
		range_max[i] = max(range_max[2*i], range_max[2*i + 1]); 
	}
}
int max_index_1(int lo, int hi){
	if(lo == 1){
		return 1;
	}
	int ans = lo;
	if(range_max[ans] < range_max[hi - 1]){
		ans = hi - 1;
	}
	if(hi/2 > (lo + 1)/2){
		int j = max_index_1((lo + 1)/2, hi/2);
		if(range_max[ans] < range_max[2*j]){
			ans = 2*j;
		}
		if(range_max[ans] < range_max[2*j + 1]){
			ans = 2*j + 1;
		}
	}
	return ans;
}
int find_max_index(int lo, int hi){
	return max_index_1(lo + (1 << 17), hi + (1 << 17)) - (1 << 17);
}

unsigned long long solve_the_problem(int start, int end, int energystart, int energyend){
	if(start == end){
		return 0;
	}
	int best = find_max_index(start, end);
	int M = min(E, energystart + (best - start) * R);
	int m = max(0, energyend - (end - best) * R);
	unsigned long long b = solve_the_problem(start, best, energystart, M) + solve_the_problem(best+1, end, min(E, m + R), energyend);
	return b + (M - m) * ((unsigned long long)value[best]);
}
int main(){
	int T;
	cin >> T;
	for(int q=0;q<T;q++){
		int N;
		cin >> E >> R >> N;
		for(int i=0;i<N;i++){
			cin >> value[i];
		}
		init();
		//cout << find_max_index(0, N) << endl;
		cout << "Case #"<< (q+1) << ": " << solve_the_problem(0, N, E, 0) << endl;
	}
}
