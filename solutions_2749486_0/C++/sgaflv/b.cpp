
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <iostream>
#include <assert.h>



#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define PI 3.14159265358979323
#define EPS 0.000000001
#define INF 1000000000

int T;



char lc;


int main() {
	cin>>T;
	int cs=1;
	char tc;
	
	while (T-->0) {
		
		int x,y;
		
		
		cin>>x>>y;
		
		printf("Case #%d: ", cs++);
		
		while (x>0) {printf("WE");x--;}
		while (x<0) {printf("EW");x++;}
		while (y>0) {printf("SN");y--;}
		while (y<0) {printf("NS");y++;}
		
		
		printf("\n");
	}
	
    return 0;
    
}


