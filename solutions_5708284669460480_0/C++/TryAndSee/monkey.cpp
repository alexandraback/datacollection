#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int minimum(int l, int s, string target){
	if(s<l)
		cout<<"ERROR : s<l"<<endl;
	int matchat=0, checkmatch;
	bool matches=false;
	while(!matches){
		if(matchat>=l)
			cout<<"ERROR : matchat>l !"<<endl;
		matchat++;
		matches=true;
		checkmatch=0;
		while(matches && (checkmatch<l-matchat)){
			matches=(target[checkmatch]==target[checkmatch+matchat]);
			checkmatch++;
		}
	}
	return (1+((s-l)/matchat));
}

long double expect(int k, int l, int s, string keyboard, string target){
	long double proba[26], prob=1;
	int mychar;
	for(int i=0;i<26;i++)
		proba[i]=0;
	for(int i=0;i<k;i++){
		mychar=(keyboard[i]-'A');
		if(mychar<0 || mychar>25)
			cout<<"ERROR : wrong value for mychar";
		proba[mychar]=proba[mychar]+1;
	}
	for(int i=0;i<26;i++)
		proba[i]=(proba[i]/((long double)(k)));
	for(int i=0;i<l;i++){
		mychar=(target[i]-'A');
		if(mychar<0 || mychar>25)
			cout<<"ERROR : wrong value for mychar";
		prob=prob*proba[mychar];
	}
	return (prob*((long double)(1+s-l)));
}

long double remain(int k, int l, int s, string keyboard, string target){
	//check if possible
	if(s<l)
		return 0;
	bool require[26], required=false;
	int mychar;
	for(int i=0;i<26;i++)
		require[i]=false;
	for(int i=0;i<l;i++){
		mychar=(target[i]-'A');
		if(mychar<0 || mychar>25)
			cout<<"ERROR : wrong value for mychar";
		require[mychar]=true;
	}
	for(int i=0;i<k;i++){
		mychar=(keyboard[i]-'A');
		if(mychar<0 || mychar>25)
			cout<<"ERROR : wrong value for mychar";
		require[mychar]=false;
	}
	for(int i=0;i<26;i++){
		required=required || require[i];
	}
	if(required)
		return 0;
	//output remain
	return ((long double)minimum(l, s, target) - expect(k, l, s, keyboard, target));
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("B-small-attempt1.in");
	ofstream outputfile("myoutput.txt");
	int T, K, L, S;
	string keyboard, target;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>K>>L>>S;
		file>>keyboard;
		file>>target;
		if(keyboard.length() != K)
			cout<<"ERROR : length of keyboard"<<endl;
		if(target.length() != L)
			cout<<"ERROR : length of keyboard"<<endl;
		//solve & write
		outputfile<<"Case #"<<(t+1)<<": "<<remain(K,L,S,keyboard,target)<<endl;
	}
	file.close();
	outputfile.close();
}

