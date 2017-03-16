#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int perform(vector<int> motes, int j, int A){
	if (j >= motes.size()){
		return 0;
	}
	if (A > motes[j]){
		A += motes[j];
		j++;
		return perform(motes, j, A);
	}else{
		int insert = perform(motes, j, 2*A-1) + 1;
		int del = perform(motes, j+1, A) + 1;
		return min(insert, del);
	}

}

int main(){
	int T;
	cin >> T;
	
	int i, j, k;

	for (i=1;i<=T;i++){
		int A, N;
		cin >> A >> N;
		vector<int> motes(N);
		for (j=0;j<N;j++){
			cin >> motes[j];
		}
		sort(motes.begin(), motes.end());


		int count = 0;
/*
		for (j=0;j<N;j++){
			if (A > motes[j]){
				A += motes[j];
			}else if (A> 1){
				if (2*A -1 > motes[j]){
					count ++;
					A = 2*A-1 + motes[j];
				}else{
					count += perform(motes, j, A);
				}
			}else{
				count = N-j;
				break;
			}
		}
*/

			if (A > 1){
				count = perform(motes,0,A);
			}else{
				count = N;
			}


		cout <<"Case #"<<i<<": " << count << endl;
	}



	return 0;
}
