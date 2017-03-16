#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int getDivisior(int base, std::vector<int>& coin){

	unsigned long long int actual = 0;
	int power = 0;
	for(int i=coin.size()-1; i>=0; i--){
		actual += coin[i]*pow(base,power);
		power++;
	}

	for(int d=2; d<10; d++){
		if(actual%d==0){
			return d;
		}
	}
	return 0;
}


int main(int argc, char* argv[]){

	//---------------------------------------
	int N = 16;

	// SUBTRACT BEGINNING AND END ONES
	std::vector<int> allowedNOnes(2,0);
	allowedNOnes[0] = 4;
	allowedNOnes[1] = 10;

	int J = 50;
	//---------------------------------------

	cout << "Case #1:" << endl;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> chooseNOnes(0,allowedNOnes.size()-1);

	std::vector<int> coinIndices;
	for(int i=1; i<=N-2; i++){
		coinIndices.push_back(i);
	}

	std::vector< std::vector<int> > longTermStorage;

	int nOutputs = 0;
	while(nOutputs < J){

		int nOnes = allowedNOnes[chooseNOnes(generator)];

		std::vector<int> coin(N,0);
		coin[0] = 1;
		coin[N-1] = 1;

		std::random_shuffle (coinIndices.begin(), coinIndices.end());
		for(int i=0; i<nOnes; i++){
			coin[coinIndices[i]] = 1;
		}

		std::vector<int> divisors(9,0);
		divisors[1] = 2;
		divisors[3] = 2;
		divisors[5] = 2;
		divisors[7] = 2;
		divisors[8] = 3;


		bool isDuplicate = false;
		for(int i=0; i<longTermStorage.size(); i++){
			if(coin == longTermStorage[i]){
				isDuplicate = true;
				break;
			}
		}

		bool pass = true;
		if(!isDuplicate){

			for(int b=2; b<=8; b+=2){
				int result = getDivisior(b, coin);
				if(result == 0){
					pass = false;
					break; 
				}else{
					divisors[b-2] = result;
				}
			}
		}

		if(pass && !isDuplicate){
			for(int i=0; i<coin.size(); i++){
				cout << coin[i];
			}
			cout << " ";
			for(int i=0; i<9; i++){
				cout << divisors[i];
				if(i!=8){
				   cout << " ";
				}
			}
			cout << endl;

			longTermStorage.push_back(coin);
			nOutputs++;	
		}

	} 

	return 0;
}