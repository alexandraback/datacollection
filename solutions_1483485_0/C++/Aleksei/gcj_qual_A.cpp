#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <string.h>
using namespace std;

//abcdefghijklmnopqrstuvwxyz
//yhesocvxduiglbkrztnwjpfmaq
char code[]="yhesocvxduiglbkrztnwjpfmaq";
char s[255];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	cin.getline(s,255);
	for(int testnum=0; testnum<ntests; testnum++){
		cin.getline(s,255);
		int i=0;
		while(s[i]!='\0'){
			if(s[i]!=' ') s[i]=code[s[i]-'a'];
			i++;
		}
		cout<<"Case #"<<testnum+1<<": "<<s<<endl;
	}
	return 0;
}
