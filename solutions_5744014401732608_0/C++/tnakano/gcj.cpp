#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;
using i8  = int8_t;  using u8  = uint8_t;
using i16 = int16_t; using u16 = uint16_t;
using i32 = int32_t; using u32 = uint32_t;
using i64 = int64_t; using u64 = uint64_t;
using f32 = float_t; using f64 = double_t;
using usize = size_t;using str = string;
template <class T> using vec = vector<T>;
#define times(n, i) for (i32 i = 0; i < (n); i++)
#define range(n, m, i) for (i32 i = (n); i < (m); i++)
#define upto(n, m, i) for (i32 i = (n); i <= (m); i++)
#define downto(n, m, i) for (i32 i = (n); i >= (m); i--)
#define foreach(xs, x) for (auto &x : (xs))
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define uniqueall(xs) (xs).erase(unique(all(xs)), (xs).end())
#define maximum(xs) *max_element(all(xs))
#define minimum(xs) *min_element(all(xs))
const i64 MOD = 1000000007;

pair<bool, vec<str>> solve(i32 b, i32 m) {
    if (int(pow(2, b-1)-1) < m) {
        vec<str> x;
        return make_pair(false, x);
    }

    vec<vec<i32>> d(b);
    times(b, i) {
        i32 h = pow(2, b-1-i) - 1;
        d[i].resize(b);
        times(b, j) {
            i32 p = b-j-1;
            d[i][p] = h & 1;
            h >>= 1;
        }
    }

    vec<str> ret(b);
    times(b, i) {
        str l = "";
        times(b, j) {
            l += '0' + d[i][j];
        }
        ret[i] = l;
    }
    return make_pair(true, ret);
}

i32 main()
{
    i32 t;
    cin >> t;
    vec<i32> b(t), m(t);
    times(t, i) {
        cin >> b[i] >> m[i];
    }
    times(t, i) {
        pair<bool, vec<str>> ans = solve(b[i], m[i]);
        cout << "Case #" << (i+1) << ": " << (ans.first ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        if (ans.first) {
            times(ans.second.size(), i) {
                cout << ans.second[i] << endl;
            }
        }
    }
    return 0;
}