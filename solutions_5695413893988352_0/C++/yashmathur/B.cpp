#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

string s1,s2;
int t;
int state;
int main() {
	freopen("input.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>t;
	for(int k = 0 ; k < t ; k++) {
		state = 0;
		cin >> s1;
		cin >> s2;
		
		for(int i = 0 ; i < s1.length() ; i++) {
			if(state == 0) {
				if(s1[i] == '?' && s2[i] == '?') {
					s1[i] = '0';
					s2[i] = '0';
					continue;
				}
				else if(s1[i] == '?') {
					s1[i] = s2[i];
					continue;
				}
				else if(s2[i] == '?') {
					s2[i] = s1[i];
					continue;
				}
				else {
					if(s1[i] > s2[i]) {
						state = 1;
					}
					else if(s2[i] > s1[i]) {
						state = -1;
					}
					continue;
				}
			}
			else if(state < 0) { //s1 needs to be larger
				if(s1[i] == '?' && s2[i] == '?') {
					s1[i] = '9';
					s2[i] = '0';
					continue;
				}
				else if(s1[i] == '?') {
					s1[i] = '9';
					continue;
				}
				else if(s2[i] == '?') {
					s2[i] = '0';
					continue;
				}
				else {
					continue;
				}
			}
			else if(state > 0) { //s2 needs to be larger
				if(s1[i] == '?' && s2[i] == '?') {
					s1[i] = '0';
					s2[i] = '9';
					continue;
				}
				else if(s1[i] == '?') {
					s1[i] = '0';
					continue;
				}
				else if(s2[i] == '?') {
					s2[i] = '9';
					continue;
				}
				else {
					continue;
				}
			}
		}
		cout << "Case #" << k+1 << ": " << s1 << " " << s2 << endl;
	}
	
	
	
	return 0;
}
