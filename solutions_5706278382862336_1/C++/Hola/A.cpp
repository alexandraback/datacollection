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

bool Judge(long long int q){
	
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

void String2Number(string str,long long int& p,long long int & q){
	
	p = q = 0;
	int i;
	long long int b = 10;
	for(i = 0; i < str.size(); i ++){
		if(str[i] == '/') break;
		p = p * b + (long long int)(str[i] - '0');
	}
	i ++;

	for(; i < str.size(); i ++){
		q = q * b + (long long int)(str[i] - '0');
	}
}

long long gcd(long long int p, long long int q){
	
	if(p % q == 0) return q;
	else return gcd(q, p%q);
}

int main(){
	
	int t;
	long long int p,q;
	long long int d;
	string str;

	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	fin >> t;
	for(int i = 1; i <= t; i ++){
		
		fin >> str;
		
		String2Number(str, p, q);
		
		d = gcd(p,q);
		p /= d;
		q /= d;

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
