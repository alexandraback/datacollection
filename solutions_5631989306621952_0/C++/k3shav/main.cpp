#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    deque<char> q;
    q.push_back(s[0]);
    
    for(int i=1 ; i< s.length() ; i++) {
        if (s[i]>=q.front()) {
            q.push_front(s[i]);
        }
        else {
            q.push_back(s[i]);
        }
    }
    
    for(auto v:q) {
        cout<<v;
    }
    cout<<endl;
    
}

int main(int argc, const char **argv) {
    if(argc>=2) {
        freopen(argv[1], "r", stdin);
        freopen(argv[2], "w", stdout);
    }
    
    int T;
    cin>>T;
    for(int t=1 ; t<=T ; t++) {
        printf("Case #%d: ",t);
        fprintf(stderr,"Case #%d: Done\n",t);
        solve();
    }
}
