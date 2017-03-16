#include <bits/stdc++.h>
using namespace std;


int main(){
	int t;
	scanf("%i", &t);
	for (int test_case = 1; test_case <= t; test_case++){
		int x,r,c;
		scanf("%i %i %i", &x, &r, &c);
		bool can = true;

		if (r*c % x > 0) can = false;
		if (x > max(r, c)) can = false;
		if (min(r,c) == 1 && max(r,c) > 2 && max(r,c) == x) can = false;
		if (min(r,c) == 2 && max(r,c) == 4 && x == 4) can = false;
		
		printf("Case #%i: %s\n", test_case, can? "GABRIEL" : "RICHARD");
	}
}