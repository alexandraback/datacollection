#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int T;
	cin >> T;
	for( int t=0; t<T; t++ ){
		double C, F, X;
		cin >> C >> F >> X;
		double sum = 0, rate = 2.0;
		while( 1 ){
			double next;
			next = C / rate;
			if( X/rate > X/(rate+F)+next ){
				sum += next;
				rate += F;
			}else{
				sum += X/rate;
				break;
			}
		}
		printf("Case #%d: %.7f\n", t+1, sum);
	}
}
