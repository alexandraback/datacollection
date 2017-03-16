#include<iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream saida;
	ifstream entrada;
	saida.open ("saida.txt");
	entrada.open ("entrada.txt");
	int t;
	entrada>>t;
	for(int i=0;i<t;i++){
		int r,c,w;
		entrada>>r>>c>>w;
		int minimo_ate_garantir_que_bate = r*(c/w);
		int result = minimo_ate_garantir_que_bate + (c%w>0 ? 1 : 0) + w-1;
		saida<<"Case #"<<i+1<<": "<<result<<endl;
	}
	entrada.close();
	saida.close();
	return 0;
}
