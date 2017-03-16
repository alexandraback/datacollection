#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void prod(char & first, char second){
	switch(first){
		case '1':
			switch(second){
				case '1':
					first='1';
					break;
				case 'i':
					first='i';
					break;
				case 'j':
					first='j';
					break;
				case 'k':
					first='k';
					break;
				case '2':
					first='2';
					break;
				case 'l':
					first='l';
					break;
				case 'm':
					first='m';
					break;
				case 'n':
					first='n';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case 'i':
			switch(second){
				case '1':
					first='i';
					break;
				case 'i':
					first='2';
					break;
				case 'j':
					first='k';
					break;
				case 'k':
					first='m';
					break;
				case '2':
					first='l';
					break;
				case 'l':
					first='1';
					break;
				case 'm':
					first='n';
					break;
				case 'n':
					first='j';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case 'j':
			switch(second){
				case '1':
					first='j';
					break;
				case 'i':
					first='n';
					break;
				case 'j':
					first='2';
					break;
				case 'k':
					first='i';
					break;
				case '2':
					first='m';
					break;
				case 'l':
					first='k';
					break;
				case 'm':
					first='1';
					break;
				case 'n':
					first='l';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case 'k':
			switch(second){
				case '1':
					first='k';
					break;
				case 'i':
					first='j';
					break;
				case 'j':
					first='l';
					break;
				case 'k':
					first='2';
					break;
				case '2':
					first='n';
					break;
				case 'l':
					first='m';
					break;
				case 'm':
					first='i';
					break;
				case 'n':
					first='1';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case '2':
			switch(second){
				case '1':
					first='2';
					break;
				case 'i':
					first='l';
					break;
				case 'j':
					first='m';
					break;
				case 'k':
					first='n';
					break;
				case '2':
					first='1';
					break;
				case 'l':
					first='i';
					break;
				case 'm':
					first='j';
					break;
				case 'n':
					first='k';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case 'l':
			switch(second){
				case '1':
					first='l';
					break;
				case 'i':
					first='1';
					break;
				case 'j':
					first='n';
					break;
				case 'k':
					first='j';
					break;
				case '2':
					first='i';
					break;
				case 'l':
					first='2';
					break;
				case 'm':
					first='k';
					break;
				case 'n':
					first='m';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case 'm':
			switch(second){
				case '1':
					first='m';
					break;
				case 'i':
					first='k';
					break;
				case 'j':
					first='1';
					break;
				case 'k':
					first='l';
					break;
				case '2':
					first='j';
					break;
				case 'l':
					first='n';
					break;
				case 'm':
					first='2';
					break;
				case 'n':
					first='i';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		case 'n':
			switch(second){
				case '1':
					first='n';
					break;
				case 'i':
					first='m';
					break;
				case 'j':
					first='i';
					break;
				case 'k':
					first='1';
					break;
				case '2':
					first='k';
					break;
				case 'l':
					first='j';
					break;
				case 'm':
					first='l';
					break;
				case 'n':
					first='2';
					break;
				default:
					cout<<"ERROR : unreadable"<<endl;
			}
			break;
		default:
			cout<<"ERROR : unreadable 1"<<endl;
	}
}

bool findijk(string & eq){
	int pos=0;
	char loc='1';
	while((pos<eq.size()) && (loc != 'i')){
		prod(loc,eq[pos]);
		pos++;
	}
	if(loc!='i')
		return false;
	loc='1';
	while((pos<eq.size()) && (loc != 'j')){
		prod(loc,eq[pos]);
		pos++;
	}
	if(loc!='j')
		return false;
	loc='1';
	while(pos<eq.size()){
		prod(loc,eq[pos]);
		pos++;
	}
	if(loc!='k')
		return false;
	return true;
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("C-large.in");
	ofstream outputfile("myoutput.txt");
	int T;
	long int L;
	long long int X;
	string s, equi;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>L>>X>>s;
		if(X>7)
			X=(6+((X+2)%4));
		equi="";
		for(long long int i=0;i<X;i++)
			equi=equi+s;
		//solve & write
		outputfile<<"Case #"<<(t+1)<<": "<<((findijk(equi))?"YES":"NO")<<endl;
	}
	file.close();
	outputfile.close();
}

