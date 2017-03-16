#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int x=1; x<=T; x++) {
    string C,J;
    cin >> C >> J;
    int n = C.length();
    cout << "Case #" << x << ": ";
    // test if equal
    bool solution = true;
    for (int i=0; i<n; i++)
      if (C[i] != '?' && J[i] != '?' && C[i] != J[i]) solution = false;
    if (solution) {
      for (int i=0; i<n; i++)
	if (C[i] =='?') C[i] = (J[i] != '?') ? J[i] : '0';
      cout << C << " " << C << endl;
    } else {
      // not equal
      long long c=0, j=1000000000000000000;
      for (int p=0; p<n; p++) { // p most significant digit that does not match
	// try C < J
	solution = true;
	long long a=0;
	for (int i=0; i<p; i++) {
	  a*=10;
	  if (C[i]=='?' && J[i] == '?') ; // fill ? = '0'
	  else if (C[i]=='?' && J[i] != '?') a+= J[i]-'0'; // fill from J
	  else if (C[i]!='?' && J[i] == '?') a+= C[i]-'0'; // fill from C
	  else if (C[i]!=J[i]) solution = false; // cannot make common prefix
	  else a += C[i] -'0';
	};
	a *= 10;
	long long b=a;
	if (C[p]=='9' || J[p]=='0') solution = false;
	else if (C[p]=='?' && J[p]=='?') b+=1; // C[p] = 0 , J[p] = 1
	else if (C[p]=='?') a += J[p]-'0'-1, b += J[p]-'0'; 
	else if (J[p]=='?') a += C[p]-'0', b += C[p]-'0'+1; 
	else if (C[p]>=J[p]) solution = false;
	else a += C[p]-'0', b += J[p] -'0';
	for (int i=p+1; i<n; i++)
	  a = 10*a + (C[i] != '?' ? C[i]-'0' : 9), b = 10*b + (J[i] != '?' ? J[i]-'0' : 0);
	
	if (solution && (abs(a-b)<abs(c-j) || (abs(a-b)==abs(c-j) && (a<c || (a==c && b<j))))) c=a, j=b;

	// try C > J
	solution = true;
	 a=0;
	for (int i=0; i<p; i++) {
	  a*=10;
	  if (J[i]=='?' && C[i] == '?') ; // fill ? = '0'
	  else if (J[i]=='?' && C[i] != '?') a+= C[i]-'0'; // fill from J
	  else if (J[i]!='?' && C[i] == '?') a+= J[i]-'0'; // fill from C
	  else if (J[i]!=C[i]) solution = false; // cannot make common prefix
	  else a += J[i] -'0';
	};
	a *= 10;
	 b=a;
	if (J[p]=='9' || C[p]=='0') solution = false;
	else if (J[p]=='?' && C[p]=='?') a+=1; // J[p] = 0 , C[p] = 1
	else if (J[p]=='?') b += C[p]-'0'-1, a += C[p]-'0'; 
	else if (C[p]=='?') b += J[p]-'0', a += J[p]-'0'+1; 
	else if (J[p]>=C[p]) solution = false;
	else b += J[p]-'0', a += C[p] -'0';
	for (int i=p+1; i<n; i++)
	  b = 10*b + (J[i] != '?' ? J[i]-'0' : 9), a = 10*a + (C[i] != '?' ? C[i]-'0' : 0);
	
	if (solution && (abs(a-b)<abs(c-j) || (abs(a-b)==abs(c-j) && (a<c || (a==c && b<j))))) c=a, j=b;

      };

      cout << setfill('0') << setw(n) << c << " " <<  setw(n) << j << endl;
    }
  };
  return 0;
};
