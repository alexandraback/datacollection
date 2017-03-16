#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>

using namespace std;

int d[10];

string elimina(char c, string aux, string num, int dig){
	string nuevo;
	int cont=0;
	int arr[aux.size()];
	bool nocambio;
	for(int i=0;i<aux.size();i++)
		arr[i]=0;
	for(int i=0;i<aux.size();i++)
		if(aux[i]==c)
			cont++;
	d[dig]+=cont;
	for(int i=0;i<aux.size();i++){
		nocambio=true;
		for(int j=0;j<num.size();j++){
			if(aux[i]==num[j] && arr[j]<cont){
				arr[j]++;
				nocambio=false;
			}
		}
		if( nocambio ) nuevo.push_back(aux[i]);
	}
	return nuevo;
}


int main(){
	int t;
	string s;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> s;
		for(int i=0;i<10;i++)
			d[i]=0;
		cout << "Case #" << tt+1 << ": ";
		s = elimina('Z', s, "ZERO", 0);
		s = elimina('W', s, "TWO", 2);
		s = elimina('X', s, "SIX", 6);
		s = elimina('G', s, "EIGHT", 8);
		s = elimina('U', s, "FOUR", 4);
		s = elimina('T', s, "THREE", 3);
		s = elimina('F', s, "FIVE", 5);
		s = elimina('S', s, "SEVEN", 7);
		s = elimina('O', s, "ONE",1);
		s = elimina('I', s, "NINE", 9);
		for(int i=0;i<10;i++){
			for(int j=0;j<d[i];j++)
				cout << i;
		}
		cout << endl; 
	}
	return 0;
}







