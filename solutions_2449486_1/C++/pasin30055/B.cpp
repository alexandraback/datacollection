#include <iostream>
#include <cstdio>

#define MAX_N 105
#define MAX_A 105

using namespace std;

int n,m;
int a[MAX_N][MAX_N];
bool ok[MAX_N][2];
bool answer;

int main() {
    int tests;
    scanf("%d", &tests);
    for (int test = 0 ; test < tests ; test ++) {
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; i ++) {
	    for (int j = 0 ; j < m ; j ++) {
		scanf("%d", &a[i][j]);
	    }
	}
	answer = true;
	for (int l = 0 ; l < MAX_A ; l ++) {
	    for (int i = 0 ; i < n ; i ++) {
		ok[i][0] = true;
		for (int j = 0 ; j < m ; j ++) {
		    if (a[i][j] > l) ok[i][0] = false;
		}
	    }
	    for (int j = 0 ; j < m ; j ++) {
		ok[j][1] = true;
		for (int i = 0 ; i < n ; i ++) {
		    if (a[i][j] > l) ok[j][1] = false;
		}
	    }
	    for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j < m ; j ++) {
		    if (a[i][j] <= l and !ok[i][0] and !ok[j][1]) answer = false;
		}
	    }
	}
	if (answer) printf("Case #%d: YES\n", test + 1);
	else printf("Case #%d: NO\n", test + 1);
    }
    return 0;
}
