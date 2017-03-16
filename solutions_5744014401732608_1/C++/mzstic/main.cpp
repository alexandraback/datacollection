#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    unsigned short int t;

    cin >> t;

    for(int i=1; i <= t; i++) {
        	unsigned  long long B;
        	cin >> B;
        	unsigned  long long M = 0;
        	cin >> M;

        	unsigned long long MAXIMUM_WAYS = 1;

        	for (int j = 0; j < B-2; j++) {
        		MAXIMUM_WAYS *= 2;
        	}
        	cout << "Case #" << i << ": ";

	//cout << endl << "MAX: " <<  MAXIMUM_WAYS << endl;

	//cout << "got here1" << endl;

        	if (M > MAXIMUM_WAYS) {
        		cout << "IMPOSSIBLE" << endl;
        		continue;
        	}
        	cout << "POSSIBLE" << endl;

	//cout << "got here2" << endl;
        	bool** matrix = new bool*[B];
        	for (int x = 0; x < B; x++) {
        		matrix[x] = new bool[B];
        	}
    //    	cout << "got here3" << endl;

        	unsigned long long curMax = 1;

        	for (int y = B-2; y >=0; y-- ) {
        //		cout << "curMax: " <<  curMax << endl;
        		if (curMax <= M) {
        			for (int x = B-1; x > y; x--) {
        //				cout << "X: " << x << "; Y: " << y << endl; 
        				matrix[x][y] = true;
        			}
        			curMax *= 2;
        		} else {
        			break;
        		}

        	}

        	unsigned long long int remaining = M;
        	unsigned long long int possible = MAXIMUM_WAYS / 2;
        	for (int x = 1;  x < B; x++) {
       // 		cout << "possible: " << possible <<endl;
     //   		cout << "remaining: " << remaining << endl;
        		if (remaining >= possible && remaining > 0) {
        			matrix[x][0] = true;
        			remaining -= possible;
        		}
        		possible /= 2;
        	}

        	for (int y = 0; y < B; y++) {
        		for (int x = 0; x < B; x++) {
        			if (matrix[x][y]) {
        				cout << '1';
        			} else {
        				cout << '0';
        			}
        		}
        		cout << endl;
        	}
        	//break;
    }
    return 0;
}
