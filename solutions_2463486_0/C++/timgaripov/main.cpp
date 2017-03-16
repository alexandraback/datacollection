#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define len(x) (int((x).size()))
#ifdef LOCALD
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#ifdef __linux__
#define I64d "%lld"
#else
#define I64d "%I64d"
#endif

typedef long long int int64;
typedef long double ext;

const int inf = 1000000000;

const int scnt = 39;
const int64 small[39] = {1ll, 4ll, 9ll, 121ll, 484ll, 10201ll, 12321ll, 14641ll, 40804ll, 44944ll, 1002001ll, 1234321ll, 4008004ll, 100020001ll, 102030201ll, 104060401ll, 121242121ll, 123454321ll, 125686521ll, 400080004ll, 404090404ll, 10000200001ll, 10221412201ll, 12102420121ll, 12345654321ll, 40000800004ll, 1000002000001ll, 1002003002001ll, 1004006004001ll, 1020304030201ll, 1022325232201ll, 1024348434201ll, 1210024200121ll, 1212225222121ll, 1214428244121ll, 1232346432321ll, 1234567654321ll, 4000008000004ll, 4004009004004ll};

using namespace std;

char s[100];

bool palindrome(int64 x){
	sprintf(s, I64d, x);
	int n = strlen(s);
	for (int i = 0; i < n / 2; i++){
		if (s[i] != s[n - i - 1])
			return false;
	}
	return true;
}

int tests;
int64 cnt;
int64 a, b;

int main()
{
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++){
		scanf(I64d" "I64d"\n", &a, &b);
		cnt = 0;
		for (int i = 0; i < scnt; i++){
			if ((a <= small[i]) && (small[i] <= b))
				cnt++;
		}
		printf("Case #%d: "I64d"\n", test, cnt);
	}
    return 0;
}
