#include<iostream>
#include<vector>

using namespace std;

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=1; n<=nCases; n++) {
		cout<<"Case #"<<n<<": ";
		int X,R,C;
		cin>>X>>R>>C;
		if(X>=7) {
			cout<<"RICHARD\n";
			continue;
		}
		if(R<X && C<X) {
			cout<<"RICHARD\n";
			continue;
		}
		if(R<(X+1)/2 || C<(X+1)/2) {
			cout<<"RICHARD\n";
			continue;
		}
		if((R*C)%X) {
			cout<<"RICHARD\n";
			continue;
		}
		cout<<"GABRIEL\n";
	}

	return 0;
}
