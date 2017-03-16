
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>

using namespace std;

int main() {

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
	char S[1001] = {0}, T[2001] = {0};
	cin >> S;
	int len = strlen(S);
	int p1 = 1000, p2 = 1001;
	T[p1] = S[0];
	for (int j =1 ; j < len; j++) {
	    if (S[j] < T[p1]) {
		T[p2] = S[j];
		p2++;
	    } else {
		p1--;
		T[p1] = S[j];
	    }
	}
	char *ans = &T[p1];
	cout << "Case #" << 1+i << ": " << ans << endl;
    }

    return 0;
}


