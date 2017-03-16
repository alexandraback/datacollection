#include <cmath>
#include <vector>
#include <iostream>
#define F first
#define S second
using namespace std; 
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        cout<<"Case #"<<xx<<": ";
        string cod, jam;
        cin>>cod>>jam;
        pair<int, int> ans = {0, 1e9};
        int n = cod.size();
        for(int i = 0; i < 10000000; ++i) {
            int cod2 = 0;
            int jam2 = 0;
            int q = 1;
            int ii = i;
            for(int j = n-1; j >= 0; --j) {
                if(cod[j] == '?') {
                    cod2 += q*(ii%10);
                }
                else {
                    cod2 += q*(cod[j]-'0');
                }
                q *= 10;
                ii /= 10;
            }
            q = 1;
            for(int j = n-1; j >= 0; --j) {
                if(jam[j] == '?') {
                    jam2 += q*(ii%10);
                }
                else {
                    jam2 += q*(jam[j]-'0');
                }
                q *= 10;
                ii /= 10;
            }
            int zz = abs(cod2-jam2) - abs(ans.F-ans.S);
            if(abs(cod2 -jam2) < abs(ans.F-ans.S)) {
                ans.F = cod2;
                ans.S = jam2;
            }
            else if(zz == 0 && cod2 < ans.F) {
                ans.F = cod2;
                ans.S = jam2;
            }
            else if(zz == 0 && cod2 == ans.F & jam2 < ans.S) {
                ans.F = cod2;
                ans.S = jam2;
            }
        }
        vector<int> ans1(n);
        vector<int> ans2(n);
        for(int i = n-1; i >= 0; --i) {
            ans1[i] = ans.F%10;
            ans.F /= 10;
            ans2[i] = ans.S%10;
            ans.S /= 10;
        }
        for(auto x: ans1) cout<<x;
        cout<<' ';
        for(auto x: ans2) cout<<x;
        cout<<'\n';
    }
}
