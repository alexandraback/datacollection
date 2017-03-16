#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int solve(string& ans1_m1, string& ans1_m2, string& ans2_m1, string& ans2_m2, int acc, char a, char b, int delta) {
    for (;;) {
        if (delta - acc < 0)
            break;
        delta -= acc;
        ++acc;
        ans1_m1 += a;
        ans1_m2 += a;
    }

    {
        int delta_ = delta;
        while (delta_--) {
            ans2_m1 += b;
            ans2_m1 += a;
        }
    }

    {
        ans1_m2 += a;
        int delta_ = acc - delta;
        while (delta_--) {
            ans2_m2 += a;
            ans2_m2 += b;
        }
    }

    return acc;
}

void run() {
    int x, y;
    cin>>x>>y;

    char ax = x > 0 ? 'E' : 'W';
    char bx = x > 0 ? 'W' : 'E';
    char ay = y > 0 ? 'N' : 'S';
    char by = y > 0 ? 'S' : 'N';
    x = abs(x);
    y = abs(y);

    string ans1_m1, ans1_m2, ans2_m1, ans2_m2;
    const int acc = solve(ans1_m1, ans1_m2, ans2_m1, ans2_m2, 1, ax, bx, x);

    string str;
    {
        string aaa1_m1 = ans1_m1, aaa1_m2 = ans1_m1, aaa2_m1 = ans2_m1, aaa2_m2 = ans2_m1;
        solve(aaa1_m1, aaa1_m2, aaa2_m1, aaa2_m2, acc, ay, by, y);
        string str1 = aaa1_m1 + aaa2_m1;
        string str2 = aaa1_m2 + aaa2_m2;
        str = str1;
        if (str2.size() < str.size())
            str = str2;
    }
    {
        string aaa1_m1 = ans1_m2, aaa1_m2 = ans1_m2, aaa2_m1 = ans2_m2, aaa2_m2 = ans2_m2;
        solve(aaa1_m1, aaa1_m2, aaa2_m1, aaa2_m2, acc+1, ay, by, y);
        string str1 = aaa1_m1 + aaa2_m1;
        string str2 = aaa1_m2 + aaa2_m2;

        if (str1.size() < str.size())
            str = str1;
        if (str2.size() < str.size())
            str = str2;
    }

    cout << " " << str <<endl;
}

int main()
{
    #if 1
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w+", stdout);
    #endif

	int testcases;
	scanf("%d", &testcases);
	for (int testcase = 1; testcase <= testcases; ++testcase)
	{
	    printf("Case #%d:", testcase);
		run();
	}
	return 0;
}
