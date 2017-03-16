#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

string solve(int x, int r, int c){
	if(x > 6)
		return "RICHARD";
	if(x > 2 * min(r, c))
		return "RICHARD";
	if(x > 3 && x >= 2 * min(r, c))
		return "RICHARD";
	if(x > max(r,c))
		return "RICHARD";
	if((r * c) % x != 0)
		return "RICHARD";
		
	return "GABRIEL";
}

int main() {
	int t, x, r, c;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> x >> r >> c;

		cout << "Case #" << (i + 1) << ": " << solve(x, r, c) << "\n";
	}
	
	return EXIT_SUCCESS;
}
