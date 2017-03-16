#include <bits/stdc++.h>
using namespace std;

#include <fstream>

int main(){

	ifstream in("D-large.in");
	ofstream out("upload.out");

	int t, x, r, c, prod;
	in>>t;
	for(int big = 1; big <= t; big++){

		bool ok = false;

		in>>x>>r>>c;

		prod = r*c;

		if(x == 1)	ok = true;
		else if(x == 2){
			if((prod%x) == 0)	ok = true;
		}
		else if(x == 3){
			if((prod%x) == 0 && min(r, c) >= 2)	ok = true;
		}
		else if(x == 4){
			if((prod%x) == 0 && min(r, c) >= 3 && max(r, c) >= 4)	ok = true;	
		}
		else if(x == 5){
			if((prod%x) == 0 && min(r, c) >= 4 && max(r, c) >= 5)	ok = true;
		}
		else if(x == 6){
			if((prod%x) == 0 && min(r, c) >= 4 && max(r, c) >= 6)	ok = true;
		}

		out<<"Case #"<<big<<": ";
		if(ok)	out<<"GABRIEL"<<endl;
		else out<<"RICHARD"<<endl;

	}
	
	return 0;
}	