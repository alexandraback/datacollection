#include<iostream>
using namespace std;

int d[10];

int calcula(int n, int k, int cont){
	int aux=n, r;
	while(aux>0){
		r=aux%10;
		aux/=10;
		if(d[r]==0){
			d[r]=1;
			cont++;
		}
	}
	if(cont>=10)
		return n;
	else
		return calcula(n+k, k, cont);
}

void hazcero(){
	for(int i=0;i<10;i++)
		d[i]=0;
}

int main(){
	int t, n;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> n;
		if( n == 0){
			cout << "Case #" << tt+1 << ": INSOMNIA" << endl;
		}
		else{
			hazcero();
			cout << "Case #" << tt+1 << ": " << calcula(n, n, 0) << endl;	
		}
	}
	return 0;
}
