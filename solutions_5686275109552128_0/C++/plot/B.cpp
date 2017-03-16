#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int max(int d, int* p){
	int max = 0;
	for(int i = 1; i < d; i++){
		if(p[max] < p[i])
			max = i;
	}
	return max;
}

int solve(int d, int* p){
	int min = p[max(d, p)];
	long special;

	for(int i = 1; i < min; i++){
		special = 0;
		for(int j = 0; j < d; j++){
			if(p[j] <= i)
				continue;
			special += (long)ceil(p[j] / (double)i) - 1;
		}
		if(special + i < min)
			min = special + i;
	}

	return min;
}

int main() {
	int t, d;
	int* p;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> d;
		
		p = (int*)malloc(d * sizeof(int));
		
		for(int j = 0; j < d; j++)
			cin >> p[j];

		cout << "Case #" << (i + 1) << ": " << solve(d, p) << "\n";
		
		free(p);
	}
	
	return EXIT_SUCCESS;
}
