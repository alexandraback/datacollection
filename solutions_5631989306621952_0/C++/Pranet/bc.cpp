//Pranet Verma
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for (int tc = 1; tc <= t; ++tc) {
        cout<<"Case #"<<tc<<": ";
        string s;
        cin>>s;
        deque<char> q;
        for (auto c : s) {
            if (q.empty()) {
                q.push_back(c);
            }
            else {
                if (c >= q.front()) {
                    q.push_front(c);
                }
                else {
                    q.push_back(c);
                }
            }
        }
        while (!q.empty()) {
            cout<<q.front();
            q.pop_front();
        }
        cout<<"\n";
    }
}