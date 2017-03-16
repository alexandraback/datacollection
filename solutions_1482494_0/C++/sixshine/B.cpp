#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <list>
#include <functional>
#include <utility>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h);i>(l);--i)
#define MAX(a,b) ((a)>(b)?(a):(b))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef multiset<int> MSI;
typedef long long LL;
typedef pair<int, int> PII;

bool comp(const PII &S1, const PII &S2) {
    if (S1.second > S2.second) {
        return true;
    }
    if ((S1.second == S2.second) && (S1.first < S2.first)) {
        return true;
    }
    return false;
}

int main() {
    ifstream cin("D:\\in.txt");
    ofstream cout("D:\\out.txt");
//    freopen("D:\\in.txt", "r", stdin);
//    freopen("D:\\out.txt", "w", stdout);
    int T, N;
    cin >> T;
    REP(i,T) {
        cin >> N;
        vector<PII> S(N);
        REP(j, N) {
            cin >> S[j].first >> S[j].second;
        }
        sort(S.begin(), S.end(), comp);
        VI OneCount(N * 2 + 2);
        bool TooBad = false;
        MSI OneSet;
        MSI OneUsed;
        REP(j, N) {
            OneSet.insert(S[j].first);
            int Havegot = (N - j - 1) * 2;
            if (S[j].second > Havegot) {
                int star = S[j].second;
                MSI::reverse_iterator itor;
                for (itor = OneUsed.rbegin(); itor != OneUsed.rend(); itor++) {
                    if (*itor < star) {
                        star--;
                    }
                }
                while (star > Havegot && !OneSet.empty()) {
                    if (*OneSet.begin() < star) {
                        OneUsed.insert(*(OneSet.begin()));
                        OneSet.erase(OneSet.begin());
                        star--;
                    } else {
                        break;
                    }
                }
                if (star > Havegot) {
                    TooBad = true;
                    break;
                }
            }
        }
        if (TooBad) {
            cout << "Case #" << i + 1 << ": Too Bad" << endl;
        } else {
            cout << "Case #" << i + 1 << ": " << N + OneUsed.size() << endl;
        }
    }
    return 0;
}
