#include <iostream>
#include <string> 

using namespace std;

// !@#$^&*()_+
// {}
// :'|
// <>?


static int N, J;

void step(string s, int depth) {
    static int j = 0;

    if (j == J) {
        return;
    } 

    if (depth == N/2 -2) {
        cout << "11" << s << "11" << " 3 4 5 6 7 8 9 10 11" << endl;
        j++;
        return;
    }

    step(s + "00", depth+1);
    step(s + "11", depth+1);
}

int main () {
	int t; 
    cin >> t;
    for (int i = 1; i <= t; i++) {
    	cin >> N >> J;
    	cout << "Case #" << i <<":" << endl;
        step("",0);
    }
}