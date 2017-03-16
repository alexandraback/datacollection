#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

long reverse(long n){
	long reverse = 0;
	while (n != 0){
		reverse = reverse * 10;
		reverse = reverse + n%10;
		n = n/10;
	}
	
	return reverse;
}

long solve(long n){
	long count = 0, x = n, fi, rev, pos = 0;
	while (x >= 10)
		x /= 10;
	for(long i = n; i > 0; i--){
		if(floor(log10(i-1)) < floor(log10(i)))
			pos = 0;
		
		count++;
		if((i % (int)pow(10, (int)(floor((log10(i) + 1) / 2)))) == 1 && i > 10 && reverse(i) < i){
			count++;
			pos++;
			i = reverse(i);
		}
	}	
	
	return count;
}

int main() {
	int t;
	long n;
	
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n;
		cout << "Case #" << (i + 1) << ": " << solve(n) << endl;
	}
	
	return EXIT_SUCCESS;
}
