#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef unsigned long long ul;

int main(){
	int N ; 
	cin>> N;

	for(int T = 1 ; T <= N ; T++) {
		int x,y;
		cin>> x >> y ;

		string ret;
		if(x > 0) 
			for(int i = 0 ;i < x ; i++) 
				ret += "WE";
		else if( x< 0)
			for(int i = 0 ;i < abs(x) ; i++) 
				ret += "EW";
		if(y>0)
			for(int i = 0 ;i < y ; i++) 
				ret += "SN";
		else if( y<0)
			for(int i = 0 ;i < abs(y) ; i++) 
				ret += "NS";
		cout<<"Case #"<<T<<": "<<ret<<endl;
	}
	return 0;
}