#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	ifstream input;
	input.open("A-large.in");
	freopen("out","w",stdout);
	int T, L;
	string S;

	input>>T;

	for(int t=0; t<T; t++){
		printf("Case #%d: ",t+1);
		input>>S;
		//cout<<S;
		L = S.length();
		for(int l=1; l<L; l++){
			if(S[l]>=S[0]){
				S.insert(S.begin(),S[l]);
				S.erase(S.begin()+l+1);
			}
		}
		cout<<S<<endl;
	}
}