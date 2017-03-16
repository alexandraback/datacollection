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

void print(const vector<int> & v){
	for (int i=0; i!=v.size(); i++){
		cout<<v[i];
	}
}

bool LT(const vector<int> &a, const vector<int> &b){
	if (a.size()!=b.size())
		cout<<"LT wrong!"<<endl;
	int i = 0;
	while(a[i]==b[i] && i!=a.size()){
		i++;
	}
	if (i!=a.size() && a[i]>b[i])
		return true;
	else
		return false;
}



vector<int> transform(int a){
	vector<int> result;
		if (a<10) {
			result.push_back(a);
			return result;
		}
		else {
			int num_digits = 1+ (int)log10(a);
			int start = a;
			for (int i = 0; i!=num_digits; i++) {
				int digit = start/(int)pow(10, num_digits-i-1);
				result.push_back(digit);
				start = start%(int)pow(10, num_digits-i-1);
			}
		}
}

int main(int arg, char** argv){
	char* filename = argv[1];
	ifstream input(filename);

	int T; //Number of Cases.
	input>>T;
	string line;
	getline(input,line); //necessary.



	for (int i = 1; i!= T+1; ++i) {   //for each case
		///////////////////
		int A, B;
		input>>A>>B;
		getline(input,line); //necessary.
		vector<int> upLimit = transform(B);

		ll result = 0;
		for (int i=A; i!=B; i++) {
			vector<int> v = transform (i);
			set<vector<int> > s;
			vector<int> newV;
			for (int j=1; j!=v.size(); j++) {
				newV.clear();
				//newV.resize(v.size());
				rotate_copy(v.begin(),v.begin()+j,v.end(),back_inserter(newV));
				if (LT(newV, v) && (LT(upLimit, newV) || upLimit==newV) && s.find(newV)==s.end()) {
					result++;
					s.insert(newV);

				}
			}
		}

		cout<<"Case #"<<i<<": ";   //output each case
		//////////////////

		/*
		vector<int> v1 = transform (1);
		vector<int> v2 = transform (0);
		cout<<LT(v1,v2)<<endl;

		for (int i=0; i!=v.size(); i++){
			cout<<v[i];
		}
		*/
		cout<<result;

		cout<<endl;
	}

	input.close();
	return 0;
}


