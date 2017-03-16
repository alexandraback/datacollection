/*
 * main.cpp
 *
 *  Created on: Apr 13, 2012
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

	for (int i = 1; i!= T+1; ++i) {   //for each case
		///////////////////
		int N, S, p;
		input>>N>>S>>p;
		vector<int> v;
		for (int i=0; i!=N; i++){
			int t;
			input>>t;
			v.push_back(t);
		}
		getline(input,line); //necessary.

		int result = 0;
		for (int i=0; i!=N; i++){
			int value = v[i];
			int x = v[i]/3;
			int y = v[i]%3;
			if (y==0){
				if (x>=p)
					result++;
				else if (x+1>=p && x-1>=0 && S!=0){
					S--;
					result++;
				}

			}
			else if (y==1){
				if (x+1>=p)
					result++;
			}
			else {
				if (x+1>=p)
					result++;
				else if (x+2>=p && S!=0){
					S--;
					result++;
				}
			}
		}


		cout<<"Case #"<<i<<": ";   //output each case
		//////////////////
        /*
		for (int i=0; i!=N; i++) {
			cout<<v[i]<<" ";
		}
		*/
		cout<<result;
		cout<<endl;
	}

	input.close();
	return 0;
}



