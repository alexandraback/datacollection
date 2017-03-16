#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <set>

using namespace std;

int T, n;
string str;
set<char> vo;

int count(string s){

	bool f = false;
	int c = 0, res = 0;
	
	for(int i=0; i<s.size(); ++i){
		
		if(!f&&!vo.count(s[i])){
			c=1;
			f=true;
		}
		else if(f&&vo.count(s[i])){
			c=0;
			f=false;
		}
		else if(f&&!vo.count(s[i])){
			c++;
		}
		
		res = max(res, c);
	}
	
	return res;
}	
		
int main(){
	
	int cnt=1;
	
	cin>>T;
	vo.insert('a');
	vo.insert('e');
	vo.insert('i');
	vo.insert('o');
	vo.insert('u');
	
	while(cnt<=T){
	
		cin>>str>>n;
		
		int out = 0;
		string sub;
		
		for(int i=0; i<str.size(); ++i){
			
			for(int j=i; j<str.size(); ++j){
				
				sub = str.substr(i, j-i+1);
				//cout << sub << ":" << count(sub) << endl;
				
				if(count(sub) >= n)
					out++;
			}
		}
		
	
		cout << "Case #" << cnt++ << ": " << out << endl;
	
	}
	
	return 0;
}