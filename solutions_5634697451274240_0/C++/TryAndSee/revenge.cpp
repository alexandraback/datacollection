#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


int main(){
	cout<<"launching function main"<<endl;
	ifstream file("B-small-attempt0.in");
//	ifstream file("B-large.in");
	ofstream outputfile("myoutput.txt");
	int T, nflip;
	string s;
	char c;
	file>>T; getline(file,s);
	for(int t=0;t<T;t++){
		//read input
		getline(file,s);
		//solve
		nflip=0;
		c='+';
		for(int i=s.length()-1; i>=0; i--){
			if(c!=s[i]){
				nflip++;
			}
			c=s[i];
		}
		//write output
		outputfile<<"Case #"<<(t+1)<<": "<<nflip<<endl;
	}
	file.close();
	outputfile.close();
}

