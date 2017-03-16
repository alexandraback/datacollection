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

void fn(){
	long long P, Q; 
	char dummy;

	cin >> P >> dummy >> Q;

	Fraction f(P, Q);
	f.printAns();
}