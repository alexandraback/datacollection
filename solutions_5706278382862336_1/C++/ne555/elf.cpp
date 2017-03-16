#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <iterator>
#include <vector>

typedef unsigned long long int number;

number gcd(number a, number b){
	if( b==0 ) return a;
	return gcd(b, a%b);
}

void simplify(number &n, number &d){
	number common = gcd(n,d);
	n /= common;
	d /= common;
}

bool existe(number n, number d, int lim){
	if(n==d/2 and d%2==0) return true;
	if(lim<0) return false;
	if(lim==0)
		return n==0 or n==1 and d==1;

	number mitad = d/2;
	if(n<mitad){
		number nuevo = 2*n;
		simplify(nuevo, d);
		return existe(nuevo, d, lim-1);
	}
	else{
		number nuevo = 2*n-d;
		simplify(nuevo, d);
		return existe(nuevo, d, lim-1);
	}
}

int busqueda(number n, number d, int lim){
	if(n==d/2 and d%2==0) return 1;
	if(lim<0) return -1;
	if(lim==0)
		return (n==1 and d==1)? 0: -1;

	number mitad = d/2;
	if(n<mitad){
		number nuevo = 2*n;
		simplify(nuevo, d);
		int result = busqueda(nuevo, d, lim-1);
		if( result == -1 ) return -1;
		return 1+result;
	}
	else{
		number nuevo = 2*n-d;
		simplify(nuevo, d);

		if( busqueda(nuevo, d, lim-1)==-1 )
			return -1;
		return 1;
	}
}


void magia(number n, number d){
	simplify(n,d);
	int lim = 40;
	int generaciones = busqueda( n, d, lim );

	if(generaciones==-1)
		std::cout <<  "impossible";
	else
		std::cout << generaciones;
}

int main(){
	int casos;
	std::cin >> casos;
	for(int K=1; K<=casos; ++K){
		number num, den;
		std::cin >> num; std::cin.ignore(); std::cin >> den;
		std::cout << "Case #" << K << ": ";
		magia(num, den);
		std::cout << '\n';
	}
}
