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
#include <map>
using namespace std;



int main(){


int t;
cin>>t;
int c =1;

while(t--){

int n;
cin>>n;
//vector <vector <int> > vec(2*n -1, vector <int> (n));

vector <int> vec (2501);


for(int i=0;i < 2*n -1;i++){
	for(int j=0;j<n;j++){
		int a;
		cin>>a;
		if (vec[a] == 1) vec[a] =0;
		else vec[a] =1;
	}
}

cout<<"Case #"<<c<<":";
for(int i=1;i<vec.size();i++){
if(vec[i] == 1) cout<<" "<<i;

}
cout<<endl;

c++;

}


return 0;
}

 
