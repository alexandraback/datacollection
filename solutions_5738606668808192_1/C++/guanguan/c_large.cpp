#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n = 32;
int num_coin = 500;


bool coins[55];
vector<int> divisors;

bool is_div(int num, int base){ //number to divide by, base
	int modulo = 0;
	int mod_step = 1;
	for (int i = n - 1; i >= 0; i--){
		if (coins[i]){
			modulo += mod_step;
			modulo %= num;
		}
		mod_step *= base;
		mod_step %= num;
	}
	if (modulo == 0){
		return true;
	}
	else{
		return false;
	}
}

bool prime_fac(int base){ //return false on failure
	if (is_div(2,base)){
		divisors.push_back(2);
		return true;
	}
	for (long long i = 3; i*i <= 900; i += 2){
		if (is_div(i,base)){
			divisors.push_back(i);
			return true;
		}
	}
	return false;
}

bool is_valid(){
	for (int i = 2; i <= 10; i++){
		if (prime_fac(i) == false){
			return false;
		}
	}
	return true;
}

void debug_coins(){
	cout << "Coins: ";
	for (int i = 0; i < n; i++){
		cout << coins[i] << " ";
	}
	cout << endl;
}

int main(){
	int cnt = 0;
	coins[0] = true;
	coins[n - 1] = true;
	ofstream fout("c_out.txt");
	fout << "Case #1:" << endl;
	for (int i = 0; i < (1 << (n-2)); i++){
		//Convert to coin
		//cout << "i: " << i << endl;
		for (int j = 0; j < n-2; j++){
			if ( (i & (1 << j)) > 0){
				coins[n - 2 - j] = true;
			}
			else{
				coins[n - 2 - j] = false;
			}
		}
		//debug_coins();
		//Test if coin is valid
		if (is_valid()){
			//Print coin
			for (int j = 0; j < n; j++){
				fout << coins[j];
			}
			fout << " ";
			//Print divisors
			for (int j = 0; j < divisors.size(); j++){
				if (j == divisors.size() - 1){
					fout << divisors[j] << endl;
				}
				else{
					fout << divisors[j] << " ";
				}
			}
			cnt += 1;
			if (cnt == num_coin){
				return 0; //Done
			}
		}
		divisors.clear();
	}
}
