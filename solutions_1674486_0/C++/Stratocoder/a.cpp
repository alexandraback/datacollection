#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 0; tt < t; ++tt) {
        int n;
        cin>>n;
        vector< vector< int > > v(n);
        vector< int > ref(n);
        for (int i = 0; i < n; ++i) {
            int c;
            cin>>c;
            for (int j = 0; j < c; ++j) {
                int x;
                cin>>x;
                v[i].push_back(x - 1);
                ++ref[x - 1];
            }
        }
        vector< map< int, int > > w(n);
        queue< int > q;
        for (int i = 0; i < ref.size(); ++i) {
            if (ref[i] == 0) {
                q.push(i);
            }
        }
        vector< bool > done(v.size());
        while (!q.empty()) {
            int c = q.front();
            q.pop();
            if ((ref[c] > 0) || done[c]) {
                continue;
            }
            done[c] = true;
            for (int i = 0; i < v[c].size(); ++i) {
                for (map< int, int >::iterator p = w[c].begin(); p != w[c].end(); ++p) {
                    w[v[c][i]][p->first] += p->second;
                }
                w[v[c][i]][c]++;
                q.push(v[c][i]);
                ref[v[c][i]]--;
            }
        }
        int ct = 0;
        for (int i = 0; i < w.size(); ++i) {
            for (map< int, int >::iterator p = w[i].begin(); p != w[i].end(); ++p) {
                if (p->second > 1) {
                    ++ct;
                }
            }
        }
        cout<<"Case #"<<(tt + 1)<<": ";
        if (ct) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

