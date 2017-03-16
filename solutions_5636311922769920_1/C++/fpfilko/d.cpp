#include<iostream>
#include<vector>

using namespace std;

long long transform(vector<long long> &x, long long k) {
    long long res=0;
    for(long long i = 0; i<x.size(); i++) {
        res*=k;
        res+=x[i];
    }
    return res+1ll;
}

int main() {
    long long T; cin >> T;
    for(int t = 1; t<=T; t++) {
        long long k, c, s;
        cin >> k >> c >> s;
        vector<vector<long long>> v;
        while(v.size()*c < k) {
            v.push_back(vector<long long> (c));
            for(int i = 0; i<c; i++)
                v.back()[i]=(i+(v.size()-1)*c)%k;
        }
        cout << "Case #" << t << ":";
        if(v.size() > s)
            cout << " IMPOSSIBLE";
        else {
            for(auto x: v) {
                cout << " " << transform(x, k);
            }
        }
        cout << "\n";
    }

}
