#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <complex>
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
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <sstream>

using namespace std;


vector<string> getLineFields(istream& stream) {
    string line;
    getline(stream, line);
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

int solve(const vector<int>& v, int R, int cur, int e, int ee) {
    if (cur == v.size()) return 0;
    
    int mx = 0;
    for (int i = 0; i <= e; ++i) {
        mx = max(mx, v[cur] * i + solve(v, R, cur + 1, min(ee, e - i + R), ee));
    }
    return mx;
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int e, r, n;
        cin >> e >> r >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        
        cout << "Case #" << t + 1 << ": " << solve(v, r, 0, e, e) << endl;

    }
}
