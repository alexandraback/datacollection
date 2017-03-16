#include<iostream>
#include<string>
using namespace std;

int t,n,J;
long long res;

int repr[20];

bool zla;
int dzielnik[20];

void to_repr(int x){
	int ind = 0;
	
	while(x > 0){
		repr[ind] = x % 2;
		x/=2;
		ind++;
	}
}

void to_base(long long x){
	long long pot = 1;
	res = 0;
	for(int i = 0; i < 16; i++){
		res += repr[i] * pot;
		pot *= x;
	}
}

bool pierwsza(long long x, int akt_baza){
	
	for(long long i = 2; i*i <= x; i++){
		if(x % i == 0){
			dzielnik[akt_baza] = i;
			return 0;
		}
	}
	return 1;
}
int ilosc;
int main(){
	cin >> t >> n >> J;
	cout << "Case #1: \n";
	
	for(int i = 32769; i < 65536; i+=2){
		to_repr(i);
		zla = 0;
		
		for(int j = 2; j <= 10; j++){
			to_base(j);
		
			if(pierwsza(res, j)){
				zla = 1;
			}
		}
		if(zla == 0){
			for(int j = 15; j >= 0; j--){
				cout << repr[j];
			}
			cout << " ";
			for(int j = 2; j <= 10; j++){
				cout << dzielnik[j] << " ";
			}
			cout << endl;
			
			ilosc++;
			
			if(ilosc == J)return 0;
		}
	}
	
	
return 0;
}
