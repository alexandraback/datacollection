#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    for (int T = 1; T <= t; T++) {
        int n;
        cin >> n;
        
        vector<pair<string, string> > v;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            v.push_back(make_pair(s1, s2));
        }
        
        int i;
        int globalRes = 0;
        for (i = 2<<(n+1)-1; i >= 0; i--) {
            vector <pair<string, string> > faked;
            set <string> notFaked1;
            set <string> notFaked2;
            
            int tmp = i;
            for (int j = 0; j < n; j++) {
                if (tmp % 2 == 0) {
                    faked.push_back(v[j]);
                }
                else {
                    notFaked1.insert(v[j].first);
                    notFaked2.insert(v[j].second);
                }
                tmp /= 2;
            }
            bool res = true;
            for (int j = 0; j < faked.size(); j++) {
                if (notFaked1.count(faked[j].first) == 0)
                    res = false;
                if (notFaked2.count(faked[j].second) == 0)
                    res = false;
            }
            
            if (res && faked.size() > globalRes)
                globalRes = faked.size();
        }
        
        cout << "Case #" << T << ": " << globalRes << "\n";
    }
    
    return 0;
}
