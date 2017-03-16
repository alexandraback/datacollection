#include <iostream>
#include <cmath>

using namespace std;

long long int arr[501][11];

int main(){

	int a,s,d;
	cin >> a >>s >>d;

	cout << "Case #1:"<<endl;

	for(int i = 0; i < 500; i++){
		int temp = i;
		int arrdig[14];
		for(int m = 0; m < 14; m++){
			arrdig[m] = temp%2;
			temp = temp/2;
		}

		for(int j = 1; j <= 14; j++){
			if(arrdig[j-1] == 1){
				for(int k = 2; k <= 10; k++){
					arr[i][k] += (int)pow(k,j);
				}
			}
		}

		cout << "1";
		for(int j = 13; j >=0; j--){
			cout << arrdig[j];
		}
		cout << "1";
		cout << "1";
		for(int j = 13; j >=0; j--){
			cout << arrdig[j];
		}
		cout << "1";

		for(int k = 2; k <= 10; k++){
			//arr[i][k] += (int)pow(k,15);
			long long int tempnum = 1;
			for(int p = 0; p < 15; p++){
				tempnum *= k;
			}
			arr[i][k] += tempnum;
			arr[i][k] += 1;
			cout << " " << arr[i][k];
		}
		cout << endl;
	}

	return 0;
}