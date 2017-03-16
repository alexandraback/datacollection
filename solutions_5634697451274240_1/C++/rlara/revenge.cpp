#include<iostream>
#include<string>
using namespace std;

int calcula(string s){
	int cont=0;
	int f = s.length()-1;
	char c;
	while(s[f]=='+' && f>=0) f--;
	while(f>=0){
		cont++;
		c = s[f];
		if( f>0 ){
			while( f>0 && s[f] == c )
				f--;
			if(s[f]!=c )
				f++;
		}
		f--;

	}
	return cont;
}

int main(){
	int t;
	string s;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> s;
		cout << "Case #" << tt+1 << ": " << calcula(s) << endl;
	}
	return 0;
}
