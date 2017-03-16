#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;

/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){



	out<<"Case #"<<Case+1<<":";
	}
	return 0;
}
*/
//           'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'
int lib[26]={'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	char s[110]={0};
	in.open("A-small-attempt0.in");
	out.open("out.txt");
	in>>CaseNum;
	in.get();
	for(int Case=0;Case<CaseNum;Case++){
		in.getline(s,300);
			for(int i=0;s[i]!=0;i++){
			if(s[i]==' ')continue;
			for(int j=0;j<26;j++)
				if(lib[j]==s[i]){
					s[i]='a'+j;
					break;
				}

		}


	out<<"Case #"<<Case+1<<": "<<s<<endl;
	}
	out.clear();
	out.close();
	return 0;
}