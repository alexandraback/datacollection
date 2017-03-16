#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
#define MAX_N (105)
int M[MAX_N + 1];
int P[MAX_N + 1];

int main()
{
    int T;
    scanf("%d", &T);

    M[0] = P[0] = 0;
    for ( int t = 0; t < T; t++ ) {
	string s;
	cin >> s;
	for ( int i = 0; i < s.size(); i++ ) {
	    if ( s[i] == '+' ) {
		P[i+1] = P[i];
		M[i+1] = P[i+1] + 1;
	    }
	    else {
		M[i+1] = M[i];
		P[i+1] = M[i+1] + 1;
	    }
	}

	printf("Case #%d: %d\n", t+1, min( P[s.size()], M[s.size()] + 1 ));
    }

    return 0;
}
