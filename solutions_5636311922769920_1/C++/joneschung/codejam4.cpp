#include <iostream>

using namespace std;

long long int getNum(int * arr, int length, int k){//0,1,2로 받
	long long int res = 1;
	long long int power = 1;
	for(int i = length-1; i >= 0; i--){
		res += (arr[i]*power);
		power *= k;
	}
	return res;
}

int main(){

	int t,k,c,s;
	cin >> t;



	for(int i = 1; i <= t; i++){
		cin >> k >> c >> s;
		cout << "Case #" << i << ":";

		int neededS = (k+c-1)/c;
		if(neededS > s){
			cout << " IMPOSSIBLE" << endl;
			continue;
		}

		for(int j = 0; j < neededS; j++){
			cout << " ";

			if(j == neededS-1 && (k - j * c != c )){
				int len = k - j * c;
				int arr[len];
				for(int m = 0; m < len; m++){
					arr[m] = j*c + m;
				}
				cout << getNum(arr, len, k);
			}
			else{
				int arr[c];
				for(int m = 0; m < c; m++){
					arr[m] = j*c + m;
				}
				cout << getNum(arr, c, k);
			}

		}
		cout << endl;
	}

	return 0;
}

//clang -stdlib=libc++ -std=c++11 -lc++ codejam4.cpp -o codejam4