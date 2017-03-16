#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class TestCaseUtil
{
    clock_t start_test_time;
    int test_id_;
    stringstream ss;
public:
    TestCaseUtil(int test_id) : start_test_time(clock()), test_id_(test_id), ss()
    {
        cerr << "Processing test #" << setw(3) << test_id << ": ";
    }
    TestCaseUtil(const TestCaseUtil &) = delete;
    TestCaseUtil &operator=(const TestCaseUtil &) = delete;
    ~TestCaseUtil()
    {
        cerr << "Ok. Time elapsed: " << setw(5) << 
            (clock() - start_test_time) / CLOCKS_PER_SEC << " secs" << endl;
        cout << "Case #" << test_id_ << ": " << ss.str() << endl;
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

typedef long long ll;

void
process(int test_id)
{
    TestCaseUtil cur_test(test_id);
    ll res = 0LL;
    ll a, b, k;
    cin >> a >> b >> k;
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            if ((i & j) < k) {
                ++res;
            }
        }
    }
    cur_test << res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        process(i);
    }
    return 0;
}
