/*
 * main.cpp
 *
 *  Created on: Apr 14, 2012
 *      Author: lulu
 */
#include <iostream>
#include <fstream>

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

#include <algorithm>
#include <iterator>

#include <math.h>
#include <iomanip>

long long gcd(long long m, long long n){
	while (n!=0){
		long long rem = m%n;
		m=n;
		n=rem;
	}
	return m;
}

long long lcm(long long m, long long n){
	return m*n/gcd(m,n);
}

using namespace std;

typedef long long ll;

int main(int arg, char** argv){
	char* filename = argv[1];
	ifstream input(filename);

	int T; //Number of Cases.
	input>>T;
	string line;
	getline(input,line); //necessary.

	map <char, char> one2one;
		one2one['a']='y';
		one2one['b']='h';
		one2one['c']='e';
		one2one['d']='s';
		one2one['e']='o';
		one2one['f']='c';
		one2one['g']='v';
		one2one['h']='x';
		one2one['i']='d';
		one2one['j']='u';
		one2one['k']='i';
		one2one['l']='g';
		one2one['m']='l';

		one2one['n']='b';
		one2one['o']='k';
		one2one['p']='r';

		one2one['q']='z';
		one2one['r']='t';
		one2one['s']='n';
		one2one['t']='w';
		one2one['u']='j';
		one2one['v']='p';
		one2one['w']='f';
		one2one['x']='m';
		one2one['y']='a';
		one2one['z']='q';

	for (int i = 1; i!= T+1; ++i) {   //for each case
		string line;
		getline(input,line);
		string result;
		for (int i=0; i!=line.size(); i++) {
			if (line[i]==' ')
				result+=' ';
			else if (isalpha(line[i]))
				result+=one2one[line[i]];
		}



		cout<<"Case #"<<i<<": ";   //output each case
		//////////////////
		cout<<result;
		cout<<endl;
	}

	input.close();
	return 0;
}




