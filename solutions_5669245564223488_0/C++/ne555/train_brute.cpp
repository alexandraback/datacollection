#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

typedef unsigned long long int number;
number modulo = 1000000007;

std::string concatenar(std::vector<std::string> &car){
	std::string s;
	for(int K=0; K<car.size(); ++K)
		s += car[K];
	return s;
}
bool valid(std::vector<std::string> &car){
	std::string s = concatenar(car);
	std::vector<bool> visto('z'-'a'+1, false);
	visto[s[0]-'a'] = true;
	for(int K=1; K<s.size(); ++K){
		if( s[K] not_eq s[K-1] ){
			if(not visto[s[K]-'a'])
				visto[s[K]-'a'] = true;
			else
				return false;
		}
	}
	return true;
}

number factorial(int n){
	if(n==0) return 1;
	return n*factorial(n-1);
}

void magia(std::vector<std::string> &car){
	number total = 0;
	number lim = factorial(car.size());
	for(number K=0; K<lim; ++K){
		if( valid(car) )
			++total;
		std::next_permutation(car.begin(), car.end());
	}

	std::cout << total;
}

int main(){
	int casos;
	std::cin >> casos;
	for(int K=1; K<=casos; ++K){
		int n;
		std::cin >> n;
		std::vector<std::string> car(n);
		for(int L=0; L<n; ++L)
			std::cin >> car[L];
		std::sort(car.begin(), car.end());

		std::cout << "Case #" << K << ": ";
		magia(car);
		std::cout << '\n';
	}
}

