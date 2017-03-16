#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int T;
	int A,B;
	cin >> T;
	for ( int i = 1; i <=T; i++ ) {
		cin >> A >> B;
		vector<float> p;
		vector<float> pp;
		float px;
		float temp = 1.0;
		for ( int j = 0; j < A; j++ ) {
			cin >> px;
			p.push_back(px);
			pp.push_back(px*temp);
			temp = px;
		}
		int k = B-A+1;
		float min = B+2;
		for ( int j = 0; j < A; j++ ) {
			float e;
			e = pp[A-j-1]*(k+2*j) + (1-pp[A-j-1])*(k+2*j+B+1);
			if ( min > e ) {
				min = e;
			}
		}
		printf("Case #%d: %.6f\n",i,min);
	}
}
