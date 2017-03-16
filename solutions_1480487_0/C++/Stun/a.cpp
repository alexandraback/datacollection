#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;
int input[201];
int N;

int next(int cur){
	int min = 99999;
	for (int i = 0 ; i < N ; i++){
		if (input[i] > cur && min > input[i])
			min = input[i];
	}
	return min;
}

int n_cur(int cur){
	int n = 0;
	for (int i = 0 ; i < N ; i++){
		if (input[i] <= cur) n++;
	}
	return n;
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		cin >> N;
		
		int sum = 0;

		for (int i = 0 ; i < N ; i++){
			cin >> input[i];
			sum += input[i];
		}
		
		cout << "Case #" << casen + 1 << ": ";
		for (int i = 0 ; i < N ; i++){
			if (i > 0) cout << " ";
			// printf("%.6lf", max(0.0, (2 * sum - N * input[i]) * 100 / (double)(N * sum)));
			double frac = 0;
			for (int j = 0 ; j < N ; j++){
				if (i == j) continue;
				frac += max(0.0, (input[i] - input[j]) / double(sum));
			}
			double remain = 1 - frac;
			int cur = input[i];
			frac = 0;
			int ncur = n_cur(cur);			
			while (remain > 0){
				ncur = n_cur(cur);
				if (ncur >= N) break;
				int ext = next(cur);
				// cout << "> " << cur << " " << ext << endl;
				if (((ext - cur) / double(sum)) * ncur > remain) {
					break;
				}
				remain -= (ext - cur) * ncur / double(sum);
				frac += (ext - cur) / double(sum);
				cur = ext;
			}
			if (remain > 0)
				frac += remain / ncur;
			printf("%.6lf", frac * 100);
		}
		cout << endl;
		
		
	}
	

	return 0;
}
