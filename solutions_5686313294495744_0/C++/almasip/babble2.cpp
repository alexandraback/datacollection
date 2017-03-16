#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

pair<string, string> s[20];
int mx;

void probal (vector<int> p, int e) {

    if (p.size() == e) {
        bool mjo=true;
        for (int i=0; i<e; i++) {
            /// i. elem kereses
            if (p[i] == 0) {
                bool jo1 = false, jo2=false;
                for (int j=0; j<e; j++) {
                    if (p[j]) {
                        if (s[j].first == s[i].first)
                            jo1=true;
                        if (s[j].second == s[i].second)
                            jo2=true;

                    }
                }
                if (!jo1 || !jo2) {
                    mjo=false;
                }

            }
        }
        if (mjo) {
            int db = count(p.begin(), p.end(), 0);
            mx = max(db, mx);
        }
    }
    else {
        p.push_back(0);
        probal(p, e);
        p[p.size()-1] = 1;
        probal(p, e);
    }

}

int main() {

    int test;
    cin >> test;
    for (int testnum = 1; testnum <= test; testnum++) {

        int e;
        cin >> e;
        mx=0;


        for (int i=0; i<e; i++) {
            cin >> s[i].first >> s[i].second;
        }

        probal({}, e);

        cout << "Case #" << testnum << ": ";
        cout << mx;
        cout << endl;
        //cout << n1 << " " << n2 << "  " << p.size() << endl;

    }
}

