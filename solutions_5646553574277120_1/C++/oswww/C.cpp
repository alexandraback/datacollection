#define OSW2

#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;




int main() {
#ifdef OSW
    freopen("//Users//osw//Desktop//in.txt", "r", stdin);
#endif
#ifdef OSW2
    string file_name = "C-large";
    freopen(("//Users//osw//Downloads//" + file_name + ".in").c_str(), "r", stdin);
    freopen(("//Users//osw//Downloads//" + file_name + ".out").c_str(), "w", stdout);
#endif
    
    int T, t = 0;
    cin >> T;

    while (T - (t++)) {
        long long C, D, V;
        cin >> C >> D >> V;
        vector<long long> v;
        for(int i = 0; i < D; ++i) {
            int a; cin >> a;
            v.push_back(a);
        }
        
        sort(v.begin(), v.end());

        long long MAX = 0;
        int cnt = 0;

        for (auto x:v) {
            if (MAX>=V) break;
            while (x > MAX+1) {
                ++cnt;
                long long mian = MAX+1;
                MAX += mian * C;
            }
            MAX += x * C;
        }
        while (V > MAX) {
            ++cnt;
            long long mian = MAX+1;
            MAX += mian * C;
        }

        
        cout << "Case #" << t << ": ";
        cout << cnt << endl;
    }
}



