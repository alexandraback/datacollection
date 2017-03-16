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

int check(int x) {
    bool z[10];
    for (int i = 0; i < 10; i++)
        z[i] = false;
    int cnt = 0;
    for (int i = 1; i <= 1000; i++) {
        int x2 = x*i;
        while (x2 > 0) {
            if (!z[x2%10]) {
                z[x2%10] = true;
                cnt++;
            }
            x2 /= 10;
            
        }
        if (cnt == 10) return x*i;
    }
    return -1;
}

int main() {
    
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int ans = check(x);
        if (ans == -1) cout << "Case #" << i+1 << ": INSOMNIA\n";
        else cout << "Case #" << i+1 << ": " << ans << "\n";
    }
    
   
    return 0;
}