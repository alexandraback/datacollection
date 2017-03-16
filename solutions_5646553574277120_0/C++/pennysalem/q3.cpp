#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){

	int T, C, D, V;
	int num;
	int count;

	vector<bool> attainable;

	cin >> T;
	for(int i=0; i<T; i++){
		attainable.clear();
		attainable.resize(31, false);
		attainable[0] = true;
		count = 0;
		cin >> C >> D >> V;

		//go through existing D denominations and generate attainable #'s
		for(int j=0; j<D; j++){
			cin >> num;
			for(int k=30; k>=0; k--){
				if(attainable[k] && (k+num) <= 30){
					attainable[k+num] = true;
				}
			}
		}

		//go through V, adding denominations as needed
		for(int j=1; j<=V; j++){
			if(attainable[j] == false){
				//add j
				for(int k=30; k>=0; k--){
					if(attainable[k] && (k+j) <= 30){
						attainable[k+j] = true;
					}
				}
				count++;
			}
		}

		cout << "Case #" << (i+1) << ": " << count << "\n";
	} //for T
	
	return 0;
}