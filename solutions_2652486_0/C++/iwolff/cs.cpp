#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

int main() {
    int nt,nteste=1;
    int r,n,m,k,d,ok[10],us[150],flag;
    string ans;
    vector<int> v;
    
    srand(time(NULL));
    cin>>nt;
    while (nt--) {
        cin>>r>>n>>m>>k;
        printf("Case #%d:\n",nteste++);
        while (r--) {
            ans.clear();
            v.clear();
            flag = 0;
            memset(ok,0,sizeof(ok));
            memset(us,0,sizeof(us));
            for (int z=0; z<k; z++) {
                cin>>d;
                v.push_back(d);
                us[d] = 1;
            }
            
            for (int z=0; z<k; z++) {
                d = v[z];
                if (d == 27) { ans = "333"; flag = 1; break; }
                if (d == 36) { ans = "334"; flag = 1; break; }
                if (d == 18) { ans = "332"; flag = 1; break; }
                if (d == 45) { ans = "335"; flag = 1; break; }
                if (d == 32) { ans = "442"; flag = 1; break; }
                if (d == 48) { ans = "443"; flag = 1; break; }
                if (d == 64) { ans = "444"; flag = 1; break; }
                if (d == 80) { ans = "445"; flag = 1; break; }
                if (d == 50) { ans = "552"; flag = 1; break; }
                if (d == 75) { ans = "553"; flag = 1; break; }
                if (d == 100) { ans = "554"; flag = 1; break; }
                if (d == 125) { ans = "555"; flag = 1; break; }
                if (d == 24) { ans = "234"; flag = 1; break; }
                if (d == 30) { ans = "235"; flag = 1; break; }
                if (d == 40) { ans = "245"; flag = 1; break; }
                if (d == 60) { ans = "345"; flag = 1; break; }
            }
            
            if (flag) { cout << ans << endl; continue; }
            
            for (int z=0; z<k; z++) {
                d = v[z];
                if (d == 6) { ok[2] = ok[3] = 1; }
                if (d == 10) { ok[2] = ok[5] = 1; }
                if (d == 15) { ok[3] = ok[5] = 1; }
                if (d == 9) { ok[3] = ok[3] = 1; }
                if (d == 25) { ok[5] = ok[5] = 1; }
            }
            
            for (int i=2; i<=m; i++)
                if (ok[i]) ans.push_back(i+'0');
            if (ans.size() == 3) { cout << ans << endl; continue; }
            
            ans.clear();
            for (int z=0; z<k; z++) {
                d = v[z];
                if (d == 8) {
                    if (ok[3] || us[12]) { ans = "243"; flag = 1; break; }
                    else if (ok[5] || us[20]) { ans = "245"; flag = 1; break; }
                    else if (us[16]) { ans = "244"; flag = 1; break; }
                }
                if (d == 12) {
                    if (ok[5] || us[20]) { ans = "345"; flag = 1; break; }
                    else if (us[8]) { ans = "234"; flag = 1; break; }
                    else if (us[16]) { ans = "344"; flag = 1; break; }
                }
                
                if (d == 20) {
                    if (ok[5]) { ans = "455"; flag = 1; break; }
                    else if (ok[3]) { ans = "345"; flag = 1; break; }
                    else if (ok[3]) { ans = "245"; flag = 1; break; }
                    else if (us[16]) { ans = "445"; flag = 1; break; }
                }
                
                if (d == 16) {
                    if (ok[2] || us[8]) { ans = "244"; flag = 1; break; }
                    else if (ok[3] || us[12]) { ans = "344"; flag = 1; break; }
                    else if (ok[5] || us[20]) { ans = "544"; flag = 1; break; }
                }
            }
            
            if (flag) { cout << ans << endl; continue; } 
            
            ans.clear();
            for (int i=0; i<3; i++)
                ans.push_back(rand()%(m-2+1) + 2 + '0');
            cout << ans << endl;
        }
    }
    
	return 0;
}
