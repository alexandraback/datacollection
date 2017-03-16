#include <iostream>
#include <cassert>
#include <cstdlib>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

template <typename T> int sgn(T val) { return (T(0) < val) - (val < T(0)); }

#define I 2
#define J 3
#define K 4

string s;

int mulM[5][5] =
{
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I,-1, K,-J},
    {0, J,-K,-1, I},
    {0, K, J,-I,-1},
};

struct Q
{
    signed char v;
    explicit Q(int vv = 1) : v(vv) {}
};
Q mulQ(Q a, Q b) { return Q(sgn(a.v) * sgn(b.v) * mulM[abs(a.v)][abs(b.v)]); }
Q mrlQ(Q a, Q b) { return mulQ(b, a); }
Q operator * (Q a, Q b) { return mulQ(a, b); }
bool operator == (Q a, Q b) { return a.v == b.v; }
bool operator != (Q a, Q b) { return a.v != b.v; }
bool operator  < (Q a, Q b) { return a.v  < b.v; }

template <typename IterT, typename OpT>
Q mul2(IterT beg, IterT end, int64_t const X, OpT op)
{
    Q sq;
    for (IterT it = beg; it != end; ++it) sq = op(sq, *it);

    vector<Q> powQ(64);
    powQ[0] = sq;
    for (size_t i = 1; i < powQ.size(); ++i)
        powQ[i] = op(powQ[i-1], powQ[i-1]);

    Q res;
    for (int64_t i = 0; i <= 62; ++i)
        if (X & (1LL << i))
            res = op(res, powQ[i]);

    return res;
}

Q mul1(vector<Q> const & S, int64_t X)
{
    vector<Q>SX(S.size() * X);
    for (size_t i = 0; i < SX.size(); ++i) SX[i] = S[i % S.size()];

    return accumulate(SX.begin(), SX.end(), Q(1), mulQ);
}

template <typename IterT, typename OpT>
int64_t firstQ1(Q v, IterT beg, IterT end, int64_t const X, OpT op)
{
    Q q;
    int64_t res = 0;
    for (int64_t x = 0; x < X; ++x)
    {
        for (IterT it = beg; it != end; ++it)
        {
            q = op(q, *it);
            ++res;
            if (q == v)
                return res;
        }
    }
    return res + 1;
}

template <typename IterT, typename OpT>
int64_t firstQ2(Q v, IterT beg, IterT end, int64_t const X, OpT op)
{
    set<Q> visited;
    Q q;
    int64_t res = 0;
    for (int64_t x = 0; x < X; ++x)
    {
        if (visited.count(q))
            return X * static_cast<int64_t>(end - beg) + 1;
        visited.insert(q);

        for (IterT it = beg; it != end; ++it)
        {
            q = op(q, *it);
            ++res;
            if (q == v)
                return res;
        }
    }
    return res + 1;

    /*
    int64_t const L = end - beg;

    map<Q, int> minFound;
    {
        Q q;
        for (IterT it = beg; it != end; ++it)
        {
            q = op(q, *it);
            if (minFound.count(q) == 0) minFound[q] = it - beg + 1;
        }
    }

    // if (minFound.count(v)) return minFound[v];

    Q const sq = mul2(beg, end, X, op);
    set<Q> visited;
    Q q;
    for (int64_t x = 0; x < X; ++x)
    {
        // TODO: if (visited.count(q)) return X * L;
        visited.insert(q);

        for (auto mf : minFound)
        {
            if (op(q, mf.first) == v)
                return x * L + mf.second;
        }

        q = op(q, sq);
    }
    // TODO: assert(false);
    return false;
    */
}

bool solve1(vector<Q> const & S, int64_t const X)
{
    if (Q(-1) != mul1(S, X))
        return false;
    return firstQ1(Q(I), S.begin(), S.end(), X, mulQ) + firstQ1(Q(K), S.rbegin(), S.rend(), X, mrlQ) < X * static_cast<int64_t>(S.size());
}

bool solve2(vector<Q> const & S, int64_t const X)
{
    assert(mul2(S.begin(), S.end(), X, mulQ) == mul2(S.rbegin(), S.rend(), X, mrlQ));

    if (Q(-1) != mul2(S.begin(), S.end(), X, mulQ))
        return false;

    int64_t const nI = firstQ2(Q(I), S.begin(), S.end(), X, mulQ);
    int64_t const nK = firstQ2(Q(K), S.rbegin(), S.rend(), X, mrlQ);
    // cerr << "! " << s << " X=" << X << " nI=" << nI << " nK=" << nK << endl;

    if (X * S.size() < 1000000000L)
    {
        assert(mul2(S.begin(), S.end(), X, mulQ) == mul1(S, X));
        assert(nI == firstQ1(Q(I), S.begin(), S.end(), X, mulQ));
        assert(nK == firstQ1(Q(K), S.rbegin(), S.rend(), X, mrlQ));
    }

    return nI + nK < X * static_cast<int64_t>(S.size());
}

int main()
{
    assert(Q(I) * Q(J) == Q(K));
    assert(Q(I) * Q(I) == Q(-1));
    assert(Q(I) * Q(-I) == Q(1));

    int caseCount = 0;
    cin >> caseCount;

    for (int i = 0; i < caseCount; ++i)
    {
        int64_t L, X;
        cin >> L >> X >> s;
        assert(s.size() == static_cast<size_t>(L));
        vector<Q> S(s.size());
        for (int j = 0; j < L; ++j)
        {
                 if (s[j] == '1') S[j] = Q(1);
            else if (s[j] == 'i') S[j] = Q(I);
            else if (s[j] == 'j') S[j] = Q(J);
            else if (s[j] == 'k') S[j] = Q(K);
            else assert(false);
        }
        cout << "Case #" << i + 1 << ": " << flush;
        bool const res = solve2(S, X);
        cout << (res ? "YES" : "NO") << endl;

        if (X * S.size() < 1000000000L) assert(res == solve1(S, X));
    }
    return 0;
}

