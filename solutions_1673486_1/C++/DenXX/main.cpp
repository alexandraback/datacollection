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
    int a, b;
    cin >> a >> b;
    vector<double> p(a);
    vector<double> correct(a);
    for (int i = 0; i < a; ++i) {
        cin >> p[i];
        correct[i] = (i > 0 ? correct[i-1] : 1) * p[i];
    }
    
    double res = 2 + b;
    
    res = min(res, (b - a + 1) * correct[a-1] + (2*b - a + 2) * (1 - correct[a-1]));
    for (int i = 1; i < a; ++i) {
        res = min(res, (2*i + (b - a) + 1) * correct[a - i - 1] + (2*i + (2*b - a) + 2) * (1 - correct[a - i - 1]));
    }
    
    cout << res;
}

int main()
{
    int T;
    cin >> T;
    cout.precision(10);
    cout.setf(ios::fixed,ios::floatfield);
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        solve();
        cout << endl;
    }
}
