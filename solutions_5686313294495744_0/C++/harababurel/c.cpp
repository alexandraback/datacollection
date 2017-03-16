#include <bits/stdc++.h>
using namespace std;

const int confmax = (1<<16)-1;

int n, t, max_bits;
vector <pair <string, string>> v;
set <string> can_use_left, can_use_right;
string a, b;

bool check(int conf) {
    // 0 means real
    // 1 means fake

    can_use_left.clear();
    can_use_right.clear();
    for(int i=0; i<n; i++)
        if(!(conf & (1<<i))) { // real
            can_use_left.insert(v[i].first);
            can_use_right.insert(v[i].second);
        }

    vector <int> fake;

    for(int i=0; i<n; i++)
        if(conf & (1<<i)) { // fake
            fake.push_back(i);

            if(can_use_left.find(v[i].first) == can_use_left.end())
                return false;
            if(can_use_right.find(v[i].second) == can_use_right.end())
                return false;
        }

    /*
    set <string> tmp_left, tmp_right;
    do {
        tmp_left.clear();
        tmp_right.clear();
        bool ok = true;
        for(auto x:fake) {
            if(can_use_left.find(v[x].first) == can_use_left.end() &&
               tmp_left.find(v[x].first) == tmp_left.end())
                ok = false;
            if(can_use_right.find(v[x].second) == can_use_right.end() &&
                tmp_right.find(v[x].second) == tmp_right.end())
                ok = false;

            if(!ok)
                break;
            tmp_left.insert(v[x].first);
            tmp_right.insert(v[x].second);
        }

        if(ok)
            return true;

    } while(next_permutation(fake.begin(), fake.end()));

    return false;
    */
    return true;
}

int main() {
    cin>>t;

    for(int test=1; test<=t; test++) {
        v.clear();

        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>a>>b;
            v.push_back(make_pair(a, b));
        }

        max_bits = 0;
        for(unsigned int conf=0; conf<(1<<n); conf++) {
            int bits = __builtin_popcount(conf);

            //cout<<conf<<"\n";
            if(bits <= max_bits)
                continue;

            if(check(conf))
                max_bits = bits;
        }

        cout<<"Case #"<<test<<": "<<max_bits<<"\n";
    }

    return 0;
}
