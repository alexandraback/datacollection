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
    int testNumber##NAME;\
    std::cin >> testNumber##NAME;\
    for (int counter##NAME = 1; counter##NAME <= testNumber##NAME; ++counter##NAME) {\
        CODEJAM_RUN_NEW_TEST(counter##NAME, NAME);\
    }\
    return 0;\
}

/* End of template part */

#include <vector>
#include <iostream>

using namespace std;

void
EXECUTE_FUNCTION(out)
{
    int n;
    cin >> n;
    vector< int > cnt(n + 1);
    string s;
    cin >> s;
    cerr << s << endl;
    for (int i = 0; i <= n; ++i) {
        cnt[i] = s[i] - '0';
    }
    int l = -1, r = n + 2;
    while (l < r - 1) {
        int m = (l + r) / 2;
        bool can = true;
        int cur_applause = m;
        for (int i = 0; i <= n && can; ++i) {
            if (cur_applause >= i) {
                cur_applause += cnt[i];
            } else {
                can = false;
            }
        }
        if (can) {
            r = m;
        } else {
            l = m;
        }
    }
    out << r;
}

CODEJAM_RUN_ALL_TESTS(Qual_2015_A)
