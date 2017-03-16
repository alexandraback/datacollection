#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <stack>

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
    //cerr << obj << endl;
    return t;
}

typedef vector< int > vi;
typedef vector< vi > vvi;

bool
reach_all(const vi &add, const vi &path, vvi &g, int n)
{
    vi used(add.begin(), add.end());
    vi q(2 * add.size());
    int qh = 0, qt = 0;
    for (auto x : path) {
        used[x] = 1;
        q[qt++] = x;
    }
    while (qh < qt) {
        int cur = q[qh++];
        for (auto x : g[cur]) {
            if (!used[x]) {
                used[x] = 1;
                q[qt++] = x;
            }
        }
    }
    /*cerr << "reach all path = ";
    for (auto x : path) {
        cerr << x << " ";
    } cerr << endl;
    cerr << "add = ";
    for (auto x : add) {
        cerr << x << " ";
    } cerr << endl;*/
    size_t cnt = 0;
    //cerr << "used : ";
    for (auto x : used) {
        cnt += x;
        //cerr << x << " ";
    }
    //cerr << endl;
    return (cnt == add.size());
}

void
process(int test_id)
{
    TestCaseUtil cur_test(test_id);
    //cerr << endl;
    int n, m;
    cin >> n >> m;
    vector< pair< string, int > > codes_num(n);
    vector< vector< int > > g(n + 5);
    for (int i = 0; i < n; ++i) {
        cin >> codes_num[i].first;
        codes_num[i].second = i;
    }
    sort(codes_num.begin(), codes_num.end());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vi used(n, 0);
    vi par(n, -1);
    int last_vertex = codes_num.front().second;
    used[last_vertex] = true;
    /*for (auto x : codes_num) {
        cerr << x.first << " " << x.second << endl;
    }*/
    cur_test << codes_num.front().first;
    for (int i = 1; i < n; ++i) {
        //cerr << "i = " << i << " last_vertex = " << last_vertex << endl;
        int j = 0;
        while (j < n) {
            if (used[codes_num[j].second]) {
                ++j;
                continue;
            }
            int v = codes_num[j].second;
            int cur_vertex = last_vertex;
            while (cur_vertex != -1) {
                auto it = find(g[cur_vertex].begin(), g[cur_vertex].end(), v);
                if (it == g[cur_vertex].end()) {
                    cur_vertex = par[cur_vertex];
                    continue;
                }
                vi path;
                int tmp_v = cur_vertex;
                while (tmp_v != -1) {
                    path.push_back(tmp_v);
                    tmp_v = par[tmp_v];
                }
                reverse(path.begin(), path.end());
                path.push_back(v);
                if (reach_all(used, path, g, n)) {
                    break;
                }
                cur_vertex = par[cur_vertex];
            }
            if (cur_vertex != -1) {
                par[v] = cur_vertex;
                used[v] = 1;
                cur_test << codes_num[j].first;
                last_vertex = v;
                break;
            }
            ++j;
        }
        if (j == n) {
            //cerr << "i = " << i << endl;
            assert(false);
        }
    }
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
