#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl; 

int main()
{
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";

        int max_shyness;
        string s;
        cin >> max_shyness >> s;
        for (int i = 0; i <= max_shyness; ++i) {
          s[i] -= '0';
        } 
        
        int num_friends = 0;
        int num_clapping_people = 0;
        for (int i = 0; i <= max_shyness; ++i) {
          if (!s[i]) continue;
          int shortage = max(0, i - num_clapping_people);
          num_friends += shortage;
          num_clapping_people += shortage + s[i];
        }

        cout << num_friends;

        cout << endl;
    }
    return 0;
}
