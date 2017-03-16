#include <iostream>
#include <cmath>

using namespace std;

int arr[51][11];

int main(){

	int a,s,d;
	cin >> a >>s >>d;

	cout << "Case #1:"<<endl;

	for(int i = 0; i < 50; i++){
		int temp = i;
		int arrdig[6];
		for(int m = 0; m < 6; m++){
			arrdig[m] = temp%2;
			temp = temp/2;
		}

		for(int j = 1; j <= 6; j++){
			if(arrdig[j-1] == 1){
				for(int k = 2; k <= 10; k++){
					arr[i][k] += (int)pow(k,j);
				}
			}
		}

		cout << "1";
		for(int j = 5; j >=0; j--){
			cout << arrdig[j];
		}
		cout << "1";
		cout << "1";
		for(int j = 5; j >=0; j--){
			cout << arrdig[j];
		}
		cout << "1";

		for(int k = 2; k <= 10; k++){
			arr[i][k] += (int)pow(k,7);
			arr[i][k] += 1;
			cout << " " << arr[i][k];
		}
		cout << endl;
	}

	return 0;
}