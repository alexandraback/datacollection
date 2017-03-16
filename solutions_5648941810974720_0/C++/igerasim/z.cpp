#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <hash_map>
#include <string>
#include <map>
#include <set>
#include <queue>

#if 0
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
typedef int256_t lll;
typedef uint256_t ulll;
#endif

using namespace std;
using namespace std::tr1;
using namespace stdext;

typedef __int64 ll;
typedef unsigned __int64 ull;

int T;
char S[3000];

void er(string& s, const char* it1) {
    int cnt = strlen(it1);
    while (cnt > 0) {
        unsigned pos = s.find(*it1);
        if (pos == string::npos) throw int(42);
        s.erase(pos, 1);
        ++it1; --cnt;
    }
}

int main(int argc, char* argv[]) {
    cin >> T; cin.getline(S, 2999);
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << (t + 1) << ": ";
        cin.getline(S, 2999);
        string s(S);
        vector<int> d;

        while (!s.empty()) {
            if (s.find('Z') != string::npos) {
                d.push_back(0);
                er(s, "ZERO");
                continue;
            }
            if (s.find('X') != string::npos) {
                d.push_back(6);
                er(s, "SIX");
                continue;
            }
            if (s.find('W') != string::npos) {
                d.push_back(2);
                er(s, "TWO");
                continue;
            }
            if (s.find('G') != string::npos) {
                d.push_back(8);
                er(s, "EIGHT");
                continue;
            }
            if (s.find('H') != string::npos) {
                d.push_back(3);
                er(s, "THREE");
                continue;
            }
            if (s.find('R') != string::npos) {
                d.push_back(4);
                er(s, "FOUR");
                continue;
            }
            if (s.find('O') != string::npos) {
                d.push_back(1);
                er(s, "ONE");
                continue;
            }
            if (s.find('F') != string::npos) {
                d.push_back(5);
                er(s, "FIVE");
                continue;
            }
            if (s.find('S') != string::npos) {
                d.push_back(7);
                er(s, "SEVEN");
                continue;
            }
            
            if (s.find('N') != string::npos) {
                d.push_back(9);
                er(s, "NINE");
                continue;
            }
            throw int(43);
        }
        sort(d.begin(), d.end());
        for (int i = 0; i != d.size(); ++i) {
            cout << d[i];
        }
        cout << "\n";
    }
    return 0;
}
