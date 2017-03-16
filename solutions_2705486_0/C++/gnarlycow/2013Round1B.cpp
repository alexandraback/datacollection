//============================================================================
// Name        : 2013Round1B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<string> dict;
int f[155][5];
string email;
int emailSize, countChanges;

int canMatch(int changeAllowed, int pos, int index) {
	if(pos+dict[index].size()>emailSize) return -1;
	countChanges = 0;
	for(int i=0;i<dict[index].size();++i)
		if(email[pos+i]!=dict[index][i]) {
			if(changeAllowed>pos+i) return -1;
			++countChanges;
			changeAllowed = pos+i+5;
		}
	return changeAllowed;
}

int main() {
	freopen("output.txt","w",stdout);
	ifstream fdict("dict.txt");
	string word;
	while(fdict>>word) dict.push_back(word);
	int dictSize = dict.size();

	int ncases;
	cin>>ncases;
	for(int cid=1;cid<=ncases;++cid) {
		cin>>email;
		emailSize = email.size();
		memset(f,0,sizeof(f));
		for(int i=emailSize-1;i>-1;--i) {
			for(int k=0;k<5;++k) {
				f[i][k] = 5555;
				for(int j=0;j<dictSize;++j) {
					int changeAllowed = canMatch(i+k, i, j);
					if(changeAllowed>-1) {
						//cout<<i<<' '<<k<<' '<<j<<' '<<countChanges<<" "<<changeAllowed<<endl;
						f[i][k] = min(f[i][k], countChanges + f[i+dict[j].size()][max(changeAllowed-i-(int)dict[j].size(),0)]);
						//cout<<f[i][k]<<endl;
					}
				}
			}
		}
		printf("Case #%d: %d\n", cid, f[0][0]);
	}
	return 0;
}
