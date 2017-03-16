#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int A,B;
int shift(int a,int x) {
	return a/10+a%10*x;
}
int main() {
	int cases;
	cin>>cases;
	for (int c=1;c<=cases;c++) {
		cin>>A>>B;
		int ans=0;
		for (int a=A,b=a;b<=B;a++,b++) {
			int x=1;
			while (x<=a) x*=10;
			x/=10;
			while ((a=shift(a,x))!=b)
				if (A<=a && a<=B && a<b && a/x!=0) ans++;
		}
		cout<<"Case #"<<c<<": "<<ans<<endl;
	}
	return 0;
}
