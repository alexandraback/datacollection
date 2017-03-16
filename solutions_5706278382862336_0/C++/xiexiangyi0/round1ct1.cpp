#include<iostream>
#include<ctype.h>
#include<fstream>
#include<stdint.h>

using namespace std;

#define MAX (((uint64_t)1)<<40)

uint64_t gcd(uint64_t a, uint64_t b) {
    uint64_t c;
    while ( a != 0 ) {
	c = a; a = b%a;  b = c;
    }
    return b;
}

int main() {
    ifstream infile("A-small-attempt0.in");
    ofstream outfile("A-small0.out");
    int T;
    infile >> T;

    

    for(int i=0; i<T; i++) {
	uint64_t P, Q;
	char slash;
	infile >> P >> slash >> Q;
	outfile << "Case #" << i+1 << ": ";
	uint64_t g = gcd(Q, P);
	P = P/g;
	Q = Q/g;
	if((MAX % Q)!=0) {
	    outfile << "impossible";
	} else {
	    P = (MAX/Q*P);
	    for(unsigned j=1; j<=40; j++) {
		if(P >= (MAX>>j)) {
		    outfile << j;
		    break;
		}
	    }
	}
	outfile << endl;
    }

    return 0;
}
