#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
using namespace std;



int main(){
	map<char,char> mapping;
	mapping['y'] = 'a'; mapping['e'] = 'o'; mapping['q'] = 'z'; mapping['z'] = 'q';mapping[' '] = ' ';
	string text1 = 
		"ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string mappedText = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	for(int i = 0; i<text1.size(); i++)
		mapping[text1[i]] = mappedText[i];

	ifstream in("A.txt");
	ofstream out("result.txt");
	int T; char c;
	in >> T >> c;

	int cant = 0;
	for(int i = 0; i<T; i++){
		string res="", input="";
		getline(in,input);
		if(i==0) input = c + input;
		for(int i = 0; i<input.size(); i++)
			res += mapping[input[i]];

		out << "Case #" << i+1 << ": " << res << endl;
		cout << "Case #" << i+1 << ": " << res << endl;
	}

	return 0;
}