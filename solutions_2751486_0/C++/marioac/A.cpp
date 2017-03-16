//#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

ifstream cin("A-small-attempt0.in");
ofstream cout("A-small.out");
//
//
int tag[1000000];
int mnd[1000000];
bool isvowel (char c) {
	return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}
int main() {
int T;

cin >> T;
for (int tt=1; tt<=T; tt++) {

long long znum=0; int curnvowels = 0; long long curznum=0;
for (int i=0; i<1000000; i++) { tag[i] = 0; mnd[i] = -1; }
string s; cin >> s; int L; cin >> L;
for (int i=0; i<L; i++) if (isvowel(s[i])) curnvowels++;
if (curnvowels == 0) { tag[L-1] = 1; }

for (int j=L; j<s.size(); j++) {
	//add j remove 
	if (isvowel(s[j-L])) {curnvowels--; }
	if (isvowel(s[j])) curnvowels++;
	if (curnvowels==0) tag[j] = 1;
}
int lastind = -1;
for (int j=s.size()-1; j>=0; j--) {
	if (tag[j] == 1) { lastind = j; }
	mnd[j] = lastind;
}

for (int i=0; i<s.size(); i++) {
	if (i+L>s.size()) break;
	int zz = mnd[i+L-1];
	if (zz!=-1) znum += (int)(s.size())-zz;
}

cout << "Case #"<<tt<<": "<<znum<< endl;

}

return 0;
}

