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

bool check(string s,int n){
	//cout<<s<<endl;
	for(int i=0;i<n;i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
			return false;
		}
	}
	return true;
}


int main(){

	ifstream in;
	//in.open("test.txt");
	in.open("A-small.in");
	//in.open("A-large.in");
	
	ofstream out;
	out.open("out.txt");
	
	int T;
	in>>T;
	

	for(int u=0;u<T;u++){
				
		string s;
		int n;
		in>>s>>n;
		
		long long ret = 0;
		
		int prev = -1;
		
		int size = s.size();
		for(int i=0;i<size-n + 1;i++){
			if(check(s.substr(i,n),n)){
				ret += (i - prev)*(size-i-n+1);
				prev = i;
			}
		}
		
		out<<"Case #"<<(u+1)<<": "<<ret<<endl;
		cout<<"Case #"<<(u+1)<<": "<<ret<<endl;
	
    }
	in.close();
	out.close();
	
    return 0;
}