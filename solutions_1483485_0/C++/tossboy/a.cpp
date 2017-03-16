#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
using namespace std;

char trans[500];
int T;

int main(){
	string fr, to;
	ifstream dic("dic");
	getline(dic, fr);
	getline(dic, to);
	assert(fr.size() == to.size());
	for(int i=0; i<fr.size(); i++)
		trans[fr[i]] = to[i];
	
	cin>>T;
	getline(cin, fr);
	for(int ca=1; ca<=T; ca++){
		cout<<"Case #"<<ca<<": ";
		getline(cin, fr);
		for(int i=0; i<fr.size(); i++)
			cout<<trans[fr[i]];
		cout<<endl;
	}
	return 0;
}
