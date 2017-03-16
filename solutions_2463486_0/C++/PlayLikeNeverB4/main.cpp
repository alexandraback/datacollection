#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#include <cstring>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXV 1024
int T, A, B;
bool good[MAXV];
int sum[MAXV];
char aux[50];

bool palindrome(int n) {
    sprintf(aux, "%d", n);
    string s(aux);

    for(int i = 0; i < (int)s.size() / 2; i++)
        if(s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

    for(int i = 1; i <= 50; i++)
        if(i * i < MAXV && palindrome(i) && palindrome(i * i))
            good[i * i] = true;

    sum[0] = 0;
    for(int i = 1; i < MAXV; i++)
        sum[i] = sum[i - 1] + good[i];

	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", t, sum[B] - sum[A - 1]);
	}

	return 0;
}
