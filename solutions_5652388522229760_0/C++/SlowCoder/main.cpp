
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

i64 solve(int in) {
    unordered_set<char> digits;
    unordered_set<int> numbers;
    
    int num = in;
    
    for (;;) {
        if (numbers.count(num)) {
            return -1;
        }

        numbers.insert(num);
        
        string str = to_string(num);
        for (char c : str) {
            digits.insert(c);
            if (digits.size() == 10) {
                return num;
            }
        }
        
        num += in;
    }
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

        ui64 N;
        scanf("%lld", &N);
        
        i64 r = solve(N);

        if (r >= 0) {
            printf("Case #%d: %lld\n", t, r);
        } else {
            printf("Case #%d: INSOMNIA\n", t);
        }
	}
	
	if (READ_IN_FILE) fclose(stdin);
	return 0;
}
