#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    double p[100000];
    double pp[100000];
    double opt;
    cin >> TIME;
    for (int t = 0 ; t < TIME; t++) {
	int A,B;
	cin >> A >> B;
	for (int i = 0 ; i < A; ++i) {
	    cin >> p[i];
	    pp[i] = 1.0;
	}
	pp[0] = p[0];
	for (int i = 1 ; i < A; ++i) {
	    pp[i] = pp[i-1]*p[i];
	}
	opt = B+2.0;// enter
	double tmp;
//	tmp = (1.0+B-A)*(pp[A-1]) + (1.0-pp[A-1])*(2.0+B+B-A);
//	opt = (opt > tmp?tmp:opt);
	for (int i = A-1,j=0; i >=0; --i,j++) {
	    tmp = (1.0+B-A+2.0*j)*(pp[i] ) + (1.0-pp[i])*(2.0+B+B-A+2.0*j);
//	    cout << tmp << endl;
	    opt = (opt > tmp?tmp:opt);
	}
	//output
	printf("Case #%d: %lf\n",t+1, opt);
    }
    return 0;
}
