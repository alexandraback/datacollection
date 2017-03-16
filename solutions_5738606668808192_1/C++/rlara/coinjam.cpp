#include<iostream>
#include<vector>
using namespace std;

vector <int> p;
int cont;

bool es_primo(int k){
	for(int i=0;i<p.size() && i*i<=k;i++)
		if(k%p[i] == 0)
			return false;
	return true;
}

void primos(int n){
	for(int i=2;i<=n;i++){
		if(es_primo(i))
			p.push_back(i);
	}
}

bool divide(int aux[], int n, int l, int k){
	int r=1, pot=1;
	for(int i=0;i<n;i++){
		pot=(pot*l)%k;
		r = ( r+ (pot*aux[i]) )%k;
	}
	pot=(pot*l)%k;
	r = ( r+pot )%k;
	if(r==0)
		return true;
	else
		return false;
}

void imprime(int a[], int div[], int n){
	cout << "1";
	for(int i=n-1;i>=0;i--)
		cout << a[i];
	cout << "1";
	for(int i=2;i<=10;i++)
		cout << " " << div[i];
	cout << endl;
}

int coinjam(int aux[], int n){
	int div[11];
	for(int i=2;i<=10;i++){
		div[i]=-1;
		for(int j=0;j<p.size();j++){
			if( divide(aux, n, i, p[j]) ){
				div[i]=p[j];
				j=p.size();
			}
		}
		if(div[i]==-1)
			return 0;
	}
	//cout << cont << " -- > ";
	imprime(aux, div, n);
	return 1;
}

void busca(int n, int j, int aux[], int t){
	if( cont>=j) return;
	if(t<n){
		aux[t]=0;
		busca(n, j, aux, t+1);
		aux[t]=1;
		busca(n, j, aux, t+1);
		aux[t]=0;
	}
	else{
		cont+= coinjam(aux, n);
	}
}

int main(){
	primos(1000);
	int t, n, j;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> n >> j;
		cout << "Case #" << tt+1 << ":" << endl;
		int aux[n-2];
		busca(n-2, j, aux, 0);
		//cout << endl;
	}
	return 0;
}
