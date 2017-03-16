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
string ss;
vector<vector<int> > grid2D (5, vector<int>(5));
vector<int> grid1D(5); 
vector<int> maska(101); 
int i;
int j;
int k;
int x;
int y;
int n;
int answer=0;
char one='1';
int first=1;
string n_ones="";

int main(int argc, char *argv[]) {
	ifstream in("A-small-attempt0.in");
	in>>T;
	ofstream out("A-small-attempt0.out");
	for(i=1;i<=T;i++){
			answer=0;
			n_ones="";
			in>>ss;
			in>>n;
			first=1;
			s='s'+ss;
			for(j=1;j<s.size();j++){
				if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
					s[j]='0';
				}
				else{
					s[j]='1';
				}
			}
			for (k=1;k<=n;k++){
					n_ones=n_ones+one;
			}

			for(j=1;j<s.size()-n+1;j++){
				if(s.substr(j,n)==n_ones){
					if(answer==0){
						answer=(s.size()-1-(j+n-1)+1)*(j);
						first=j+1;
					}
					else{
						answer=answer+(s.size()-1-(j+n-1)+1)*(j-first+1);
						first=j+1;
					}
				}
			}
			
			out << "Case #" << i << ": " <<answer<<endl;
			
	}
	return 0;
}
