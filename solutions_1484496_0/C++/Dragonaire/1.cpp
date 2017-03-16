#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

using namespace std;

ifstream reader("in");
ofstream writer("out");

int main(){
	
	if(!reader) return 0;

	int cases; reader >> cases;

	for(int m = 0; m < cases; ++m){
		
		int numbs; reader >> numbs;

		int elements[20];

		for(int a = 0; a < 20; ++a){
			reader >> elements[a];
		}

		map<int, int> sums;

		cout << "Case #" << m + 1 << ":\n";

		for(int a = 0; a < 1048576; ++a){
			int sum = 0;
			for(int b = 0; b < 20; ++b){
				if((a >> b) % 2 == 1){
					sum += elements[b];
				}
			}
			if(sums.find(sum) != sums.end()){
				// we've got a hit!
				int set1 = a;
				int set2 = sums[sum];
				for(int b = 0; b < 20; ++b){
					if((set1 >> b) % 2 == 1){
						cout << elements[b] << " ";
					}
				}cout << endl;
				for(int b = 0; b < 20; ++b){
					if((set2 >> b) % 2 == 1){
						cout << elements[b] << " ";
					}
				}cout << endl;
				goto nextcase;
			}else{
				sums[sum] = a;
			}

		}

		cout << "Impossible" << endl;
	

nextcase:

;

	}

	return 0;

}
