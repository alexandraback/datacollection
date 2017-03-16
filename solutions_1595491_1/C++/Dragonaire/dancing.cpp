#include <iostream>
#include <fstream>

using namespace std;

ifstream reader("in");
ofstream writer("out");

// 2: 0 0 2
// 3: 0 1 2
// 4: 1 1 2 : these cases are not surprising.
// 5: 1 1 3

int maxpts(int total){
	if(total < 2) return total;
	if(total > 27) return 10;
	else return (total - 2) / 3 + 2;
}

int main(){
	
	int cases;
	reader >> cases;

	for(int _m = 0; _m < cases; ++_m){
		int dancers, surprises, minpoints;
		reader >> dancers >> surprises >> minpoints;
		int total, mindancers = 0;
		for(int a = 0; a < dancers; ++a){
			reader >> total;
			if(total > 1 && total < 28 && maxpts(total) == minpoints && total % 3 != 1){
				--surprises; // this case must have been surprising for it to have gotten at least "minpoints" points.
				if(surprises >= 0){
					++mindancers;
				}
			}else if(maxpts(total) >= minpoints){
				++mindancers;
			}
		}
		writer << "Case #" << _m + 1 << ": " << mindancers << endl;
	}

}
