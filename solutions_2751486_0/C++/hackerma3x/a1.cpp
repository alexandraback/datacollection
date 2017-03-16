#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <list>
using namespace std;


void Test(int T) {
	unsigned int L;
	string name;
	cin >> name >> L;
	int k=name.length();
	unsigned int y = 0;
	vector<int> pocetci;
	
	for(int i=0; i<k; i++) {
		if(name[i]!='a' && name[i]!='e' && name[i]!='i' && name[i]!='o' && name[i]!='u') {
			for(int j=0, m=0; j<L && i+j<k; j++) {
				if(name[i+j]!='a' && name[i+j]!='e' && name[i+j]!='i' && name[i+j]!='o' && name[i+j]!='u')
					m++;
				if(m==L) {
					pocetci.push_back(i);
					break;
				}
			}
		}
	}
	int NNN=0;
	for(int i=0; i<k; i++) {
		for(int j=k; j>i; j--) {
		 	for(vector<int>::iterator it=pocetci.begin(); it!=pocetci.end(); it++) {
				if(i<=*it && j>=*it+L) { NNN++; break; }
 			}
		}
	}
	
	cout << "Case #" << T << ": " << NNN << endl;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	unsigned int T;
	cin >> T;
	for(int i=1; i<=T; i++)
		Test(i);
	return 0;
}
