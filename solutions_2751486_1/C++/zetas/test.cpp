#include<iostream>
#include<fstream>
#include <algorithm>
#include<vector>
#include<string>
using namespace std;
ifstream fin("A-large.in");
ofstream fout("A-large.out");

int T=1;

bool iscon(char c)
{
	if(c == 'a') return 0;
	if(c == 'e') return 0;
	if(c == 'i') return 0;
	if(c == 'o') return 0;
	if(c == 'u') return 0;
	return 1;	
}

int main()
{
    fin >> T;
	for(int i = 1; i <= T; i++){
		string str;
		fin >> str;
		long long L = str.length();
		long long n = 1;
		fin >> n;
		long long marker = 0;
		long long counter = 0;
		long long con = 0;
		char * cstr = new char[L+1];
		strcpy(cstr, str.c_str());
		for(long long j = 0; j < L; j++){
			if( iscon(*(cstr+j)) ){
				con++;
				if(con > n-1){
					counter += (L-j)*(j - marker + 2 - n);
					marker = j - n + 2;
				}
			}
			else { con = 0;}
			
		}
		fout << "Case #" << i << ": " << counter;
		if(i < T) fout << endl;
	}
	return 1;
}
