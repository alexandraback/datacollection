#include<iostream>
#include<fstream>
using namespace std;
void train(int *cipher){
	char sentence[3][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	char translate[3][100]={"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"};
	for(int i=0;i<3;i++){
		for(int j=0;sentence[i][j]!='\0';j++){
			if(sentence[i][j]==' '){
				if(translate[i][j]!=' '){
					cout<<"bug"<<endl;
				}
				continue;
			}
			if(cipher[sentence[i][j]-'a']!=-1){
				if(cipher[sentence[i][j]-'a']+'a'!=translate[i][j]){
					cout<<"bug"<<endl;
				}
			}
			cipher[sentence[i][j]-'a']=translate[i][j]-'a';
			
			//missing part
			cipher['q'-'a']='z'-'a';
			cipher['z'-'a']='q'-'a';
		}
	}
	
}
int main(){
	ofstream fout;
	fout.open("E:\\decipher.txt");
	int cipher_code[26];
	for(int i=0;i<26;i++){
		cipher_code[i]=-1;
	}
	train(cipher_code);
	int T;
	cin>>T;
	cin.get();
	for(int j=0;j<T;j++){
		char input[200];
		char output[200];
		cin.getline(input,200);
		int i;
		for(i=0;input[i]!='\0';i++){
			if(input[i]==' ')
				output[i]=' ';
			else
				output[i]=cipher_code[input[i]-'a']+'a';
		}
		output[i]='\0';
		cout<<"Case #"<<(j+1)<<": "<<output<<endl;
		fout<<"Case #"<<(j+1)<<": "<<output<<endl;
		fout.flush();
	}
	fout.close();
	return 0;
}