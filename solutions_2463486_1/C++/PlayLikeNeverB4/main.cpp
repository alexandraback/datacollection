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

#define INF 1000000000
#define MAXV 100000000000500LL
//#define MAXV 100000500LL
int T;
long long A, B;
vector<long long> s;
vector<long long> :: iterator it;
char aux[50];

bool palindrome(long long n) {
    sprintf(aux, "%I64d", n);
    string s(aux);

    for(int i = 0; i < (int)s.size() / 2; i++)
        if(s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);

    for(long long i = 1; i * i < MAXV; i++)
        if(palindrome(i) && palindrome(i * i))
            s.push_back(i * i);

	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
        scanf("%I64d %I64d", &A, &B);

        int sumA = -INF;
        int sumB = INF;

        it = upper_bound(s.begin(), s.end(), B);
        it--;
        sumB = it - s.begin() + 1;

        it = lower_bound(s.begin(), s.end(), A);
        if(it != s.begin()) {
            it--;
            sumA = it - s.begin() + 1;
        }
        else sumA = 0;

        printf("Case #%d: %d\n", t, sumB - sumA);
	}

	return 0;
}
