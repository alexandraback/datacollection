#include <iostream>
#include <cstdio>
#include <sstream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    for (int tt=1; tt <= T; tt++) {
        set<pair<int,int> > pairs;
        int A, B; cin >> A >> B;
        int count = 0;
        for (int i=A; i<=B; i++) {
            stringstream ss; ss << i;
            string num; ss >> num;
            for (int j=0; j < num.size(); j++) {
                string newnum = num.substr(j, num.size()-j) + num.substr(0, j);
                stringstream ss2; ss2 << newnum;
                int d; ss2 >> d;
                if (d > i && d <= B && !pairs.count(make_pair(i,d))) {
                    count++;
                    pairs.insert(make_pair(i,d));
                }
            }
        }
        cout << "Case #" << tt << ": " << count << "\n";
    }
    cout << flush;
    return 0;
}