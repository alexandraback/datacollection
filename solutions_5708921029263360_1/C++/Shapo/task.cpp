/* This is template part for Google CodeJam contest
 * created by Shapovalov Nikita, 2016
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

namespace CodeJamUtility {

    class TestCaseUtil
    {
        std::clock_t start_test_time;

        int test_id_;
        int precision_;

        std::stringstream ss;

    public:
        TestCaseUtil(int test_id, int precision = 10) : 
            start_test_time(std::clock()), 
            test_id_(test_id), 
            precision_(precision),
            ss()
        {
            std::cerr << "Processing test #" << std::setw(4) << test_id << ": ";
            ss << std::fixed << std::setprecision(precision_);
        }

        TestCaseUtil(const TestCaseUtil &) = delete;

        TestCaseUtil &operator=(const TestCaseUtil &) = delete;

        ~TestCaseUtil()
        {
            std::cerr << "Ok. Time elapsed: " << std::setw(5) << 
                (std::clock() - start_test_time) / (1. * CLOCKS_PER_SEC) << " secs" << std::endl;
            std::cout << "Case #" << test_id_ << ": " << ss.str() << "\n";
        }

        template< class T >
        friend TestCaseUtil &operator<<(TestCaseUtil &, const T &obj);

    };

    template< class T >
    TestCaseUtil &
    operator<<(TestCaseUtil &t, const T &obj)
    {
        t.ss << obj;
        return t;
    }
}

#define EXECUTE_FUNCTION(NAME) \
    process(CodeJamUtility::TestCaseUtil & NAME)

#define CODEJAM_RUN_NEW_TEST(ID, NAME) \
    {\
        CodeJamUtility::TestCaseUtil NAME(ID);\
        process(NAME);\
    }

#define CODEJAM_RUN_ALL_TESTS(NAME)\
int main() \
{\
    std::ios_base::sync_with_stdio(false); \
    int testNumber##NAME;\
    std::cin >> testNumber##NAME;\
    for (int counter##NAME = 1; counter##NAME <= testNumber##NAME; ++counter##NAME) {\
        CODEJAM_RUN_NEW_TEST(counter##NAME, NAME);\
    }\
    return 0;\
}

#include <bits/stdc++.h>

using namespace std;

/* End of template part */

bool
check(vector< vector< int > > tuples, int cnt)
{
    vector< pair< int, int > > indices = {{0, 1}, {0, 2}, {1, 2}};
    sort(tuples.begin(), tuples.end());
    int old_size = int(tuples.size());
    int new_size = int(unique(tuples.begin(), tuples.end()) - tuples.begin());
    if (old_size != new_size) {
        return false;
    }
    for (auto pr : indices) {
        vector< pair< int, int > > tmp;
        for (const vector< int > &tp : tuples) {
            tmp.push_back(make_pair(tp[pr.first], tp[pr.second]));
        }
        sort(tmp.begin(), tmp.end());
        int l = 0, n = int(tmp.size());
        while (l < n) {
            int r = l;
            while (r < n && tmp[l] == tmp[r]) ++r;
            if (r - l > cnt) return false;
            l = r;
        }
    }
    return true;
}

void
EXECUTE_FUNCTION(out)
{
    int j, p, s, k;
    cin >> j >> p >> s >> k;
    vector< vector< int > > res;
    int diff = min(s, k);
    for (int i1 = 0; i1 < j; ++i1) {
        for (int i2 = 0; i2 < p; ++i2) {
            for (int l = 0; l < diff; ++l) {
                int i3 = (i1 + i2 + l) % s;
                res.push_back({i1, i2, i3});
            }
        }
    }
    assert(check(res, k));
    out << res.size();
    for (const auto &v : res) {
        out << "\n";
        for (int x : v) {
            out << x + 1 << ' ';
        }
    }
}

CODEJAM_RUN_ALL_TESTS(Qual_2015_)
