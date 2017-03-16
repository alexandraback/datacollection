#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void calculardif(string C, string J, string *Csol, string *Jsol);
void calcularSig(string *S, string C);

int main(){
	int T;
	string C,J,Csol,Jsol;
	cin>>T;
	for(int i=0;i<T;i++){
		cin>>C>>J;
		calculardif(C,J,&Csol,&Jsol);
		cout<<"Case #"<<(i+1)<<": "<<Csol<<" "<<Jsol<<endl;
	}
}

void calculardif(string C, string J, string *Csol, string *Jsol){
	int dif = 2000;
	int maxc = 2000;
	string Caux = C;
	string Jaux = J;
	string Cini;
	string Jini;
	
	//inicializar
	for(int i=0;i<C.length();i++){
		if(Caux[i]=='?'){
			Caux[i]='0';
		}
		if(Jaux[i]=='?'){
			Jaux[i]='0';
		}
	}
	Cini = Caux;
	Jini = Jaux;
	//inf bucle
		//inf bucle
			//calcular diferencia de esos dos
			//ver si es una mejor solucion
			//calcular siguiente del J
			//si J es el inicial break
		//calcular siguiente del C
		//si C es el inicial break
	//end
	while(true){
		while(true){
			int a = atoi(Caux.c_str());
			int b = atoi(Jaux.c_str());
			int difer = abs(a-b);
			int maximc = a;
			if(difer<dif){
				dif = difer;
				maxc = maximc;
				*Csol = Caux;
				*Jsol = Jaux;
			}
			else if(difer==dif){
				if(maximc<maxc){
					maxc = maximc;
					*Csol = Caux;
					*Jsol = Jaux;
				}
			}
			calcularSig(&Jaux,J);
			if(Jaux.compare(Jini)==0) break;
		}
		calcularSig(&Caux,C);
		if(Caux.compare(Cini)==0) break;
	}
}

void calcularSig(string *S, string C){
	int pos = C.length()-1;
	//string cojonesHostiaPutaMeCagoEnLosPunteros = *S;
	int aux;
	while(true){
		if(C[pos]=='?'){
			aux = (*S)[pos] - '0';
			aux++;
			if(aux!=10){
				(*S)[pos]=aux+'0';
				break;
			}
			else{
				(*S)[pos]='0';
			}
		}
		pos--;
		if(pos<0) break;
	}
}
