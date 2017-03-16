#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    unsigned int n;
    ios::sync_with_stdio(false);
    
    cin >> n;
    for (unsigned int i = 0; i < n; i++) {
	string stack;
        cin >> stack;
	
	unsigned int len = stack.size();
	string s;
	s.push_back(stack[0]);
	for (unsigned int j = 1; j < len; j++) {
	    if (stack[j] >= s[0]) {
		s.insert(s.begin(), stack[j]);
	    }
	    else {
		s.push_back(stack[j]);
	    }
	}
      
        cout << "Case #" << i+1 << ": " << s << endl;
    }
    return 0;
}