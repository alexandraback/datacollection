#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)


string tr="yhesocvxduiglbkrztnwjpfmaq";
int n;
char line[200];
string temp;

int main()
{
	cout << setprecision(9) ;
	cin.getline(line, 199);
	n = atoi(line);
	for(int i=1;i<=n;i++) {
		cin.getline(line, 199);
		string s = line;
		stringstream ss(s);
		vector<string> ret;
		while(ss >> s) {
			for(int j=0;j<s.size();j++) {
				s[j] = tr[s[j]-'a'];
			}	
			ret.push_back(s);
		}
		cout << "Case #" << i << ": ";
		for(int j=0;j<ret.size();j++) {
			cout << ret[j];
			if(j!=ret.size()-1) {
				cout << " ";
			}
		}
		cout << endl;
	}	
	return 0;
}


