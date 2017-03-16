#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ifstream fi("1.in");
ofstream fo("1.out");

int nr,rs,tt,t,n,i,j,k,a[1000],ok;
string s;

int main(){
	
	fi >> t;
	for (tt=1; tt<=t; tt++){
		fi >> s >> n;
		rs=0;
		for (i=n; i<=(int)s.size(); i++){
			for (j=0; j<=(int)s.size()-i; j++){
				nr=0,ok=0;
				for (k=j; k<=j+i-1; k++){
					if (s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u') nr=0; else nr++;
					if (nr>=n) ok=1;
				}
				if (ok) rs++;
			}
			
		}
			
		
		fo << "Case #" << tt << ": " << rs << endl;
	}
	
	return 0;
}
