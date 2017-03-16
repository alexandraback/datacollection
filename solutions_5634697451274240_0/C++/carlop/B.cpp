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

int number_of_inversion(const string & S) {
	int c=0;
	for (int i=1; i<S.size(); i++) if (S[i] != S[i-1]) c++;
	return c;
}

int main(void) {
	int num_test;
	cin>>num_test;
	
	for (int test=1; test<=num_test; test++) {
		string S;
		cin>>S;
		
		int lenght = number_of_inversion(S);
		
		if ((lenght%2 == 0) != (S.front()=='+')) lenght++;
		
		cout<<"Case #"<<test<<": "<<lenght<<"\n";
	}
	return 0;
}
