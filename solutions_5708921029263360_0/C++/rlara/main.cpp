#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>

using namespace std;

int arr[5];
int aux, ini;

void todo(int j, int p, int s, int cont){

	if(cont==0){
		for(int i=1;i<=j;i++){
			arr[cont]=i;
			todo(j,p,s,cont+1);
		}
	}
	else if(cont==1){
		for(int i=1;i<=p;i++){
			arr[cont]=i;
			todo(j,p,s,cont+1);
		}
	}
	else if(cont==2){
		for(int i=1;i<=s;i++){
			arr[cont]=i;
			todo(j,p,s,cont+1);
		}
	}
	else{
		cout << arr[0] << " " <<  arr[1] << " " << arr[2] << endl;
	}
}

void resuelve(int j, int p, int s, int k, int cont){
	if(cont==0){
		for(int i=1;i<=j;i++){
			arr[cont]=i;
			resuelve(j,p,s,k,cont+1);
			ini++;
		}
	}
	else if(cont==1){
		for(int i=1;i<=p;i++){
			arr[cont]=i;
			resuelve(j,p,s,k,cont+1);
		}
	}
	else{
		//cout << aux << " " << ini << endl;	
		cout << arr[0] << " " <<  arr[1] << " " << (aux+ini)%p +1 << endl;
		aux++;
	}
}

int main(){
	int t;	
	int j, p, s, k;		
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> j >> p >> s >> k;
		int min= j*p*s< j*p*k? j*p*s : j*p*k;
		cout << "Case #" << tt+1 << ": " << min << endl;;
		if(j*p*s==min)
			todo(j,p,s, 0);
		else
			for(int i=0;i<k;i++){
				aux=0; ini=0;
				resuelve(j,p,s,k,0);
			} 
	}
	return 0;
} 
