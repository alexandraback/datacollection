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

bool mo(char c) {
	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
		default:
			return false;
	}
}
int d[1000 * 1000 + 1];
int main(){
	int N ; 
	cin>> N;

	for(int T = 1 ; T <= N ; T++) {
		memset(d,0,sizeof(d));
		string s;
		int n;
		cin>> s >> n ; 

		for(int i = 0 ; i < s.size() ; i++) {
			if(mo(s[i]) == false) {
				if(i == 0) d[i] = 1;
				else d[i] = d[i-1] +1;
			}
			else
				d[i] = 0;
		}

		long long ret = 0;
		for(int i = 0 ; i < s.size() ; i++){
			
			int temp = -1 ;
			for(int j = i+n-1 ; j < s.size() ; j++) 
				if(d[j] >= n) {
					temp = j;
					break;
				}
			if(temp != -1) {
				ret += (s.size() - temp) ;
			}
		}

		cout<<"Case #"<<T<<": "<<ret<<endl;
	}
	return 0;
}