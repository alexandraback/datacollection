#include <iostream>
using namespace std;

/*long long int gcd(long long int x, long long int y){
	long long int a;
	for(long long int i=1;i<=x&&i<=y;i++){


     if(x%i==0 && y%i == 0 ){

                     a=i;

  	}

}	
return a;
}*/

long long int     gcd( long long int a, long long int b ) {
    long long int     r;
     
    while ( b ) {
        r = a % b;
        a = b;
        b = r;
    }
     
    return a;
}

long long int isPowerOfTwo (unsigned long long int x)
{
 while (((x % 2) == 0) && x > 1) /* While x is even and > 1 */
   x /= 2;
 return (x == 1);
}

int main(){
	long long int T, P, Q;
	char buf;
	cin >> T;
	for (long long int i=1;i<=T;i++){
		long long int c=0;
		cin >> P >> buf>>Q;
		cout << "Case #"<<i<<": ";

		long long int g= gcd(P,Q);
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