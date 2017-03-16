#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <vector>

#define mp make_pair
#define ll long long
#define pb push_back

using namespace std;

int main() {
    
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int ans = 0;
        for (int j = 0; j < s.length()-1; j++)
            if (s[j] != s[j+1]) ans++;
        if (s[s.length()-1] == '-') ans++;
        cout << "Case #" << i+1 << ": " << ans << "\n";
    }
    
    
    
   
    return 0;
}