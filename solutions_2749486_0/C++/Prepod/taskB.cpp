#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool islinenumb(int x,int y,int n){
	int m = abs(x)+abs(y);
	if (n*(n+1)/2<m) return false;
	if (m%2==0 && (n%4==1 || n%4==2)) return false;
	if (m%2==1 && (n%4==0 || n%4==3)) return false;
	return true;
}

int main(){
	ifstream inp("B-small-attempt1.in");
	ofstream out("outputB.txt");
	int t; inp>>t;
	for(int mi=1; mi<=t; mi++){
		string res="";
		int x,y; inp>>x>>y;
		int r;
		for(r=0;;r++)
			if (islinenumb(x,y,r)) break;	
		while(r>0){
			if (islinenumb(x+r,y,r-1)) {res+='W';x+=r;}
			else if (islinenumb(x-r,y,r-1)) {res+='E';x-=r;}
			else if (islinenumb(x,y+r,r-1)) {res+='S';y+=r;}
			else if (islinenumb(x,y-r,r-1)) {res+='N';y-=r;}
			r--;
		}
		std::reverse(res.begin(), res.end());

		out<<"Case #"<<mi<<": "<<res<<endl;
	}
	return 0;
}