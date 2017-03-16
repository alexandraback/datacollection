#include <cstdlib>
#include <bitset>
#include <functional>
#include <utility>
#include <tuple>
#include <limits>
#include <cstdint>
#include <cctype>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <random>
#include <numeric>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> words1, words2;
int n;

int rec(int mask){
    unordered_set<string> first, second;
    int orig = 0;
    for(int bit = 1, cnt = 0; bit < (1 << n); bit <<= 1, ++cnt){
        if(mask & bit){
            first.insert(words1[cnt]);
            second.insert(words2[cnt]);
            ++orig;
        }
    }

    bool ok = true;
    for(int bit = 1, cnt = 0; bit < (1 << n); bit <<= 1, ++cnt){
        if(!(mask & bit)){
            if(first.count(words1[cnt]) == 0 || second.count(words2[cnt]) == 0){
                ok = false;
                break;
            }
        }
    }
    return ok? n-orig : 0;
}

void comp(int tc){
    cin >> n;
    words1.resize(n);
    words2.resize(n);
    for(int i=0; i<n; ++i){
        cin >> words1[i] >> words2[i];
    }

    int best = 0;

    for(int mask=1; mask<(1<<n); ++mask){
        best = max(best, rec(mask));
    }

    cout << "Case #" << tc << ": " << best << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}