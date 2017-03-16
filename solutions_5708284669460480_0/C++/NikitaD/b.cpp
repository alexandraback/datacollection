#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>

#include <iostream>
#include <iomanip>
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
typedef long double ld;

template <class T> inline T sqr(const T& a) { return a * a; }
template <class T> inline void updMin(T& a, const T& b) { if (b < a) a = b; }
template <class T> inline void updMax(T& a, const T& b) { if (b > a) a = b; }

const int maxn = 100 + 10;

ld d[maxn][maxn][maxn];
int cnt[26];
int to[maxn][26];



void solution()
{

    memset(d, 0, sizeof(d));
    memset(cnt, 0, sizeof(cnt));
    memset(to, 0, sizeof(to));


    int k, l, s;
    cin >> k >> l >> s;

    string buf;
    getline(cin, buf);

    string keyboard, target;
    getline(cin, keyboard);
    getline(cin, target);


    for (int i = 0; i < keyboard.length(); ++i)
        ++cnt[keyboard[i] - 'A'];

    for (int k = 0; k <= target.length(); ++k)
    {
        //cout << "k = " << k << ":" << endl;

        for (int C = 0; C < 26; ++C)
        {
            string s = target.substr(0, k) + char(C + 'A');
            //cout << s << endl;
            for (int j = k + 1; j > 0; --j)
            {
                //cout << "here : ";
                //cout << s.length() - j << " " << j << "   " << s.length() << endl;
                
                ///cout << "WOW:" << endl;
                //cout << target << endl;
                //cout << target.substr(0, j) << endl;
                //cout << s.substr(s.length() - j, j) << endl;
                //cout << "END" << endl;

                if (j > target.length())
                    continue;
                if (target.substr(0, j) == s.substr(s.length() - j, j))
                {
                    to[k][C] = j;
                    break;
                }
            }

        }
    }



    /*for (int k = 0; k <= target.length(); ++k)
    {
        int C = 0;
        cout << "to[" << k << "][" << C << "] = " << to[k][C] << endl;
    }
    cout << endl;*/

    d[0][0][0] = 1;


    for (int i = 0; i < s; ++i)
    {
        for (int k = 0; k <= i; ++k)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (!d[i][k][j])
                    continue;

                for (int C = 0; C < 26; ++C)
                {
                    int nxt = to[k][C];
                    d[i + 1][nxt][j + int(nxt == target.length())] += cnt[C] * d[i][k][j];
                }

            }
        }
    }

    cout << fixed << setprecision(10);


    ld sum = 0;
    int maxJ = 0;

    for (int k = 0; k <= target.length(); ++k)
        for (int j = 0; j <= s; ++j)
        {
            sum += d[s][k][j];
            if (d[s][k][j] > 0)
            {
                maxJ = j;
                //cout << "$" << d[s][k][j] << endl;
            }
        }

    //cout << "sum = " << sum << ";" << endl;
    
    ld ans = 0;
    for (int k = 0; k <= target.length(); ++k)
        for (int j = 0; j <= s; ++j)
            ans += j * d[s][k][j] / sum;


    cout << maxJ - ans;

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

        cerr << "Case #" << test << ", time: " << fixed << setprecision(2) << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    }



    return 0;
}
