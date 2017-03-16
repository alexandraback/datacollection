#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#define FOR(i,n) for(int i = 0, n_ = (n); i<n_; i++)

using namespace std;

int main(){
	int T, A, B;
	double p, prod_p, min_stroke, stroke;
	cin>>T;
	FOR(test,T){
		cin>>A>>B;
		prod_p=1.0;
		min_stroke = B+2;
		FOR(i,A) {
			cin>>p;
			prod_p *= p;
			stroke = prod_p * (B + A - 2*(i+1) + 1);
			stroke += (1-prod_p) * (2*B + A - 2*(i+1) + 2);
			if (stroke < min_stroke) min_stroke = stroke;
		}

		cout<<"Case #"<<test+1<<": "<<setprecision(19)<<min_stroke<<endl;
	}
	return 0;
}