#include <iostream>
#include <iomanip>
using namespace std;

void run() {
	long double C,F,X;
	cin >> C >> F >> X;
	if(X <= C) {
		cout << X/2.;
		return;
	}
	long double bestt=X/2.;
	long double curt=0;
	for(int N=0; N<1000000; N++) {
		curt+=C/(2+N*F);
		long double tfin=curt+X/(2+(N+1)*F);
		if(tfin < bestt) bestt=tfin;
	}
	cout << bestt;
}

int main() {
	int n;
	cin >> n;
	cout << fixed << setprecision(7);
	for(int i=0; i<n; i++) {
		cout << "Case #" << (i+1) << ": ";
		run();
		cout << endl;
	}
}