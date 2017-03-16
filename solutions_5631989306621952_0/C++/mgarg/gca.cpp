#include <iostream> 
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <math.h>
#include <limits.h>
#include <inttypes.h>
using namespace std;



int main(){


int t;
cin>>t;
int c =1;

while(t--){

string s;
cin>>s;

string res ="";
res+= s[0];

for(int i=1;i<s.length();i++){
	if(s[i] >= res[0]) res= s[i] + res;
	else res = res + s[i];
}

cout<<"Case #"<<c<<": "<<res<<endl;

c++;

}


return 0;
}

 
