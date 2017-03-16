#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <list>
#include <stack>
#include <numeric>
#include <queue>
#include <algorithm>
#include <functional>
#include <stack>
#include <bitset>
#include <map>
#include <list>
#include <math.h>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <sstream>

#define vvvvi(T) vector<vector<vector<vector<T> > > >
#define vvvi(T) vector<vector<vector<T> > >
#define vvi(T) vector<vector<T> >

using namespace std;

string getLine(istream& stream) {
    string res;
    getline(stream, res);
    return res;
}

vector<string> getLineFields(istream& stream) {
    string line = getLine(stream);
    stringstream str;
    str << line;
    vector<string> fields;
    string temp;
    while(str>>temp)
    {
        fields.push_back(temp);
    }
    return fields;
}

template <typename T>
T str2type(string a) {
    stringstream t;
    t << a;
    T b;
    t >> b;
    return b;
}

void solve() {
    int n;
    cin >> n;
    vector< pair<int, int> > one(n);
    vector< pair<int, int> > two(n);
    vector<int> tt(n);
    vector<bool> done2(n, false);
    vector<bool> done1(n, false);    
    for (int i = 0; i < n; ++i) {
        one[i].second = i;
        two[i].second = i;
        cin >> one[i].first;
        cin >> two[i].first;
        tt[i] = two[i].first;
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    
    int res = 0;
    int stars = 0;
    int curt = 0;
    int curo = 0;
    bool ok = true;
    while (curt < n && ok) {
        ok = false;
        if (two[curt].first <= stars) {
            stars += (done1[two[curt].second] ? 1 : 2);
            done2[two[curt].second] = true;
            ++res;
            ++curt;
            ok = true;
        }
        else {
            while (curo < n && done2[one[curo].second]) ++curo;
            int j = curo;
            int maxt = numeric_limits<int>::min();
            int bestj = -1;
            while (j < n && one[j].first <= stars) {
                if (!done1[one[j].second] && !done2[one[j].second] && tt[one[j].second] > maxt) {
                    bestj = j;
                    maxt = tt[one[j].second];
                }
                ++j;
            }
            if (bestj > -1) {
                stars += 1;             
                done1[one[bestj].second] = true;
                ++res;
                ok = true;                
            }
        }
    }
    if (!ok) cout << "Too Bad";
    else cout << res;
}

int main()
{
    int T;
    cin >> T;
    //cout.precision(10);
    //cout.setf(ios::fixed,ios::floatfield);
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        solve();
        cout << endl;
    }
}
