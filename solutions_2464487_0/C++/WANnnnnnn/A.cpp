//#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream cin;
	ofstream cout;

	cin.open("A-small-attempt0.in");
	cout.open("ASoutput.txt");

	int T;
	cin >> T;
	for(int n =1 ; n<=T ;n++){
		int r ,t;
		cin >> r >> t;
		int ans = 0;
		int i;
		for(i=0 ; ans+2*r+4*i+1<=t ; i++){
			ans += 2*r+4*i+1;
		}
		cout << "Case #" << n << ": " << i << endl;
	}

	cin.close();
	cout.close();
}