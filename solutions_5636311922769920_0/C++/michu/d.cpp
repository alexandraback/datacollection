#include<iostream>
using namespace std;

int t,k,c,s;

int main(){
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cin >> k >> c >> s;
		
		cout << "Case #"<<i<<": ";
		for(int j = 1; j <= s; j++){
			cout << j << " ";	
		}
		cout <<endl;
	}
	
	return 0;
}
