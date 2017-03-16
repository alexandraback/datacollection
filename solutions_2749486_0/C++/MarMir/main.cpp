#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
string s;
vector<vector<int> > grid2D (5, vector<int>(5));
vector<int> grid1D(5) ; 
int i;
int j;
int k;
int x;
int y;
string ud="";
string rl="";
string answer="";
int main(int argc, char *argv[]) {
	ifstream in("B-small-attempt2.in");
	in>>T;
	ofstream out("B-small-attempt2.out");
	for(i=1;i<=T;i++){
			ud="";
			rl="";
			answer="";
			in>>x;
			in>>y;
			if(y>0){
				ud="SN";
			}
			else if(y<0){
				ud="NS";
			}
		
			for(j=1;j<=abs(y);j++){
				answer=answer+ud;
			}
		
			if(x>0){
				rl="WE";
			}
			else if(x<0){
				rl="EW";
			}
		
			for(j=1;j<=abs(x);j++){
				answer=answer+rl;
			}
			out << "Case #" << i << ": " <<answer<<endl;
	}
	return 0;
}
