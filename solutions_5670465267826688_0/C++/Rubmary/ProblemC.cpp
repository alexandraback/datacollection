#include <iostream>
using namespace std;

int multiply (int x, int y);

int main () {
	
	bool isPossible;
	int T;
	int L, X;
	string str1, str;
	cin >> T;
	
	for (int k=1; k<=T; k++) {
		cin >> L >> X;
		cin.get();
		getline(cin, str1);
		int a, b, c;
		c=0;
		str="";
		
		for (int i=1; i<=X; i++)
			str+=str1;
		L*=X;
		

		a=1;
		isPossible=false;
		int i=0;
		while (i<L && a!=2) {
			b=str[i]-103;
			a=multiply(a, b);
//			cout << a << ' ';
			i++;
		}
		
//		cout << endl;
		a=1;
		
		while (i<L && a!=3) {
			b=str[i]-103;
			a=multiply(a, b);
			i++;
//			cout << a << ' ';
		}
		
//		cout << endl;
		a=1;
		while (i<L) {
			b=str[i]-103;
			a=multiply(a, b);
			i++;
			c=a;
//			cout << a << ' ';
	
		}
		
		if (c==4)
			isPossible=true;
		
//		cout << endl;
		
		cout << "Case #" << k << ": ";
		if (isPossible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}

int multiply (int x, int y) {
	
	if (x>0 && y>0) {
		if (x==1)
			return y;
		if (y==1)
			return x;
		if (x==y)
			return -1;
		if (x==2) {
			if (y==3)
				return 4;
			if (y==4)
				return -3;
		}
		if (x==3) {
			if (y==2)
				return -4;
			if (y==4)
				return 2;
		}
		if (x==4) {
			if (y==2)
				return 3;
			if (y==3)
				return -2;
		}
	}
	

	if (x<0)
		return -1*multiply (-1*x, y);
	if (y<0)
		return -1*multiply (x, -1*y);
	
	return 0;
}

