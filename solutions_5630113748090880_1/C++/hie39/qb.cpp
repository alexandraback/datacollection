#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    unsigned int case_num;
    ios::sync_with_stdio(false);
    
    cin >> case_num;
    for (unsigned int i = 0; i < case_num; i++) {
	unsigned int  n;
        cin >> n;
	
	vector<unsigned int> v(2501);
	for (unsigned int j = 0; j < 2*n*n - n; j++) {
	    unsigned int tmp;
	    cin >> tmp;
	    v[tmp]++;
	}
	
        cout << "Case #" << i+1 << ":";
	for (unsigned int j = 0; j <= 2500; j++) {
	    if (v[j] % 2) {
		cout << " " << j;
	    }
	}
	cout << endl;
    }
    return 0;
}