#include <iostream>

using namespace std;

int main(){

	int t;
	cin >> t;

	for(int i = 1; i <= t; i++){
		string str;
		cin >> str;

		int length = str.length();

		int arr[length + 1];
		for(int j = 0; j < length; j++)
			arr[j] = (str[j] == '-') ? 0 : 1;

		int saved = arr[0];
		int numOfFlip = 0;
		for(int j = 1; j < length; j++){
			if(saved == arr[j])
				continue;
			else{
				numOfFlip++;
				saved = 1 - saved;
			}
		}
		if(saved == 0)
			numOfFlip++;

		cout << "Case #" << i << ": " << numOfFlip << endl;
	}

	return 0;
}