#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int tmp = 0;

int main() {
    freopen("/Users/clsrn1581/Desktop/codejam/A/A-small-attempt0.in", "r", stdin);
    freopen("/Users/clsrn1581/Desktop/codejam/A/A-small-attempt0.out", "w", stdout);
    
    int T;
    cin >> T;
    
    for(int t = 1; t <= T; t++){
        vector<int> ans;
        string str;
        cin >> str;
        
        int ck[26];
        for(int i = 0 ; i < 26; i++)
            ck[i] = 0;
        
        for(int i = 0 ; i < str.length() ; i++)
            ck[str[i]-'A']++;
        
        //ZERO
        tmp = ck['Z'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(0);
        ck['Z'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        ck['R'-'A'] -= tmp;
        ck['O'-'A'] -= tmp;
        
        //TWO
        tmp = ck['W'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(2);
        ck['T'-'A'] -= tmp;
        ck['W'-'A'] -= tmp;
        ck['O'-'A'] -= tmp;
        
        //FOUR
        tmp = ck['U'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(4);
        ck['F'-'A'] -= tmp;
        ck['O'-'A'] -= tmp;
        ck['U'-'A'] -= tmp;
        ck['R'-'A'] -= tmp;
        
        
        //SIX
        tmp = ck['X'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(6);
        ck['S'-'A'] -= tmp;
        ck['I'-'A'] -= tmp;
        ck['X'-'A'] -= tmp;
        
        //EIGHT
        tmp = ck['G'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(8);
        ck['E'-'A'] -= tmp;
        ck['I'-'A'] -= tmp;
        ck['G'-'A'] -= tmp;
        ck['H'-'A'] -= tmp;
        ck['T'-'A'] -= tmp;
        
        //THREE
        tmp = ck['H'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(3);
        ck['T'-'A'] -= tmp;
        ck['H'-'A'] -= tmp;
        ck['R'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        
        //FIVE
        tmp = ck['F'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(5);
        ck['F'-'A'] -= tmp;
        ck['I'-'A'] -= tmp;
        ck['V'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        
        //NINE
        tmp = ck['I'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(9);
        ck['N'-'A'] -= tmp;
        ck['I'-'A'] -= tmp;
        ck['N'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        
        //ONE
        tmp = ck['O'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(1);
        ck['O'-'A'] -= tmp;
        ck['N'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        
        //SEVEN
        tmp = ck['V'-'A'];
        for(int i = 0 ; i < tmp ; i++)
            ans.push_back(7);
        ck['S'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        ck['V'-'A'] -= tmp;
        ck['E'-'A'] -= tmp;
        ck['N'-'A'] -= tmp;

        sort(ans.begin(), ans.end());
        
        printf("Case #%d: ", t);
        for(int i = 0 ; i < ans.size(); i++){
            cout << ans[i];
        }
        cout << endl;
    }
    
    return 0;
}
