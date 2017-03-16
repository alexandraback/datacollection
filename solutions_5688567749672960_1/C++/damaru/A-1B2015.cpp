#include <iostream>
#include <string>

using namespace std;


typedef long long int ll;

ll semiexp (int n){
	n = (n+1)/2;
	ll res = 1;
	while (n--){
		res*=10;
	}
	return res;
}


int cifras (ll n){
	int res = 0;
	while (n){
		res++;
		n/=10;
	}
	return res;
}

int main() {
    int i, j, t, cont=0;
    ll aux, n, aux2, resul, asd;
    bool esp;
    cin >>t;
    int a[20];
    a[1]= 9;
    for (i=2; i<17; i++){
    	aux = semiexp (i);
    	a[i]= a[i-1]+ aux-1;
    	if (i & 1){
    		a[i]+=(aux/10);
    	}
    	else{
    		a[i]+=aux;
    	}
    }
    for (i=0; i<t; i++){
    	esp = false;
    	cout << "Case #" << ++cont << ": ";
    	cin >> n;
    	if (n==10){cout << 10 << endl; continue;}
    	if (n%10 == 0){n-=1; esp = true;}

    	if (n < 12) {
    		cout << n << endl; continue;
    	}
    	aux = cifras (n);
    	aux2 =  semiexp(aux);
    	resul = n % aux2;
    	n/=aux2;
    	asd = 0;
    	while (n){
    		asd= (asd*10) + (n%10);
    		n/=10;
    	}
    	if (asd == 1) asd--;
    	resul =  resul + asd + a[aux-1]+1;
    	if (esp) resul++;
    			cout  << resul << endl;
    }
    return 0;
}
/*

*/
