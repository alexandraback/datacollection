#include<iostream>
#include<iomanip>
using namespace std;
int main() {
unsigned int T, A, B;
long double p[100000], keystrokes, small, x;
cin>>T;
for(int i=0;i<T;i++) {
	cin>>A>>B;
	x=1.0;
	for(int j=0;j<A;j++) {
		cin>>p[j];
		p[j]=p[j]*x;
		x=p[j];
	}
	if(A>0) {
	small=(float)B+2;
	for(int x=0;2*x<=1+A&&x<A;x++) {
		keystrokes=p[A-1-x]*(B-A+1+2*x)+(1-p[A-1-x])*(2*(B+1+x)-A);
		//cout<<keystrokes<<"\n";
		if(keystrokes<small)
			small=keystrokes;
	}
	}
	else
		small=(float)B+1;
	cout << setprecision(16);
	cout<<"Case #"<<i+1<<": "<<small<<"\n";
}
return 0;
}

