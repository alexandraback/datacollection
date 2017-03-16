#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXL 128
long long seq[100] = {
0LL,
1LL,
4LL,
9LL,
121LL,
484LL,
10201LL,
12321LL,
14641LL,
40804LL,
44944LL,
1002001LL,
1234321LL,
4008004LL,
100020001LL,
102030201LL,
104060401LL,
121242121LL,
123454321LL,
125686521LL,
400080004LL,
404090404LL,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,
1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL,
100000020000001LL,
100220141022001LL,
102012040210201LL,
102234363432201LL,
121000242000121LL,
121242363242121LL,
123212464212321LL,
123456787654321LL,
400000080000004LL,
2000000000000000LL
};

int myBinary(long long x) {
    int left = 0, right = 49;
    int mid;
    while (left + 1 < right) {
        mid = (left + right) / 2;
        if (seq[ mid ] <= x) left = mid;
            else right = mid;
    }
    return left;
}

int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	long long a, b;
	for (int p = 1; p <= t; ++p) {
	    cin >> a >> b;
	    cout << "Case #" << p << ": " << myBinary(b) - myBinary(a - 1) << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
