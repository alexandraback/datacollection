#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

//int check(){}
int eval(unsigned char *S, int len, int target){
	if(len==1){
		return (1-(S[0]==target));
	}
	if(S[len-1]==target) return eval(S,len-1,target);
	else return 1+eval(S,len-1,1-target);
}

int main(int argc, char* argv[]){
	int T,nocase;
	int y;

	int i,len;
	string str;
	unsigned char S[100];

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	getline(cin,str);
	for (nocase = 1; nocase <= T; ++nocase) {
		getline(cin,str);
		len = (int) (str.length());
		for(i=0;i<len;i++) {
			if(str[i]=='-') S[i] = 0;
			else S[i] = 1;
		}

		y = eval(S,len,1);

		cout << "Case #" << nocase << ": " << y<< endl;
	}

	return 0;
}