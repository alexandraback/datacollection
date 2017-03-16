#include <iostream>
typedef unsigned long long int number;

int main(){
	int casos;
	std::cin >> casos;
	for(int T=0; T<casos; ++T){
		number conteo=0;
		int limA, limB, limK;
		std::cin>>limA>>limB>>limK;
		for(int K=0; K<limK; ++K)
			for(int A=0; A<limA; ++A)
				for(int B=0; B<limB; ++B)
					if( (A&B) == K)
						++conteo;
		std::cout << "Case #" << T+1 << ": ";
		std::cout << conteo << '\n';
	}
}
