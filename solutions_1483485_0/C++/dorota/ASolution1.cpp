#include<iostream>
#include<cstring>
#include<sstream>

using namespace std;

int magicArray[30] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 
't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };

char sen1[1000];

int main() {
	cin.getline(sen1, 1000);
	int t;
	istringstream ins;
	ins.str(sen1);
	ins >> t;
	for(int tt=1; tt<=t; tt++) {
		cin.getline(sen1, 1000);
		for(int i=0; i<strlen(sen1); i++) {
			if(sen1[i] >= 'a' && sen1[i] <= 'z') {
				sen1[i] -= 'a';
				sen1[i] = magicArray[sen1[i]];
			}
		}
		cout << "Case #" << tt << ": " << sen1 << endl;
	}
}
