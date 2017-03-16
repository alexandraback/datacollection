//#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

ifstream cin("C-large.in");
ofstream cout("C-large.out");

int getval(vector<int> & zvec) {
	int s = 0;
	for (int i=0; i<zvec.size(); i++) {
		s = s*10 + zvec[i];
	}
	return s;
}
int LUT[2000001];

int main() {

int T;
cin >> T;

for (int tt=1; tt<=T; tt++) {
long long ret=0;
int A,B;
cin >> A >> B;
for (int i=A; i<B+1; i++) LUT[i] = 0;

for (int i=A; i<=B; i++) {
if (LUT[i] != 0) continue; 
vector<int> digits;
LUT[i] = 1;
int s = i;
while (s!=0) {
digits.push_back(s%10); s=s/10;
}
reverse(digits.begin(), digits.end());

int lcount = 1;

vector<int> temps;
int ll = digits.size()-1;
while (ll > 0) {
	temps.clear();
	for (int k=ll; k<ll+digits.size(); k++) {
		temps.push_back(digits[k%digits.size()]);
	}
	int m = getval(temps);
	if (m >= A && m <=B) { if (LUT[m] == 0) { lcount++; LUT[m] = 1; } }
	ll--;
}
ret += (lcount*(lcount-1));

}



cout << "Case #"<<tt<<": " << ret/2 << endl;
}
return 0;
}
