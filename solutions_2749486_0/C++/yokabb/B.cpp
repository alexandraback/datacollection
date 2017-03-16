
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(){
	int x,y;
	cin>>x >> y;
	
	string str;
	if(x>0){
		for(int i=0;i<x;i++){
			str += "WE";
		}
	}else if(x<0){
		x = -x;
		for(int i=0;i<x;i++){
			str += "EW";
		}
	}
	if(y>0){
		for(int i=0;i<y;i++){
			str += "SN";
		}
	}else if(y<0){
		y = -y;
		for(int i=0;i<y;i++){
			str += "NS";
		}
	}
	
	cout<< str<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	
	int n;
	cin>> n;
	for(int i=0;i<n;i++){
		cout<<"Case #"<< i+1<< ": ";
		solve();
	}
	
	return 0;
}

 