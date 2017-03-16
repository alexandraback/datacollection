#include<iostream>
#include<string>
#include <fstream>
using namespace std;
int main(){
	ofstream myfile;
	myfile.open ("saida A.txt");

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int max,amigos=0,aplaudidos=0;
		string s;
		cin>>max;
		cin>>s;
		//aplaudidos+=s[0]-'0';
		for(int j=0;j<=max;j++){
			int sj= s[j]-'0';
			if (j>aplaudidos){
				amigos+=j-aplaudidos;
				aplaudidos=j;
			}
			aplaudidos+=sj;
		}
		myfile<<"Case #"<<i+1<<": "<<amigos<<endl;
		
		
	}
  myfile.close();
	return 0;
}

