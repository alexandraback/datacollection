#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <list>

using namespace std;

long potenciaDeDos(long q){
	long res = 1;
	while(q > 2){
		//cout << q << "  "; 
		if((q & 1) == 1){
			return -1;
		}
		else{
			++res;
			q = q >> 1;
		}
	}
	if(q == 1){return -1;}
	//cout << "res " << res << endl;
	return res;

}

long potenciaDeDosImpar(long q){
	long res = 0;
	while(q > 1){
		++res;
		q = q >> 1;
	}
	return res;

}

int main(){
	
	int t;
	long p,q,a,b;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		cout << "Case #" << i << ": ";
		cin >> p;
		cin >> q;
		//cout << p << " " << q << endl;
		a = potenciaDeDos(q);
		//cout << a << endl;
		if(a == -1){
			cout << "impossible" << endl;
			continue;
		}
		b = potenciaDeDosImpar(p);
		cout << a-b << endl;
	}




	return 0;
}

