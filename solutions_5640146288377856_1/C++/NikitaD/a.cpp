#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> inline T sqr(const T& a) { return a * a; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }





void solution()
{
    int r, c, w;
    cin >> r >> c >> w;
    //if (r == 1)
    //{
    int ans = (c / w) * r + w - 1 + (c % w ? 1 : 0);
    cout << ans;
    //}

}



int main()
{
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);


    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; ++test)
    {
        cout << "Case #" << test << ": ";
        solution();
        cout << "\n";
    }



    return 0;
}
