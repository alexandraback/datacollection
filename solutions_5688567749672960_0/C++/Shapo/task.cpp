/* This is template part for Google CodeJam contest
 * created by Shapovalov Nikita, 2014
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

int
reverse_val(int x)
{
    int ans = 0;
    while (x) {
        int rem = x % 10;
        x /= 10;
        ans = ans * 10 + rem;
    }
    return ans;
}

void
EXECUTE_FUNCTION(out)
{
    int n;
    cin >> n;
    int ans = 0;
    vector< int > q(n + 1);
    vector< int > dist(n + 1, -1);
    dist[1] = 1;
    int qh = 0, qt = 0;
    q[qt++] = 1;
    while (qh < qt) {
        int cur = q[qh++];
        int x = reverse_val(cur);
        if (x <= n && dist[x] == -1) {
            dist[x] = dist[cur] + 1;
            q[qt++] = x;
        }
        x = cur + 1;
        if (dist[x] == -1) {
            dist[x] = dist[cur] + 1;
            q[qt++] = x;
        }
    }
    ans = dist[n];
    out << ans;
}

CODEJAM_RUN_ALL_TESTS(Round1B_2015_A)
