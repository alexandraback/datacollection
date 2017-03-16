//#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

ifstream cin("C-small-attempt0.in");
ofstream cout("C-small.out");


bool ispalindrome(long long s) {
	string l;
	while (s!=0) {
		l=(char)((s%10)+48) + l;
		s=s/10;
	}
	for (int i=0; i<l.size(); i++) {
		if (l[i]!=l[l.size()-1-i]) return false;
	}
	return true;
}



int main() {
vector<long long> zworks;
for (long long zz=1; zz<=10000000; zz++) {
	if (ispalindrome(zz)) {
		long long zz2 = zz*zz;
		if (ispalindrome(zz2)) zworks.push_back(zz2);
	}
}
int T;
cin >> T;
for (int tt=1; tt<=T; tt++) {
cout << "Case #"<<tt<<": ";
int cnt=0; long long A,B; cin >> A >> B;
for (int i=0; i<zworks.size(); i++) {
	if (zworks[i]>=A && zworks[i] <=B) cnt++;
}
cout << cnt << endl;
}
return 0;
}
