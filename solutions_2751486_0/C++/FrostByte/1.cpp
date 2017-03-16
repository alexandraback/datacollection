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

string s, str; 
int n, l;

vector<int> v;

int consonants(string s)
{
    int N = s.length();
    int i, x = 0;
    int current = 0, best = 0;

    fi(N)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            if(current > best) 
            {
                best = current;
            }
            current = 0;
        }
        else current++;
    }

    if(current > best) 
        best = current;

    return best;
}

int do_thing(int n)
{
    int i, j, k, c;
    int max = 0;

    fi(l)
    {
        for(j=i; j<l; j++)
        {
            if(j-i+1 < n)
                continue;

            str = s.substr(i, j-i+1);
            c = consonants(str); 
            if(c >= n)
            {
                max++;
            }
        }
    }
    return max;
}

int main()
{
    int i, t, tt;
    int n, a, b, x;

    cin >> tt;

    for(t=1; t<=tt; t++)
    {
        cin >> s >> n;
        l = s.length();

        printf("Case #%d: ", t);
        cout << do_thing(n);
        printf("\n");
    }

    return 0;
}



