//#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

ifstream cin("A-small-attempt0.in");
ofstream cout("A-small.out");
map<char,char> zmp;
int main() {
int T;

zmp['z'] = 'q'; zmp['q'] = 'z';
string ls = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string ls2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string ls3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
string dec = "our language is impossible to understand";
string dec2 = "there are twenty six factorial possibilities";
string dec3 = "so it is okay if you want to just give up";

for (int i=0; i<ls.length(); i++) {
	if (zmp.find(ls[i]) == zmp.end()) {
		zmp[ls[i]] = dec[i];
	}
}

for (int i=0; i<ls2.length(); i++) {
        if (zmp.find(ls2[i]) == zmp.end()) {
                zmp[ls2[i]] = dec2[i];
        }
}
for (int i=0; i<ls3.length(); i++) {
        if (zmp.find(ls3[i]) == zmp.end()) {
                zmp[ls3[i]] = dec3[i];
        } 
}
cin >> T;
string tll; getline(cin,tll);
for (int tt=1; tt<=T; tt++) {
string inp;
getline(cin,inp);
cout << "Case #"<<tt<<": ";
for (int i=0; i<inp.length(); i++) {
	if (inp[i] == ' ') cout << ' ';
	else cout << zmp[inp[i]];
}
cout <<endl;
}
return 0;
}

