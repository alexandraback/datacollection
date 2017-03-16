#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int t, tc;
double C, F, X;
double rate;
double mn;

int main(){
	cin >> t;
	while( t-- ){
		cin >> C >> F >> X;
		rate = 2.0;
		mn = HUGE_VAL;
		double sum = 0.0;
		bool changed = true;
		while( changed ){
			changed = false;
			// try straight
			double x = X / rate;
			double straight = sum + x;
			if( mn > straight ){
				mn = straight;
				changed = true;
			}
			// try detour
			double drop = C / rate;
			sum += drop;
			rate += F;
		}
		printf( "Case #%d: %.7lf\n", ++tc, mn );
	}
}
