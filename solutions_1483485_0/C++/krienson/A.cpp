/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int A[300];

void process(string &s){
	for (int i=0; i<int(s.LE); i++) {
		s[i] = char(A[int(s[i])]);
	}
}

int main(){
	for(int i=0;i<300;i++) A[i] = i;
	string a = "yhesocvxduiglbkrztnwjpfmaq";
	for (int i = int('a'),j=0; i<=int('z'); i++,j++) {
		A[i] = int(a[j]);
	}
	int N,kases = 1; cin>>N;
	string s; getline(cin,s);
	while (kases <= N) {
		getline(cin,s);
		process(s);
		cout<<"Case #"<<kases++<<": "<<s<<endl;
	}
}