#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
using namespace std;

long long gcd(long long u, long long v)
{
    return (v != 0) ? gcd(v, u % v) : u;
}

int Solve(long long p, long long q, bool flag)
{
    if(flag) {
        //big
        long long i = gcd(p, q);
        p = p / i;
        q = q / i;
    }

    if (q % 2 == 1) {
        return -1;
    }

    bitset<64> bp(p);
    bitset<64> bq(q);

    if(bq.count() > 1) {
        return -1;
    }

    string sp = bp.to_string<char,std::string::traits_type,std::string::allocator_type>();
    string sq = bq.to_string<char,std::string::traits_type,std::string::allocator_type>();

    string::size_type ip = sp.find_first_of("1");
    string::size_type iq = sq.find_first_of("1");
    return ip - iq;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        long long P, Q;
        string tmp;
        cin >> tmp;
        string::size_type pos = tmp.find("/");
        //cout << tmp.substr(pos + 1) << endl;
        //cout << tmp.substr(0, pos) << endl;
        Q = stoll(tmp.substr(pos + 1));
        P = stoll(tmp.substr(0, pos));

        cout << "Case #" << i + 1 << ": ";

        int ret = Solve(P, Q, false);
        if (ret == -1) {
            cout << "impossible" << endl;
        } else {
            cout <<  ret << endl;
        }
    }
    return 0;
}