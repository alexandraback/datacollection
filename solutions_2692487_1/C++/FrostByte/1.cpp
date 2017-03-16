#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <sstream>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

#define fo(a,b,c) for(a = (b); a < (c); a++)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define fn fr
#define forit(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)

using namespace std;

template <class T> T abs(T x) { return x < 0 ? -x : x; }
template <class T> inline string to_str(const T& x) { ostringstream s(""); s << x; return s.str(); }

const long double PI = acos(-1.0);

typedef long long ll;
typedef unsigned long long ull;

vector<long> v;

int do_thing(vector<long> v, int steps, long long z);

int put(vector<long> v, int steps, long long z)
{
    if(z == 1) return v.size();

    while(z <= v[0])
    {
        z += z - 1;
        // cout << "New size " << z << endl;
        steps++;
    }

    return do_thing(v, steps, z);
}

int do_thing(vector<long> v, int steps, long long z)
{
    forit(it, v)
    {
        if(z > *it)
        {
            // cout << "Eating " << *it << endl;
            z += *it;
            it = v.erase(it) - 1;
        }
        else 
            break;
    }

    if(v.empty()) return steps;

    // cout << "Remaining " << v.size() << endl;
    return min(put(v, steps, z), steps + (int) v.size());
}

int main()
{
    int i, t, tt;
    int n, a, b;
    long x;
    long long size;

    cin >> tt;

    for(t=1; t<=tt; t++)
    {
        v.clear();

        size = 0;

        cin >> size >> n;

        fi(n)
        {
            cin >> x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());

        printf("Case #%d: ", t);
        cout << do_thing(v, 0, size);
        printf("\n");
    }

    return 0;
}



