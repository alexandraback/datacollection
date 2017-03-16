#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <bitset>
#include <cstdlib>

using namespace std;

int arr[6][6];
int m[6];
int count = 0;
int goal;
bool cont = true;
int limit;
int nums[6];

bool dfs(int start) {

	m[start] = 1;
	for (int i=0; i < goal ; i++) {
		if (m[i] != 1 && cont == true) {
			arr[start][i] = 1;
			if (i == goal - 1){
				count = count + 1;
				if (count == limit) {
					cont = false;
				}
				return true;
			}
			m[i] = 1;
			dfs(i);

		}
	}
	m[start] = 0;
			
}
int main(int argc, char* argv[]) {

	int t;
	int n;
	int j;
	cin >> t;



	for (int e = 1; e <= t; e++) {

		cout << "Case #" << e << ": "; 
		cin >> goal;
		cin >> limit;
		dfs(0);
		if (count == limit) {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < goal; i++) {
				for (int k =0 ; k < goal; k++) {
					cout << arr[i][k] << " ";
					arr[i][k] = 0;
					m[k] = 0;
				}
				cout << endl;
			}
		}
		else 
			cout << "IMPOSSIBLE" << endl;

   	    cont = true;
   	    count = 0;
   	    
		
		
		
	}


}