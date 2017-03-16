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
    precalc();\
    int testNumber##NAME;\
    std::cin >> testNumber##NAME;\
    for (int counter##NAME = 1; counter##NAME <= testNumber##NAME; ++counter##NAME) {\
        CODEJAM_RUN_NEW_TEST(counter##NAME, NAME);\
    }\
    return 0;\
}

/* End of template part */

#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

typedef long long ll;

map< pair< string, string >, string > conv;

void
precalc()
{
    conv[{"1", "1"}] = "1";
    for (auto x : {"i", "j", "k"}) {
        conv[{"1", x}] = conv[{x, "1"}] = x;
        conv[{x, x}] = "-1";
    }
    conv[{"i", "j"}] = "k";
    conv[{"j", "k"}] = "i";
    conv[{"k", "i"}] = "j";
    conv[{"j", "i"}] = "-k";
    conv[{"k", "j"}] = "-i";
    conv[{"i", "k"}] = "-j";
}

string
get_val(string a, string b)
{
    string res = "";
    if (a[0] == '-') {
        res += "-";
        a = a.substr(1);
    }
    if (b[0] == '-') {
        res += "-";
        b = b.substr(1);
    }
    res += conv[{a, b}];
    while (res.size() > 2) {
        res = res.substr(2);
    }
    return res;
}

void
EXECUTE_FUNCTION(out)
{
    ll x, l;
    string s;
    cin >> l >> x;
    cin >> s;
    string st_val = "1";
    for (int i = 0; i < l; ++i) {
        string x = s.substr(i, 1);
        st_val = get_val(st_val, x);
    }
    int mod = x % 4;
    string all_val = "1";
    for (int i = 0; i < mod; ++i) {
        all_val = get_val(all_val, st_val);
    }
    if (all_val != "-1") {
        out << "NO";
        return;
    }
    ll min_i = l * x, min_k = l * x;
    string cur_pref = "1";
    for (int i = 0; i < l; ++i) {
        cur_pref = get_val(cur_pref, s.substr(i, 1));
        string tmp_pref = cur_pref;
        for (int j = 0; j < 4; ++j) {
            if (tmp_pref == "i") {
                min_i = min(min_i, i + 1ll + j * l);
            }
            tmp_pref = get_val(st_val, tmp_pref);
        }
    }
    cur_pref = "1";
    for (int i = l - 1; i >= 0; --i) {
        cur_pref = get_val(s.substr(i, 1), cur_pref);
        string tmp_pref = cur_pref;
        for (int j = 0; j < 4; ++j) {
            if (tmp_pref == "k") {
                min_k = min(min_k, l - i + j * l);
            }
            tmp_pref = get_val(tmp_pref, st_val);
        }
    }
    if (min_i + min_k < x * l) {
        out << "YES";
    } else {
        out << "NO";
    }
}

CODEJAM_RUN_ALL_TESTS(Qual_2015_C)
