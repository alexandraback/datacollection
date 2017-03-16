// speak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream> 
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream cin(argv[1]);
	std::ofstream cout(argv[2]);

	char x[26];
	char y[26];

	string a= "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string b("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd") ;
	string c("de kr kd eoya kw aej tysr re ujdr lkgc jv");

	string a1("our language is impossible to understand");
	string b1("there are twenty six factorial possibilities" );
	string c1("so it is okay if you want to just give up");
	
	//cout<<b[0]<<endl;

	
	for(int i = 0 ; i < a.length() ; i++){
		if(a[i] != ' '){
			int k = a[i]-'a';
			//cout<<k<<endl;
			x[k] = a1[i];
		}
	}

	
	for(int i = 0 ; i < b.length() ; i++){
		if(b[i] != ' '){
			int k = b[i]-'a';
			//cout<<k<<endl;
			x[k] = b1[i];
		}
	}

	for(int i = 0 ; i < c.length() ; i++){
		if(c[i] != ' '){
			int k = c[i]-'a';
			//cout<<k<<endl;
			x[k] = c1[i];
		}
	}

	x['q' -'a'] = 'z';
	x['z' - 'a'] = 'q';

	/*
	for(int i = 0 ; i < 26 ; i++){
		cout<<(char)('a'+i)<<" ----> "<<x[i]<<endl;
	}
	*/
	string num;
	getline(cin, num);
	int n = atoi(num.c_str());
	
	string t[40];

	for(int i = 0 ; i < n ; i++){
		getline(cin, t[i]);
		cout<<"Case #"<<i+1<<": ";
		for(int j = 0 ; j < t[i].length() ; j++){
			if(t[i][j] == ' '){
				cout<<" ";
			} else {
				cout<<x[t[i][j] - 'a'];
			}

		}
		cout<<endl;
	}
	

	return 0;
}

