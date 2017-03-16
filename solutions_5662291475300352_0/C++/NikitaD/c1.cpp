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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef unsigned uint;

template <class T> inline T sqr(const T& a) { return a * a; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }




void solution()
{

    vector <pii> hikers;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ll d, h, m;
        cin >> d >> h >> m;
        for (int j = 0; j < h; ++j)
        {
            hikers.push_back(make_pair(d, m + j));
        }
    }

    if (hikers.size() < 2)
    {
        cout << 0;
        return;
    }

    if (hikers.size() == 2)
    {
        if (hikers[1].second > hikers[0].second)
            swap(hikers[0], hikers[1]);


        /*if (hikers[1].first > hikers[0].first)
        {
            int dist = 360 - hikers[1].first + hikers[0].first;
            
            //cout << "dist = " << dist << endl;
            //cout << "hikers[0]: " << hikers[0].first << " " << hikers[0].second << endl;
            //cout << "hikers[1]: " << hikers[1].first << " " << hikers[1].second << endl;

            //if ((360 - hikers[0].first) * hikers[0].second < dist * hikers[1].second)
            if ((360 - hikers[0].first) * hikers[0].second < (2 * 360 - hikers[1].first) * hikers[1].second)
            {
                cout << 0;
            }
            else
            {
                cout << 1;
            }
        }
        else
        {*/

        if ((2 * 360 - hikers[1].first) * hikers[1].second > (360 - hikers[0].first) * hikers[0].second)
        {
            cout << 0;
        }
        else
        {
            cout << 1;
        }

        //}

    }

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
