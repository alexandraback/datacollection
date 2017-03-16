#include <iostream>
#include <vector>

using namespace std;

unsigned long long e, r, n, res;
vector<unsigned long long> valores;

unsigned long long saturar(unsigned long long e, unsigned long long d);
unsigned long long calcular(unsigned long long restante, unsigned long long it);

int main(){
	
	unsigned long long T, k=1;
	
	cin >> T;
	
	while (k<=T){
		res = 0;
		
		cin >> e >> r >> n;
		
		valores.resize(n);
		
		for (unsigned long long i = 0; i < n; i++)
		{
			cin >> valores[i];
		}
		
		res = calcular(e, 0);
		
		cout << "Case #" << k << ": " << res << endl;
		
		++k;
	}
	
	return 0;
}

unsigned long long calcular(unsigned long long restante, unsigned long long it){
	if (it == n){
		return 0;
	} else{
		unsigned long long max=0, aux;
		
		for (unsigned long long usar = 0; usar <= restante ; usar++)
		{
			if ( (aux=calcular( saturar(e, restante-usar+r) , it+1 ) + usar*valores[it] ) > max )
				max = aux;
		}
		
		return max;
	}
}

unsigned long long saturar(unsigned long long e, unsigned long long d){
	if (d>=e)
		return e;
	else
		return d;
}
