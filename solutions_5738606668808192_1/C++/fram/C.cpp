#include <iostream>
#include <string>
using namespace std;

int N = 32;
int J = 500;

int main(){
	cout << "Case #1:" << endl;
	for(int x=0; x<J; x++){
		cout << "11";
		int cx = x;
		for(int i=1; i<N/2-1; i++){
			if(cx % 2) cout << "11"; else cout << "00";
			cx /= 2;
		}
		cout << "11 ";
		
		for(int i=2; i<=10; i++) cout << i+1 << ' ';
		cout << endl;
	}
	return 0;
}
