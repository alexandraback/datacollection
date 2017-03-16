#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 0; tt < t; ++tt) {
        int n;
        cin>>n;
        vector< int > v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }
        map< int, int > mp;
        bool ok = false;
        for (int i = 1; i < (1<<20); ++i) {
            int sm = 0;
            int x = i;
            int ct = 0;
            while (x) {
                if (x & 1) {
                    sm += v[ct];
                }
                x >>= 1;
                ++ct;
            }
            if (mp.find(sm) == mp.end()) {
                mp[sm] = i;
            } else {
                vector< int > a, b;
                x = i;
                ct = 0;
                while (x) {
                    if (x & 1) {
                        a.push_back(v[ct]);
                    }
                    x >>= 1;
                    ++ct;
                }
                x = mp[sm];
                ct = 0;
                while (x) {
                    if (x & 1) {
                        b.push_back(v[ct]);
                    }
                    x >>= 1;
                    ++ct;
                }
                cout<<"Case #"<<(tt + 1)<<":"<<endl<<a.front();
                for (int i = 1; i < a.size(); ++i) {
                    cout<<" "<<a[i];
                }
                cout<<endl<<b.front();
                for (int i = 1; i < b.size(); ++i) {
                    cout<<" "<<b[i];
                }
                cout<<endl;
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout<<"Case #"<<(tt + 1)<<":"<<endl<<"Impossible"<<endl;
        }
    }
    return 0;
}

