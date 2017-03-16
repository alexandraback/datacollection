#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool isGlas(char c){
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int main(){
	ifstream inp("A-small-attempt0.in");
	ofstream out("outputA.txt");
	int t; inp>>t;
	for(int mi=1; mi<=t; mi++){
		__int64 res=0;
		cout<<mi;
		string name; inp>>name;
		int n; inp>>n;
		int lname = name.length();
		if (lname>=n){
			int suflen = n;
			for(int i=(n-1);i<lname;i++){
				int j;
				for( j=0; j<n; j++)
					if (isGlas(name[i-j])) break;
				if (j<n) suflen++;
				else suflen=n;				
				if (suflen<=(i+1)) res+=(i+1-suflen+1);
			}
		}
		out<<"Case #"<<mi<<": "<<res<<endl;
	}
	return 0;
}