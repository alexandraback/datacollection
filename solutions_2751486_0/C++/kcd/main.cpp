#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <utility>
#include <iomanip>

using namespace std;

typedef long long LL;
template<typename T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<typename T> inline T Sqr(const T& x) { return x * x; }


void Solution() {
    int n;
    string s;
    cin >> s;  
    cin >> n;
    vector<bool> isvowel(256, false);
    isvowel['a'] = true;    
    isvowel['e'] = true;    
    isvowel['o'] = true;    
    isvowel['u'] = true;    
    isvowel['i'] = true;    
    vector<int> a(s.length(), 0);
    for (int i = 0; i < s.length(); ++i) {
        if (!isvowel[s[i]]) {
            a[i] = 1;
        }
    }
    LL ans = 0;
    
    int cur = 0;
    int last = -1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 1) {
            ++cur;
        } else {
            cur = 0;
        }
        if (cur == n) {
            last = i;
            break;
        }
    }
    if (last != -1) {
        for (int i = 0; i < a.size(); ++i) {
            if (cur < n) {
                int ff = last + 1;
                last = -1;
                for (int j = ff; j < a.size(); ++j) {
                    if (a[j]) {
                        ++cur;
                    } else {
                        cur = 0;
                    }
                    if (cur == n) {
                        last = j;
                        break;
                    }
                }
                if (last == -1) {
                    goto end;
                }
            }
            ans += a.size() - last;
            if (last - i + 1 == n) {
                --cur;
            }
        }
    }
    end:
    cout << ans << endl;
}


struct Timer {
    map<string, float> starts;
    void Tic(const string& name) { starts[name] = clock(); }
    float Toc(const string& name) { return (clock() - starts[name]) / CLOCKS_PER_SEC; }
} timer;

int main(int argc, char* argv[]) {
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);

    timer.Tic("global");
    int testsNumber;
    cin >> testsNumber;
    for (int curTest = 1; curTest <= testsNumber; ++curTest) {
        cout << "Case #" << curTest << ": ";
        cerr << "Case #" << setw(2) << setfill('0') << curTest << ": running...";
        timer.Tic("test");
        Solution();
        cerr << "done! Elapsed time is " << setprecision(3) << timer.Toc("test") << endl;
    }
    cerr << endl << "Total elapsed time is " << setprecision(3) << timer.Toc("global") << endl;

    return 0;
}
