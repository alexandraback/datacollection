#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string s;
    int N;
    for (int c=1; c<=T; c++) {
	cin >> s >> N;
	int acc = 0;
	vector<int> p;
	p.push_back(-1);
	int len = s.length();
	for (int i=0; i<len; i++) {
	    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
		s[i] == 'o' || s[i] == 'u') {
		acc = 0;
	    } else {
		acc++;
		if (acc >= N) {
		    p.push_back(i-N+1);
		}
	    }
	}
	int sum = 0;
	for (int i=1; i<p.size(); i++) {
	    sum += (p[i]-p[i-1]) * (len-p[i]-N+1);
	}
	cout << "Case #" << c << ": " << sum << endl;
    }
    return 0;
}
