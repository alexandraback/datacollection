#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa



int main(){
	int T;
	double C, F, X, tiempo, Fact, tr, proxima;
	cin >> T;
	for(int caso=1;caso<=T;caso++){
		cin >> C >> F >> X;
		tr = C/F;
		
		tiempo = 0.0;
		Fact = 2.0;
		
		proxima = C/Fact;
		while(X/Fact>tr+proxima){
			tiempo += proxima;
			Fact += F;
			proxima = C/Fact;
		}
		tiempo += X/Fact;
		
		printf("Case #%d: %.7lf\n", caso, tiempo);
	}
	return 0;
}
