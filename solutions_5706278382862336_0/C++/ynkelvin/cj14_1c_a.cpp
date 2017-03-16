#include <iostream>
using namespace std;

int gcd(int x, int y){
	int a;
	for(int i=1;i<=x&&i<=y;i++){


     if(x%i==0 && y%i == 0 ){

                     a=i;

  	}

}	
return a;
}

int isPowerOfTwo (unsigned int x)
{
 while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
   x /= 2;
 return (x == 1);
}

int main(){
	int T, P, Q;
	char buf;
	cin >> T;
	for (int i=1;i<=T;i++){
		int c=0;
		cin >> P >> buf>>Q;
		cout << "Case #"<<i<<": ";

		int g= gcd(P,Q);
		P /= g;
		Q /= g;

		if (isPowerOfTwo(Q)){
			while (P*2<Q){
				P*=2;
				c++;
			}
			cout << c+1 <<endl;
		} else {
			cout << "impossible\n";
		}
	}
	return 0;
}