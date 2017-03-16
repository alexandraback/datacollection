#include <string>
#include <iostream>

using namespace std;
int T, N;

int main(){
	cin >> T;
	for(int i= 0; i < T; i++){
		cin >> N;
		int count[2510];
		for(int j = 0; j < 2510; j++)
			count[j] = 0;
		int k;
		for(int j= 0; j<2*N*N-N; j++){
			cin >> k;
			count[k]++;
		}
		cout << "Case #" << i+1 << ": " ;
		for(int j = 0; j < 2510; j++){
			if(count[j] % 2 != 0)
				cout << j << " ";
		}
		cout << endl;

	}
}