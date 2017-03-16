#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

int n, m;
string key, word;
long double ans;
int cnt[256];

int main()
{
    freopen("B-small-attempt0.in.txt", "r", stdin);
    freopen("B-small-attempt0.out.txt", "w", stdout);
    //freopen("B-large.in.txt", "r", stdin);
    //freopen("B-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        memset(cnt, 0, sizeof(cnt));
        cin >> n >> n >> n >> key >> word;
        for (int i = 0; key[i]; ++cnt[key[i++]]);
        long double p = 1;
        for (int i = 0; word[i]; p *= ((long double)cnt[word[i++]])/key.size());
        if (p > 0)
        {
            for (m = 1; word[m] && word.substr(m) != word.substr(0, word.size()-m); ++m);
            ans = (n-word.size())/m+1-p*(n-word.size()+1);
        }
        else
            ans = 0;
        cout << setprecision(20) << fixed << "Case #" << Test << ": " << ans << endl;
    }
    return 0;
}
