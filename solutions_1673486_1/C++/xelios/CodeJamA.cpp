#include <iostream>

using namespace std;

int main(){
	int N;
	int A,B;
	int K;
	double min;
	double p;
	double a;
	double res;
	cin >> N;
	
	cout.precision(6);
	
	for(int i=1; i<=N; i++){
		cin >> A >> B;
		K = B-A+1;
		min = 2.0 + B;
		p = 1.0; 
		for(int j=A; j>0; j--, p*=a){
			cin >> a;
			res = p * (K+j+j) + (1-p) * (K+j+j+B+1);
			if(res<min) min = res;
		}
		res = p * K + (1-p) * (K+B+1);
		if (res<min) min = res;
		cout << "Case #" << i << ": " << fixed << min << endl;
	}
	
	return 0;
}
//if i press enter - 2 +B
//if i keep typing - mul(prob) * (B-A+1) + (1-mul(prob))*(B-A+1 + B+1)


//if i remove 3(all) chars - mul(prob[0..0]) - 2
//if i remove 2 char - mul(prob[0..1])  * (2 + (B-A+1 + 2)) + (1-mul(prob[0..1])) *
//if i remove 1 char - mul(prob[0..2])  * (1 + (B-A+1 + 1)) + (1-mul(prob[0..2])) *


//.. A-1 chars
