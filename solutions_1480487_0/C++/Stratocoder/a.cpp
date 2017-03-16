#include <iostream>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 0; tt < t; ++tt) {
        vector< int > v;
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        int toti = accumulate(v.begin(), v.end(), 0);
        vector< pair< int, int > > ju(v.size());
        vector< bool > dist(v.size());
        for (int i = 0; i < v.size(); ++i) {
            ju[i] = make_pair(v[i], i);
        }
        sort(ju.begin(), ju.end());
        reverse(ju.begin(), ju.end());
        int act = v.size();
        for (int i = 0; i < ju.size(); ++i) {
            int ls = (ju.size() - i - 1) * ju[i].first;
            int occ = 0;
            for (int j = i + 1; j < ju.size(); ++j) {
                occ += ju[j].first;
            }
            int ptot = ls - occ;
            if (toti <= ptot) {
                dist[ju[i].second] = true;
                --act;
            } else {
                break;
            }
        }
        double tot = toti;
        double pot = 0.0;
        for (int i = 0; i < v.size(); ++i) {
            if (!dist[i]) {
                pot += v[i];
            }
        }
        double part = (tot + pot) / act;
        vector< double > ans(v.size());
        cout<<"Case #"<<(tt + 1)<<":"<<fixed<<setprecision(6);
        for (int i = 0; i < v.size(); ++i) {
            if (!dist[i]) {
                ans[i] = 100.0 * (part - v[i]) / tot;
            }
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}

