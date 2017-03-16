#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool issquare[10000];
bool ispalin[10000];
int ps[10000];

int main(void) {
int T;
cin >> T;
for(int i=0; i<10000; i++) {
	ostringstream os;
	os << i;
	string s = os.str();
	bool palin=true;
	for(int i=0; i<s.size(); i++) if(s[i]!=s[s.size()-i-1]) palin=false;
	if(palin) ispalin[i]=1;
}
for(int i=0; i*i<10000; i++) if(ispalin[i]) issquare[i*i]=1;
for(int i=1; i<10000; i++) ps[i]=ps[i-1]+(ispalin[i]&&issquare[i]);
for(int ts=1;ts<=T;ts++) {
	int A,B;
	cin >> A >> B;
	//for(int i=A; i<=B; i++) if(issquare[i]&&ispalin[i]) cout << i << endl;
	cout << "Case #" << ts << ": " << ps[B]-ps[A-1] << endl;
}
}
