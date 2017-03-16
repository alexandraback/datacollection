#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <queue>
#include <map>
#include <math.h>
using namespace std;

vector<int> a(100000);

int A[50][50];

char out[3000];
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		// Problem starts here
		unsigned long long B,M;
		cin >> B >> M;
		for (int i = 0; i < B; i++) {
			for (int j = 0; j < B; j++) {
				if (i < j) {
					A[i][j] = 1;
				}
				else {
					A[i][j] = 0;
				}
			}
		}
		unsigned long long maxSol = pow(2ull, B -2);
		bool poss = M <= maxSol;
		if (poss)
		{
			unsigned long long toRem = maxSol - M;
			cout << "POSSIBLE" << endl;
			
			if (M == 0) {
				for (int i = 0; i < B; i++) {
					A[i][B-1] = 0;
				}
			}
			else {
				int i = 0;
				while(toRem!=0)
				{
	  				unsigned long long r = toRem%2ull;
				    if(r > 0) {
				    	//int powToRem = pow(2,i);
				    	int idxToRem = i+1;
						//cout << idxToRem << ' ';
				    	
				    	A[idxToRem][B-1] = 0;
				    	// rem 
				    }
				    toRem /= 2;
				    i++;
				}
			}


			for (int i = 0; i < B; i++) {
				for (int j = 0; j < B; j++) {
					cout << A[i][j];
				}
				cout << endl;
			}

		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}		

		// Problem ends here
		//cout << endl;
	}

	return 0;
}