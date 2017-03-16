#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
	int num_test;
	cin>>num_test;
	
	for (int test=1; test<=num_test; test++) {
		int N, J;
		cin>>N>>J;
		cout<<"Case #"<<test<<":\n";
		
		for (int j=0; j<J; j++) {
			string S(N, '0');
			S[0] = '1';
			S.back() = '1';
			
			int curr = 1;
			int temp = j;
			while (temp>0) {
				if (temp%2) S[curr] = S[curr+1] = '1';
				curr += 2;
				temp /= 2;
			}
			
			cout << S;
			for (int i=3; i<=11; i++) cout << " " << i;
			cout << "\n";
		}
	}
	return 0;
}
