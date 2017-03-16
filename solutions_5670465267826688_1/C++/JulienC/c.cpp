#include <algorithm>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0,nn=static_cast<int>(n);i<nn;i++)
#define REP_R(i,n) for(int i=static_cast<int>(n)-1;i>=0;i--)
#define ALL(v) v.begin(),v.end()
#define ALL_R(v) v.rbegin(),v.rend()
#define SZ(v) static_cast<int>(v.size())
template<typename T> inline T sqr(T a) { return a*a; }

struct Q
{
    enum Sign { P, M } sign;
    enum Value { U, I, J, K } value;
    Q() : sign(P), value(U) {}
    Q(Sign s, Value v) : sign(s), value(v) {}
    Q operator*(const Q& rhs) const
    {
        static const Q product_table[4][4] = {
            { Q(P,U), Q(P,I), Q(P,J), Q(P,K) },
            { Q(P,I), Q(M,U), Q(P,K), Q(M,J) },
            { Q(P,J), Q(M,K), Q(M,U), Q(P,I) },
            { Q(P,K), Q(P,J), Q(M,I), Q(M,U) }};
        Q ret = product_table[value][rhs.value];
        if (sign != rhs.sign) ret.sign = (ret.sign == P) ? M : P;
        return ret;
    }
    bool operator==(const Q& rhs) { return sign==rhs.sign && value==rhs.value; }
    static Q from_char(char c);
    std::string to_string() const;
};

Q Q::from_char(char c)
{
    Q ret;
    switch (c)
    {
        case 'i': ret.value = Q::I; break;
        case 'j': ret.value = Q::J; break;
        case 'k': ret.value = Q::K; break;
        default: assert(false);
    }
    return ret;
}

std::string Q::to_string() const
{
    std::string ret;
    ret += (sign == Q::P) ? '+' : '-';
    switch (value)
    {
        case Q::U: ret += '1'; break;
        case Q::I: ret += 'i'; break;
        case Q::J: ret += 'j'; break;
        case Q::K: ret += 'k'; break;
    }
    return ret;
}

void solve()
{
    int64_t L,X; std::cin >> L >> X;
    std::string strZ; std::cin >> strZ;
    assert(L == SZ(strZ));
    if (X*L < 3) { std::cout << "NO" << std::endl; return; }

    std::vector<Q> Z; REP(i,L) Z.push_back(Q::from_char(strZ[i]));

    Q accZ = std::accumulate(ALL(Z), Q(), std::multiplies<Q>());
    if (accZ == Q()) { std::cout << "NO" << std::endl; return; }
    if (accZ.value == Q::U && X%2==0) { std::cout << "NO" << std::endl; return; }
    if (accZ.value != Q::U && X%2==1) { std::cout << "NO" << std::endl; return; }
    if (accZ.value != Q::U && (X/2)%2==0) { std::cout << "NO" << std::endl; return; }

    if (X > 16) { X = 16 + (X%4); }
    std::vector<Q> seq(X*L);
    REP(i,X) REP(j,L) seq[i*L+j] = Z[j];

    std::vector<Q> accC(X*L);
    accC[X*L-1] = seq[X*L-1];
    REP_R(i,X*L-1) accC[i] = seq[i] * accC[i+1];

    Q a;
    REP(i,X*L-2)
    {
        a = a * seq[i];
        if (a.sign == Q::P && a.value == Q::I)
        {
            Q b;
            for (int j=i+1; j < X*L; j++)
            {
                b = b * seq[j];
                const Q& c = accC[j+1];
                if (b.sign == Q::P && b.value == Q::J &&
                    c.sign == Q::P && c.value == Q::K)
                {
                    std::cout << "YES" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << "NO" << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

