#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

#define TEST 0
#define DEBUG 0

bool myfun (int i,int j) { return (i<j); }

int main() {
	int T;
	
	string filename = "B-large";
	ifstream input(filename + ".in");
	
	ofstream output(filename + ".out");


	input >> T;
	for(int T_i = 1; T_i <= T; T_i++){
       	long N;
        input >> N;
        int arr[2501] = {0};
		for(int i = 0; i < N; i++){
			for(int j = 0; j < 2 * N - 1; j++){
                int p;
				input >> p;
				arr[p]++;
			}
		}
		vector<int> lost;
		for(int i = 1; i <= 2500; i++){
			if(arr[i] % 2 == 1){
				lost.push_back(i);
			}
		}

		sort(lost.begin(), lost.end(), myfun);


#if TEST		
		output << "Case #" << T_i << ": " << endl;
#else
		output << "Case #" << T_i << ": ";
			for(int i = 0; i < N; i++){
				output << lost[i] << " ";
		}
		output << endl;
#endif				
	}    
	return 0;
}
