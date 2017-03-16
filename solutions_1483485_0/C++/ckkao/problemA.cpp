#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main() {
	ifstream fin("input");
	ofstream fout("output");
	char list[26] = {'y','h','e','s', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r','z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	int nCount;
	char input[1000];
	
	/*
	for(int nloop=1; nloop<=3; ++nloop) {
		cin.getline(input,100);
		cin.getline(output,100);

		for(int i=0; input[i]!='\0'; ++i) {
			if(input[i]==' ') continue;
			list[ input[i]-97 ] = output[i];
		}
	}*/

	//for(int i=0; i<26; ++i) fin >> list[i];
	//for(int i=0; i<26; ++i) cout << "'" << list[i] << "', ";
	//cout<<endl;
	
	fin.getline(input,1000);
	nCount = atoi(input);
	for(int i=1; i<=nCount; ++i) {
		fin.getline(input,1000);
		fout<<"Case #"<<i<<": ";
		for(int j=0; j<strlen(input); ++j) {
			if(input[j]==' ') {fout<<" "; continue;}
			fout << list[ input[j]-'a'];
		}
		fout<<endl;
	}
	//system("pause");
}