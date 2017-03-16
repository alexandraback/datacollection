#include<iostream>
using namespace std;

int res[1000003];
bool byl[13];

void rozloz(int x){
	while(x > 0){
		byl[x % 10] = 1;
		x /= 10;
	}
}
bool wszystkie(){
	for(int i = 0; i < 10; i++){
		if(byl[i] == 0) return 0;
	}
	return 1;
}

int t,n;

int main(){

	for(int i = 1; i <= 1000001; i++){
		
		for(int j = 0; j < 10; j++){
			byl[j] = 0;
		}
		
		for(int j = 1; j <= 100; j++){
			rozloz(i*j);
			if(wszystkie()){
				res[i] = i*j;
				break;
			}
		}
	}
	
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cin >> n;
		
		cout << "Case #" << i << ": ";
		
		if(n == 0)cout << "INSOMNIA" << endl;
		else cout << res[n] << endl;
	}

return 0;
}
