#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <valarray>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <boost/variant.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": "  << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template<class T>
class IsIterable__ {static void f(...); template<class U> static typename U::const_iterator f(const U&);
public:const static bool value = !std::is_same<void, decltype(f(std::declval<T>()))>::value;};

template <class F, class S> ostream& operator << (ostream& o, const pair<F,S>& p) {
return o << "(" << p.first << ", " << p.second << ")";}

template<class C>void O__(ostream& o, const C& c) {
bool f = 1; for(const auto& x: c) {if (!f) o << ", "; if (IsIterable__<decltype(x)>::value) o << "\n"; f = 0; o << x;}}

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {o << "[";O__(o, v);o << "]";return o;}

template <class T, class V>
ostream& operator << (ostream& o, const map<T, V>& v) {o << "{";O__(o, v);o << "}"; return o;}

template <class T>
ostream& operator << (ostream& o, const set<T>& v) {o << "{";O__(o, v);o << "}";return o;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

#if GCC_VERSION > 40900
// supports find_by_order(int) and order_of_key(Key)
template<class Key, class Value>
using MapWithOrderStatistics = tree<Key, Value,
      std::less<Key>, rb_tree_tag /*splay_tree_tag*/,
      tree_order_statistics_node_update>;
#endif

#define QuaternionClass(x) class x {\
    public:\
          explicit x(int sign=+1):sign_(sign) {} \
          int sign() const {return sign_;}\
    private:\
        int sign_;\
};

QuaternionClass(One)
QuaternionClass(I)
QuaternionClass(J)
QuaternionClass(K)

#define QuaternionMulRule(x,y,z,si) Quaternion operator()(const x& X, const y& Y) const {\
    return z(X.sign() * Y.sign() * si);}

typedef boost::variant<One, I, J, K> Quaternion;

class QuaternionMultiplicationVisitor: public boost::static_visitor<Quaternion>  {
public:
    QuaternionMulRule(One, One, One, +1)
    QuaternionMulRule(One, I, I, +1)
    QuaternionMulRule(One, J, J, +1)
    QuaternionMulRule(One, K, K, +1)

    QuaternionMulRule(I, One, I, +1)
    QuaternionMulRule(I, I, One, -1)
    QuaternionMulRule(I, J, K, +1)
    QuaternionMulRule(I, K, J, -1)

    QuaternionMulRule(J, One, J, +1)
    QuaternionMulRule(J, I, K, -1)
    QuaternionMulRule(J, J, One, -1)
    QuaternionMulRule(J, K, I, +1)

    QuaternionMulRule(K, One, K, +1)
    QuaternionMulRule(K, I, J, +1)
    QuaternionMulRule(K, J, I, -1)
    QuaternionMulRule(K, K, One, -1)
};

class QuaternionHash: public boost::static_visitor<size_t>  {
public:
    size_t operator()(const One& x) const {
        return x.sign() == +1 ? 0 : 1;
    }
    size_t operator()(const I& x) const {
        return x.sign() == +1 ? 2 : 3;
    }
    size_t operator()(const K& x) const {
        return x.sign() == +1 ? 4 : 5;
    }
    size_t operator()(const J& x) const {
        return x.sign() == +1 ? 6 : 7;
    }
};

Quaternion uncodedQuaternion[8] = {One(), One(-1), I(), I(-1), K(), K(-1), J(), J(-1)};
Quaternion quaternionForStage[3] = {I(), J(), K()};

bool solve(size_t pos, size_t stage, size_t prodHash,
        const vector<Quaternion>& q,
        vector<vector<vector<bool>>> & dp,
        vector<vector<vector<bool>>> & calculated) {
    if (calculated[pos][stage][prodHash]) {
        return dp[pos][stage][prodHash];
    }
    bool res = pos == q.size() && stage == 3 && prodHash == QuaternionHash()(One());

    if (stage < 3 &&
            boost::apply_visitor(QuaternionHash(), quaternionForStage[stage]) ==
                prodHash) {
        res = res || solve(pos, stage + 1, QuaternionHash()(One()),
                q,dp,calculated);
    }

    if (pos < q.size()) {
        Quaternion newProd = boost::apply_visitor(QuaternionMultiplicationVisitor(),
                uncodedQuaternion[prodHash], q[pos]);

        size_t newProdHash = boost::apply_visitor(QuaternionHash(),
                newProd);

        res = res || solve(pos + 1, stage, newProdHash,
                q, dp, calculated);
    }

    calculated[pos][stage][prodHash] = true;
    return dp[pos][stage][prodHash] = res;
}

vector<Quaternion> q;
vector<vector<vector<bool>>> dp;
vector<vector<vector<bool>>> calculated;

int main() {
    std::ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int id = 0; id < tests; ++id) {
        cerr << "--\n";
        debug(id);
        q.clear();
        ll l,x;
        cin >> l >> x;
        string s;
        cin >> s;
        ll new_x = x % 4;
        while(new_x + 4 <= x && new_x <= 12) {
            new_x += 4;
        }
        x = new_x;
        debug(x);

        for (ll i = 0; i < x; ++i)
            for (char ch: s) {
                if (ch == 'i')
                    q.push_back(I());
                if (ch == 'j')
                    q.push_back(J());
                if (ch == 'k')
                    q.push_back(K());
            }
        debug(q.size());
        dp.assign(1+q.size(),
                vector<vector<bool>>(4,
                    vector<bool>(8,0)));
        calculated = dp;

        cout << "Case #" << id + 1 << ": ";
        cout.flush();
        //cout << (solve(0, 0, 0, q, dp, calculated)? "YES":"NO") << "\n";
        for (int pos = (int)q.size(); pos >= 0; --pos) {
            for (int stage = 3; stage >= 0; --stage) {
                for (int prodHash = 0; prodHash < 8; ++prodHash) {
                    bool res = pos == q.size() && stage == 3 && prodHash == QuaternionHash()(One());

                    if (stage < 3 &&
                            boost::apply_visitor(QuaternionHash(), quaternionForStage[stage]) ==
                                prodHash) {
                        res = res || dp[pos][stage + 1][QuaternionHash()(One())];
                            //solve(pos, stage + 1, QuaternionHash()(One()),
                            //    q,dp,calculated);
                    }

                    if (pos < q.size()) {
                        Quaternion newProd = boost::apply_visitor(QuaternionMultiplicationVisitor(),
                                uncodedQuaternion[prodHash], q[pos]);

                        size_t newProdHash = boost::apply_visitor(QuaternionHash(),
                                newProd);

                        res = res || dp[pos+1][stage][newProdHash];
                        //solve(pos + 1, stage, newProdHash,
                        //        q, dp, calculated);
                    }

                    calculated[pos][stage][prodHash] = true;
                    dp[pos][stage][prodHash] = res;

                }
            }
        }
        cout << (dp[0][0][0]? "YES":"NO") << "\n";

    }


    return 0;
}
