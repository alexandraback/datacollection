#include <iostream>

using namespace std;

int arr[12];

int main(){

	int t, n;
	cin >> t;

	for (int i = 1; i <= t; i++){
		cin >> n;

		if (n == 0) {
			cout << "Case #" << i << ": INSOMNIA" << endl;
			continue;
		}

		int temp;

		for(int j = 1; j <= 2000; j++){
			temp = n * j;

			while(temp != 0){
				arr[temp%10] = 1;
				temp = temp/10;
			}

			int isdone = 1;
			for(int k = 0; k < 10; k++){
				if(arr[k] == 0){
					isdone = 0;
					break;
				}
			}

			if(isdone == 1){
				cout << "Case #" << i << ": " << (n * j) << endl;
				break;
			}
		}

		for(int j = 0; j < 10; j++){
			arr[j] = 0;
		}
	}
	return 0;
}