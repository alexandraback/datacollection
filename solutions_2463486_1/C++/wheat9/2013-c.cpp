#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_palidrome(long long n) {
        vector<int> digits;
        while (n > 0) {
                digits.push_back(n % 10);
                n /= 10;
        }

        int i = 0, j = digits.size() - 1;
        while (i <= j) {
                if (digits[i] == digits[j]) {
                        ++i;
                        --j;
                } else {
                        return false;
                }
        }
        return true;
}

void gen_tbl(vector<long long> &tbl, long long max_b)
{
        long long bm = sqrtl(max_b);
        for (long long i = 1; i < bm; ++i) {
                if (is_palidrome(i) && is_palidrome(i * i))
                        tbl.push_back(i * i);
        }
}


unsigned long long precomputed_tbl[] = {
        1ULL, 4ULL, 9ULL, 121ULL, 484ULL, 10201ULL, 12321ULL, 14641ULL, 40804ULL, 44944ULL, 1002001ULL, 1234321ULL, 4008004ULL, 100020001ULL, 102030201ULL, 104060401ULL, 121242121ULL, 123454321ULL, 125686521ULL, 400080004ULL, 404090404ULL, 10000200001ULL, 10221412201ULL, 12102420121ULL, 12345654321ULL, 40000800004ULL, 1000002000001ULL, 1002003002001ULL, 1004006004001ULL, 1020304030201ULL, 1022325232201ULL, 1024348434201ULL, 1210024200121ULL, 1212225222121ULL, 1214428244121ULL, 1232346432321ULL, 1234567654321ULL, 4000008000004ULL, 4004009004004ULL,
};
                   
int main()
{
        int t;
        unsigned long long a, b;
#if 0
        vector<long long> tbl;
        static const long long MAX_B = 100000000000000;
        gen_tbl(tbl, MAX_B);

        copy(tbl.begin(), tbl.end(), ostream_iterator<long long>(cout, "ULL, "));
#else
        cin >> t;        
        const unsigned s = sizeof(precomputed_tbl) / sizeof(unsigned long long);

        for (int i = 1; i <= t; ++i) {
                cin >> a >> b;
                int count = 0;
                for (size_t j = 0; j < s && precomputed_tbl[j] <= b; ++j) {
                        if (precomputed_tbl[j] >= a)
                                ++count;
                }
                cout << "Case #" << i << ": " << count << "\n";
        }
#endif
        return 0;
}
