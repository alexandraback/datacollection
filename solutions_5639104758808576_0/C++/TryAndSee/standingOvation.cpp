#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(){
	cout<<"launching function main"<<endl;
	ifstream file("A-small-attempt0.in");
	ofstream outputfile("myoutput.txt");
	int T, shy, maxshyness, standing, toAdd;
//	vector<int> shyness;
	string shyness;
	file>>T;
	for(int t=0;t<T;t++){
		//reading input
		file>>maxshyness>>shyness;
		//solving
		standing = 0;
		toAdd=0;
		outputfile<<"Case #"<<(t+1)<<": ";
		for(int i=0; i<=maxshyness; i++){
			shy=shyness[i]-'0';
			if(standing<i){
				toAdd+=(i-standing);
				standing=i+shy;
			}else{
				standing+=shy;
			}
		}
		outputfile<<toAdd<<endl;
	}
	file.close();
	outputfile.close();
}

