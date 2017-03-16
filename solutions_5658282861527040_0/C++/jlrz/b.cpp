#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <memory>
#include <cassert>
#include <set>
#include <numeric>

using namespace std;

#define MAPITR(a,b) map<a,b>::iterator
#define LISTITR(a)  list<a>::iterator

#define ITER(itr,a)   for( itr = (a).begin(); itr != (a).end(); ++itr )
#define ITERNI(itr,a) for( itr = (a).begin(); itr != (a).end();  )
#define FORI(i,a,b)   for( int i(a), _b(b); i < _b; ++i )
#define FORD(i,a,b)   for( int i(a), _b(b); i > _b; --i )
#define FORLE(i,a,b)  for( int i(a), _b(b); i <= _b; ++i )
#define FORGE(i,a,b)  for( int i(a), _b(b); i >= _b; --i )

#define DISCARD_LINE  { char buf[32]; cin.getline(buf, 32); }

using dword = unsigned int;
using qword = unsigned long long;

using lb = list<bool>;
using lc = list<char>;
using li = list<int>;
using ld = list<double>;
using ls = list<string>;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;

using vdw = vector<dword>;
using vqw = vector<qword>;

template <class T>
inline auto XY(T& a, size_t x, size_t y, size_t width) -> decltype(a[y*width + x]) { return a[y*width + x]; };
//////////////////////////////////////////////////////////////////////////////////////////////////////

int find_num_bits(dword num)
{
    int i = 0;

    while (num >= (1 << i))
    {
        ++i;

        assert(i < 32);
    }

    return i;
}

void process()
{
    dword A, B, K;

    cin >> A;
    cin >> B;
    cin >> K;

    int numBitsA, numBitsB, numBitsK;

    numBitsA = find_num_bits(A-1);
    numBitsB = find_num_bits(B-1);
    numBitsK = find_num_bits(K-1);

    qword sum = 0;
/*
    auto num_statisfied_bits_a = min(numBitsK, numBitsA) - 1;
    auto num_statisfied_bits_b = min(numBitsK, numBitsB) - 1;

    auto sumA = (1 << num_statisfied_bits_a);

    auto diffA = A >= K ? A - K : K - A;

    diffA = diffA >> num_statisfied_bits_a;

    sumA *= diffA;

    auto sumB = (1 << num_statisfied_bits_b);

    auto diffB = B >= K ? B - K : K - B;

    diffB = diffB >> num_statisfied_bits_b;

    sumB *= diffB;
*/
    FORI(a, 0, A)
    {
        FORI(b, 0, B)
        {
            if ((a & b) < K)
            {
                sum += 1;
            }
        }
    }

    cout << sum;
}

int main()
{
    int nCases;
    cin >> nCases;

    FORLE(i, 1, nCases)
    {
        cout << "Case #" << i << ": ";

        process();

        cout << endl;
    }

    return 0;
}