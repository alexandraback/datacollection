#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
ifstream in("lang.txt");
ofstream out("langout.txt");

string original 	= "abcdefghijklmnopqrstuvwxyz";
string convert		= "abcdefghijklmnopqrstuvwxyz";
string test[30], input;
int cases;
char temp, input1, input2;


int main(){
	in>>cases;
	for(int i = 0; i < cases; i++){
		while(1){
			in>>input;
			test[i] += input;
			temp = in.get();
			if(temp=='\n') break;
			test[i] += temp;
		}
	}

	//begin interaction
	while(1){
		cout<<original<<"\n"<<convert<<"\n";
		for(int i = 0; i < cases; i++){
			cout<<"Case #"<<i+1<<": ";
			for(int j = 0; j < test[i].size(); j++){
				if(test[i][j]==' ') cout<<' ';
				else{
					int counter = -1;
					while(convert[++counter]!=test[i][j]);
					cout<<(char)(original[counter]);
				}
			}
			cout<<"\n";
		}
		cin>>input1>>input2;
		if(input1=='0') break;
		temp = convert[input1-'a'];
		convert[input1-'a'] = convert[input2-'a'];
		convert[input2-'a'] = temp;
	}
	//output;
	for(int i = 0; i < cases; i++){
			out<<"Case #"<<i+1<<": ";
			for(int j = 0; j < test[i].size(); j++){
				if(test[i][j]==' ') out<<' ';
				else{
					int counter = -1;
					while(convert[++counter]!=test[i][j]);
					out<<(char)(original[counter]);
				}
			}
			out<<"\n";
		}
	return 0;
}
