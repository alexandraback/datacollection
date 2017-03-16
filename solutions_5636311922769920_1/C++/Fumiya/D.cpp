#include <iostream>
#include <string>

using namespace std;

int main(){
	int N; cin >> N;
	for(int i=0;i<(1<<N);i++){
		string S;
		for(int j=0;j<N;j++){
			if(i&(1<<(N-1-j))) S += 'G';
			else               S += 'L';
		}
		string G(N, 'G');
		string R;
		for(int j=0;j<N;j++){
			if(S[j] == 'G') R += G;
			else            R += S;
		}
		cout << R << endl;
	}
}
