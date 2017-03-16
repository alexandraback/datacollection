#include <stdio.h>
#include <string.h>
#include <math.h>
int v[10000001];
using namespace std;

int testcase = 0;
int solve(long long x2) {
    long long x = sqrt(x2);
    if (x == 0)
        return 0;
    return v[x];
}
void run()
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("%d\n", solve(b) - solve(a-1));
}

bool is_palindrome(long long x) {
    char num[20];
    sprintf(num, "%lld", x);

    int s = strlen(num);
    for (int i = 0; i < s; ++i)
        if (num[i] != num[s-1-i])
            return false;
    return true;
}

int main()
{
    #if 1
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w+", stdout);
    #endif // ONLINE_JUDGE


    v[0] = 0;
    #if 1
    for (long long x = 1; x <= 1000; ++x) {
        v[x] = v[x-1];
        long long x2 = x*x;

        if (is_palindrome(x) && is_palindrome(x*x)) {
            ++v[x];
        }
    }
    #endif


	int testcases;
	scanf("%d", &testcases);
	for (testcase = 1; testcase <= testcases; ++testcase)
	{
	    printf("Case #%d: ", testcase);
		run();
	}
	return 0;
}
