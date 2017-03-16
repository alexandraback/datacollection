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

bool gen(vector<int>& d, int m) {
    for (int i = 0; i < d.size(); ++i) {
        if (d[i] < m) {
            ++d[i];
            return true;
        }
        d[i] = 2;
    }
    return false;
}

bool check(const vector<int>& d, const set<int>& p) {
    set<int> prods(p.begin(), p.end());
    for (int i = 0; i < 1 << d.size(); ++i) {
        int prod = 1;
        for (int j = 0; j < d.size(); ++j) {
            if (i & (1 << j))
                prod *= d[j];
        }
        prods.erase(prod);
    }
    return prods.empty();
}

string solve(int n, int m, int k) {
    set<int> prods;
    for (int i = 0; i < k; ++i) {
        int tmp;
        cin >> tmp;
        prods.insert(tmp);
    }
    
    vector<int> d(n, 2);
    vector<string> sol;
    do {
        if (check(d, prods)) {
            string res = "";
            for (int i = 0; i < n; ++i)
                res += (d[i] + '0');
            sol.push_back(res);
        }
    }
    while (gen(d, m));
    
    
    return sol[0];
}


int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int r;
        cin >> r;
        int n, m, k;        
        cin >> n >> m >> k;
        cout << "Case #" << t + 1 << ":" << endl;
        for (int i = 0; i < r; ++i) {
            cout << solve(n, m, k) << endl;
        }

    }
}
