#include <iostream>

using namespace std;

int T,X,R,C;

int min(int a, int b) {
	if (a<b) return a; else return b;
}

bool solve(int x, int r, int c) {
	if (r*c%x != 0) return true;
	if (r==1) return (x>2);
	return (x>=min(r,c)*2);
}

int main() {
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>X>>R>>C;
		if (R>C) {
			int a=R;R=C;C=a;
		}
		if (solve(X,R,C)) {
			cout<<"Case #"<<t<<": RICHARD"<<endl;
		} else {
			cout<<"Case #"<<t<<": GABRIEL"<<endl;
		}
	}
	return 0;
}