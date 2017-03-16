#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <assert.h>
#include <set>

using namespace std;

long long last_number(long long start) {
	if (start == 0) return -1;
	
	set <int> cypher;
	
	long long curr = 0;
	
	while (cypher.size() < 10) {
		curr += start;
		long long temp = curr;

		while (temp > 0) {
			cypher.insert(temp%10);
			temp /= 10;
		}
		
		if (curr / start > 1000) assert(false);
	}
	return curr;
}

int main(void) {
	int num_test;
	cin>>num_test;
	
	for (int test=1; test<=num_test; test++) {
		long long N;
		cin>>N;
		
		cout<<"Case #"<<test<<": ";
		
		if (N == 0) cout << "INSOMNIA";
		else cout << last_number(N);

		cout << "\n";
	}
	return 0;
}
