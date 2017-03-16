#include <iostream>
#include <iomanip>
using namespace std;
typedef long double ld;
int main() {
    int tt;
    cin>>tt;
    for(int xx = 1; xx <= tt; ++xx) {
        ld ma = 0;
        int k,l,s;
        cin>>k>>l>>s;
        string K, L;
        cin>>K>>L;
        string v;
        v = L;
        ma = 0;
        ld tod[1000] = {0};
        for(int i = 0; i < K.size(); ++i) {
            tod[K[i]] += 1.0/k;
        } 
        for(int i = 1; i+(int)L.size()-1 < s; ++i) {
            for(int j = 0; j < L.size(); ++j) {
                if(i+j < v.size() && v[i+j] != L[j]) goto ohi;
                if(i+j >= v.size()) {
                    v.push_back(L[j]);
                }
            }
            ohi:;
        }
        for(int i = 0; i < s; ++i) {
            for(int j = 0; j < L.size(); ++j) {
                if(i+j >= s) goto ohi2;
                if(v[i+j] != L[j]) {
                    goto ohi2;

                }
                if(tod[L[j]] < 0.0000000000001) {
                    goto ohi2;
                }
            }
            ++ma;
            ohi2:;
        }
        /*
        cout<<"lol"<<endl;
        cout<<v<<'\n';
        cout<<ma<<'\n';
        */
       
        ld dp1[1000] = {0};
        ld dp2[1001] = {0};
        ld qwe = 0;
        for(int i = 0; i < s; ++i) {
            dp2[0] = tod[L[0]];
            for(int j = 1; j < L.size(); ++j) {
                dp2[j] = dp1[j-1]*tod[L[j]];
            }
            for(int j = 0; j < 1000; ++j) {
                dp1[j] = dp2[j];
            }
            qwe += dp2[l-1];
        }
        cout<<fixed;
        cout<<"Case #"<<xx<<": "<<setprecision(15)<<ma-qwe<<'\n';
    }
}
