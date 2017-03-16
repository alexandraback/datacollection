#include <iostream> 
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
using namespace std;

void fn();

/*
class Fraction{
private:
	long long num, dem;

	long long gcd(long long a, long long b){
		if(a == 0){
			return b;
		}
		return gcd(b%a, a);
	};

public: 
	Fraction(){num = 0; dem = 0;};
	Fraction(long long a, long long b){num = a; dem = b;};

	long long getNum(){return num;};
	long long getDem(){return dem;};

	void reduce(){
		long long div = gcd(num, dem);
		num /= div;
		dem /= div;
	}
	
	void averageWith(Fraction b){
		num = num*b.getDem() + b.getNum() * dem;
		dem *= b.getDem();

		reduce();
	}

	void printAns(){
		reduce();

		long long temp = 2; 

		bool match = false;
		for(int i = 0; i < 40; i++){
			if(temp == dem){match = true;}
			temp *= 2;
		}

		if(!match){cout << "impossible\n"; return;}

		int i = 0; 
		while(dem > num){
			dem /= 2;
			i++;
		}

		cout << i << endl;

	}
};
*/

int
main(){
	srand(time(NULL));
	int nTest; 

	cin >> nTest;

	for(int i = 1; i <= nTest; i++){
		cout << "Case #" << i << ": ";
		fn();
	}

	return 0;
}

int fn2(int M, int N, int K){
	if(M == 3 && N == 3){
		if(K >= 5){return K - 1;}
		else return K;
	}
	if(M == 3 && N == 4){
		if(K < 5){return K;}
		if(K >=5 && K <=7){return K - 1;}
		return K - 2;
	}
	if(M == 3 && N == 5){
		if(K < 5)return K;
		if(K >= 5 && K <= 7) return K-1;
		if(K >= 8 && K <= 10) return K-2; 
		return K - 3;
	}
	if(M == 4 && N == 4){
		if (K < 5) return K;
		if(K >= 5 && K <= 7) return K-1;
		if(K >= 8 && K <= 9) return K-2;
		if(K >= 10 && K <= 11) return K-3;
		return K-4;
	}
	if(M==4 && N ==5){
		if(K<5)return K;
		if(K>=5 && K <= 7) return K-1;
		if(K>= 8 && K <= 9) return K-2;
		if(K>=10 && K <= 11) return K-3;
		if(K>=12 && K <= 13) return K-4;
		if(K>=14 && K <= 15) return K-5;
		return K - 6;
	}
	if(M==3 && N == 6){
		if(K<5)return K;
		if(K>=5 && K<=7) return K-1;
		if(K>= 8 && K<= 10) return K-2;
		if(K>= 11 && K <= 13) return K-3;
		return K-4;
	}

	return K;
}

void fn(){
	int M, N, K; 

	cin >> M >> N >> K; 

	if(M > N){
		int temp = M; 
		M = N; 
		N = temp;
	}

	cout << fn2(M, N, K)<< endl; 
}