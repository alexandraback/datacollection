#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;


int main(){

	ifstream in;
	in.open("Ar.in");
	//in.open("A-large.in");
	
	ofstream out;
	out.open("out.txt");
	
	int T;
	in>>T;
	//cout<<T;
	

	
	for(int u=0;u<T;u++){
		
		unsigned long long r;
		unsigned long long t;
		
		in>>r>>t;	
		
		double rd = r;
		double td = t;
		
		//cout<<rd<<endl;
		//cout<<td<<endl;
		
		//cout<<(2*rd-1)*(2*rd-1) +8*td<<endl;
		
		long double n = (-(2*rd-1) + sqrt((2*rd-1)*(2*rd-1) + 8 * td))/4.0;
		
		unsigned long long ans = floor(n);
		
		//cout<<ans<<endl;
		out<<"Case #"<<(u+1)<<": "<<ans<<endl;	
		
    }
	in.close();
	out.close();
	
    return 0;
}