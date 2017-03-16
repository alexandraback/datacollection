#include<iostream>
#include<algorithm>
#include<utility>
#include<string>

using namespace std;

void imprime(string s){
	if(s.length()>0){
	char c=0;
//	cout << s << endl;
	int pos=0;
	//cout << s.length()<< endl;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]>c){
			c=s[i];
			pos=i;
		}
	}
	cout << s[pos];
	string aux="";
	for(int i=0;i<pos;i++)
		aux.push_back(s[i]);
	imprime(aux);
	for(int i=pos+1;i<s.length(); i++){
		cout << s[i];
	}
	}
}

int main(){
	int t, n, k;
	cin >> t;
	string s;
	for(int tt=0;tt<t;tt++){
		cin >> s;
		cout << "Case #" << tt+1 << ": ";
		imprime(s);
		cout << endl; 
	}
	return 0;
}
