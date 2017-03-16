#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;
int pow10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int convert(int number, int digitsToChange, int digits){
	return (number / pow10[digitsToChange]) +  ((number % pow10[digitsToChange]) * pow10[digits - digitsToChange]);
}

int main(int argc, char *argv[]){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		cout << "Case #" << (i+1) << ": ";
		int A, B;
		int digits = 0;
		cin >> A >> B;
		int tmpA = A;
		while(tmpA > 0){
			digits++;
			tmpA /= 10;
		}
		int count = 0;
		for (int j = A; j <= B; j++){
			set<int> casados;
			for (int k = 1; k < digits; k++){
				int converted = convert(j, k, digits);
				if ((converted > j) && (converted <= B)){
					if (casados.count(converted) == 0){	
						casados.insert(converted);
						count++;
					}
				}
			}
		}
		cout << count << endl;
	}
}
