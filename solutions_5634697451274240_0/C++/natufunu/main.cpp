#include <iostream>
#include <string> 

using namespace std;

// !@#$^&*()_+
// {}
// :'|
// <>?
int main () {
	int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	string s;
    	cin >> s;
    	s.push_back('+');
    	
    	int n = 0;
    	for (int j = 0; j < s.size()-1; j++) {
    		if (s[j] != s[j+1]) {
    			n++;
    		} 
    	}
    	cout << "Case #" << i <<": " << n << endl;
    }
}