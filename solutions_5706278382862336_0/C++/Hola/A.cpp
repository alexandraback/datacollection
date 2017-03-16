/*************************************************************************
    > File Name: A.cpp
    > Author: csy
    > Mail: chshaoyi7@gmail.com 
    > Created Time: Sun 11 May 2014 04:54:25 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool Judge(int q){
	
	bool flag = true;

	while(q != 1){
		if(q % 2 != 0){
			flag = false;
			break;
		}
		q /= 2;
	}

	return flag;
}

void String2Number(string str, int& p,int & q){
	
	p = q = 0;
	int i;
	for(i = 0; i < str.size(); i ++){
		if(str[i] == '/') break;
		p = p * 10 + str[i] - '0';
	}
	i ++;

	for(; i < str.size(); i ++){
		q = q * 10 + str[i] - '0';
	}
}


int main(){
	
	int t;
	int p,q;
	string str;

	ifstream fin("ASmall.in");
	ofstream fout("ASmall.out");
	fin >> t;
	for(int i = 1; i <= t; i ++){
		
		fin >> str;
		
		String2Number(str, p, q);
		

		fout << "Case #" << i<<": ";
		if(!Judge(q)) fout << "impossible" << endl;
		else{
			int counter = 1;
			while(p * 2 < q){
				p *= 2;
				counter ++;
			}

			fout << counter << endl;
		}

	}

	return 0;
}
