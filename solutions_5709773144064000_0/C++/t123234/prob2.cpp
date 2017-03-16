#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int order[2][17];

int main(){
	int t, i, j, k;
	double c, f, x;
	double r, ans, e, tmp;

	cin>>t;
	for (i = 0; i < t; ++i){
		cin>>c>>f>>x;

		r = 2.0;
		ans = x/r;
		
		e = c/r;
		while ( (tmp=(x/(r+f)+e))<ans){
			r += f;
			e += c/r;

			ans = tmp;
		}
		printf("Case #%d: %.7f\n", i+1, ans);
	}
	
	return 0;
}