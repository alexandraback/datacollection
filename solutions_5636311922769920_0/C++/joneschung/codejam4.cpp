#include <iostream>

using namespace std;

int main(){

	int t,k,c,s;
	cin >> t;

	for(int i = 1; i <= t; i++){
		cin >> k >> c >> s;
		cout << "Case #" << i << ":";
		for(int j = 1; j <= k; j++){
			cout << " " << j;
		}
		cout << endl;
	}

	return 0;
}

//clang -stdlib=libc++ -std=c++11 -lc++ codejam4.cpp -o codejam4