
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <bitset>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <numeric>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>

#define i64 long long
#define ui64 unsigned long long

using namespace std;

#define READ_IN_FILE 1

#ifdef ONLINE_JUDGE
#define READ_IN_FILE 0
#endif

void rev(string &in, int end) {
    int l = 0, r = end;
    while (l <= r) {
        char tmp = in[l];

        if (in[r] == '+')
            in[l] = '-';
        else
            in[l] = '+';

        if (tmp == '+')
            in[r] = '-';
        else
            in[r] = '+';

        l++; r--;
    }
}

int solve(string in) {
    if (!in.length()) return 0;
    
    int rev_cnt = 0;
    bool did_rev = false;
    
    while (true) {
        did_rev = false;

        for (int i = 1; i < in.length(); i++) {
            if (in[i] != in[0]) {
                did_rev = true;
                rev_cnt++;
                rev(in, i - 1);
                break;
            }
        }
        
        if (!did_rev) {
            if (in[0] == '+')
                return rev_cnt;
            else
                return rev_cnt + 1;
        }
    }
    return -1;
}

int main()
{
	if (READ_IN_FILE) freopen("in.in", "r", stdin);
	
	int T;
	scanf("%d\n", &T);
	if (!T) {
		cerr << "Check input!" << endl;
		exit(0);
	}

	for (int t = 1; t <= T; t++) {

        string s;
//        scanf("%s", &s);
        
        getline (cin, s);
        
        int r = solve(s);

        printf("Case #%d: %d\n", t, r);
    }
	
	if (READ_IN_FILE) fclose(stdin);
	return 0;
}
