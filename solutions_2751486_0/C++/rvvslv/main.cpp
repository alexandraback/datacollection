#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() {
    ifstream cin("/Users/mac/topcoder/input.txt");
    ofstream cout("/Users/mac/topcoder/output.txt");
    
    int NT;
    cin >> NT;
    
    string vowels = "aeiou";
    
    for (int CT = 0; CT < NT; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        string s;
        int n;
        cin >> s >> n;
        
        int l = 0;
        vector<int> ends;
        for (int i = 0; i < s.size(); i ++) {
            if (vowels.find(s[i]) == -1) {
                l ++;
                if (l >= n)
                    ends.push_back(i);
            } else
                l = 0;
        }
    
        long long res = 0;
        for (int i = 0; i < s.size(); i ++) {
            auto lower = lower_bound(ends.begin(), ends.end(), i + n - 1);
            if (lower != ends.end())
                res += s.size() - *lower;
        }
        
        cout << res << endl;
    }
    
    return 0;
} 
