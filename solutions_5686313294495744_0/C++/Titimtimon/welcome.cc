#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

#define mp make_pair
#define ll long long
#define pb push_back

using namespace std;
map<string,int> m1;
map<string,int> m2;
pair <string,string> a[1100];
bool vis[1100];

int main() {
    
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    for (int i1 = 0; i1 < n; i1++) {
        int cnt = 0;
        int x;
        cin >> x; 
        for (int j = 0; j < x; j++) {
            string s1;
            string s2;

            cin >>a[j].first >> a[j].second;
            m1[a[j].first]++;
            m2[a[j].second]++;

            
        }
        
        int ans = 0;
        for (int i = 0; i < (1<<x); i++) {
            bool z = true;
            int cnt = 0;
            for (int j = 0; j < x; j++)
                if ((i & (1<<j)) > 0) {
                    cnt ++;
                    
                    bool z1 = false;
                    bool z2 = false;
                    for (int k = 0; k < x; k ++) {
                        if (((i & (1<<k)) == 0) && a[j].first == a[k].first) z1 = true;
                        if (((i & (1<<k)) == 0) && a[j].second == a[k].second) z2 = true;
                    }
                    if (!z1 || !z2 ) z = false;
                }
//            cout << cnt << " " << z << "\n";
            if (z) ans = max(ans,cnt);
        }
            
        cout << "Case #" << i1+1 <<": " << ans << "\n";
    }
    
    

    
    
    return 0;
}