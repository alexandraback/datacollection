#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;
		
bool valid(string s, int n, int a, int b) {
	int c=0;
	int max=0;
	for(int i=a;i<=b;i++) {
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') c++;
		else c=0;
		if(c>max) max = c;
	}
	if(max>=n) return true;
	else return false;
}
		
int main() {
	int T;
	cin >> T;
	int C=1;
	while(T-- > 0) {
		
		string str;
		int n;
		cin >> str;
		cin >> n;
		
		int resp=0;
		
		int s = str.size();
		int mat[s][s];
		for(int i=0;i<s;i++) {
			for(int j=i;j<s;j++) {
				if(j-i < n-1) mat[i][j] = 0;
				else {

					if(valid(str,n,i,j)) mat[i][j] = 1;
					else mat[i][j] = 0;
				
				}
			}
		}
		
		for(int i=0;i<s;i++)
			for(int j=i;j<s;j++)
				resp+= mat[i][j];
		
		
		
		cout << "Case #"<<C++<<": "<<resp<<endl;
	}

	return 0;
}

