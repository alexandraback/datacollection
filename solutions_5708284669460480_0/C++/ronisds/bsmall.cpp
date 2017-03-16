#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <limits>
#include <iomanip>

#define INF 1000000000
#define Inf 1000000000000000000
#define mp make_pair
#define pb push_back
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vector<pair<string,int> > vec;
vector<char> letters;
int lettersCount[26];
string a,b,c;
int t,k,l,s, maxX;
void generate() {
    if (c.size() == s) {
        int x = 0;
        for(int i = 0; i <= c.size() - b.size(); ++i) {
            bool equal = true;
            for(int j = 0; j < b.size(); ++j) {
                if (c[i + j] != b[j]) {
                    equal = false;
                    break;
                }
            }
            if (equal) ++x;
        }
        maxX = max(maxX, x);
        vec.pb(mp(c,x));
        return;
    }
    for(int i = 0; i < letters.size(); ++i) {
        c.pb(letters[i]);
        generate();
        c.pop_back();
    }
}

int main() {
    //freopen("in","r",stdin);
    //freopen("out", "w", stdout);
    cin >> t;
    for(int cas = 1; cas <= t; ++cas)
    {
        vec.clear();
        memset(lettersCount,0,sizeof(lettersCount));
        letters.clear();
        maxX = 0;
        cin >> k >> l >> s;
        cin >> a >> b;
        for(int i = 0; i < a.size(); ++i)
            lettersCount[a[i] - 'A']++;
        for(int i = 0; i < 26; ++i)
            if (lettersCount[i])
                letters.pb((char)('A' + i));
        generate();
        double expected = (double)maxX;
        for(int i = 0; i < vec.size(); ++i)
        {
            double aux = 1.0;
            for(int j = 0; j < vec[i].first.size(); ++j) {
                aux *= (double)lettersCount[vec[i].first[j] - 'A'] / (double)a.size();
            }
            expected -= (aux) * (double)vec[i].second;
        }
        printf("Case #%d: %lf\n",cas, expected);
    }
    return 0;
}
