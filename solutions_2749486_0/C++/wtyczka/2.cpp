#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <ctime>
typedef long long LL;
typedef long double LD;
#define REP(i, n) for (LL i = 0; i < (n); i++)
#define REPF(i, m, n) for (LL i = m; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
#define GETLL(a) scanf("%lld", &a);
#define GETLL2(a, b) scanf("%lld%lld", &a, &b);


template<typename T, long long size = 100010>
class Memory {
public:
    Memory() : _allocated(0) {
        fill(&_data[0], &_data[size], T());
    }

    T *alloc() {
        return &_data[_allocated++];
    }

    T *getNew() {
        T *mem = alloc();
        return new (mem) T();
    }

    T &newRef() {
        return *getNew();
    }

    void clean() {
        fill(&_data[0], &_data[_allocated], T());
        _allocated = 0;
    }

private:
    T _data[size];
    long long _allocated;
};


inline bool vowel(char letter)
{
    return (letter == 'a') || (letter == 'e') || (letter == 'i') ||
           (letter == 'o') || (letter == 'u');
}

template<typename T>
inline T sq(T a, T b) { return a * b; }


int main()
{
    ios_base::sync_with_stdio(false);

    LL t;
    cin >> t;

    string st;

    REP(i, t) {

        LL x, y;
        cin >> x >> y;

        cout << "Case #" << i + 1 << ": ";

        if (x > 0) {
            REP(j, abs(x)) cout << "WE";
        } else {
            REP(j, abs(x)) cout << "EW";
        }

        if (y > 0) {
            REP(j, abs(y)) cout << "SN";
        } else {
            REP(j, abs(y)) cout << "NS";
        }

        cout << endl;
    }
}

