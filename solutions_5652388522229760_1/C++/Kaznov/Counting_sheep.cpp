//============================================================================
// Name        : Counting_sheep.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool znane[10];
int nieznane;

void rozbij(int a){
	while(a){
		int x = a%10;
		a/=10;
		if(!znane[x]){
			znane[x]=true;
			--nieznane;
		}
	}
}

int main() {
	int t;
	cin >> t;
	for(int i=0; i<t; ++i){
		long long int sprawdzana;
		cin >> sprawdzana;

		long long int obrabiana = 0;
		if(sprawdzana!=0){
			for(int j=0; j<10; ++j) znane[j]=false;
			nieznane = 10;
			while(nieznane){
				obrabiana+=sprawdzana;
				rozbij(obrabiana);
			}
			cout << "Case #" << i+1 << ": " << obrabiana << "\n";
		}
		else cout << "Case #" << i+1 << ": INSOMNIA" << "\n";


	}

	return 0;
}
