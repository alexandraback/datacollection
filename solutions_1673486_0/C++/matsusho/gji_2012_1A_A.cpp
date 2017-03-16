#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		int A,B;
		cin >> A >> B;
		vector<double> p(A);
		for(int a=0; a<A; a++){
			cin >> p[a];
		}
		double result = B+2;
		double correct_p = 1;
		for(int a=0;a<=A;a++){
			int back = A-a;
			double e = ((2*back+1+B-A)*correct_p) + (1-correct_p)*(2*back+1+B-A+B+1);
			if(result > e) result = e;
			correct_p *= p[a];
		}
		printf("Case #%d: %6f\n", t, result);;
	}
}