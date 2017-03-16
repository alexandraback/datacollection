#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int compareAsc (const void * a, const void * b){
	return ( *(int*)a - *(int*)b );
}

int compareDsc (const void * a, const void * b){
	return ( *(int*)b - *(int*)a );
}


int main(){
	int t, a, b, i, j;
	double p, pc;
	double e, oe;
	cin >> t;
	for (i=0; i<t; i++) {
		cin >> a >> b;
		cin >> p;
		oe = 2.0*(a-1.0)+b-a+1.0+(1.0-p)*(b+1.0);
		for (j=2; j<=a; j++){
			cin>>pc;
			p *= pc;
			e = 2.0*(a-j)+b-a+1.0+(1.0-p)*(b+1.0);
			if (e<oe) {
				oe = e;
			}
		}
		if (b+2<oe) {
			oe = b+2;
		}
		//cout << "Case #" << (i+1) <<": "<<oe<<endl;
		printf("Case #%d: %.6f\n", (i+1), oe);
	}
	
	return 0;
}