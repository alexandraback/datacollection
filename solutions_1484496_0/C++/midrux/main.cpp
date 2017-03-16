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
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

int main(){
	ifstream in("A.in");
	ofstream out("result.txt");
	int T; 
	int N;
	in >> T;
	
	for(int test = 0; test<T; test++){
		in >> N;
		out << "Case #" << test+1 << ":" << endl;
		cout << "Case #" << test+1 << ":" << endl;
		vector<int> S(N);
		for(int i = 0; i<N; i++)
			in >> S[i];

		map<int, int> setsum;
		for(int i = 1; i<(1<<N); i++){
			int sum = 0;
			for(int bit = 0; bit<N; bit++)
				if(i & (1<<bit)) sum += S[bit];

			
			if(setsum.count(sum)>0){
				for(int bit = 0; bit<N; bit++)
					if(i & (1<<bit)) {
						out << S[bit] << " ";
						cout << S[bit] << " ";
					}
				cout << endl;
				out << endl;
				int temp = setsum[sum];
				for(int bit = 0; bit<N; bit++)
					if(temp & (1<<bit)) {
						out << S[bit] << " ";
						cout << S[bit] << " ";
					}
				break;
			}
			setsum[sum] = i;
		}
		out << endl;
		cout << endl;	
	}

	return 0;
}