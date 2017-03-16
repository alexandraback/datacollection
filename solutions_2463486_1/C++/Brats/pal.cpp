#include<iostream>
#include<sstream>
using namespace std;

bool ispalin(long long i) {
    ostringstream ss;
	ss << i;
	string s = ss.str();
	
	if (s == string(s.rbegin(), s.rend())) {
        return true;
	}
	return false;
}

int main()
{
    long long i = 1;
	while (i < 1000000001l) {
	    if (ispalin(i)) {
		    if (ispalin(i*i)) {
			    cout << i*i << ",\n";
			}
		}
		i++;
    }
}
