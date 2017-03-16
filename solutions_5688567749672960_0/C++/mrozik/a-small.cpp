#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <cstring>
using namespace std;

int Z[1000001];

char buf[128];
int inv(int x) {
    sprintf(buf, "%d", x);
    reverse(buf, buf+strlen(buf));
    sscanf(buf, "%d", &x);
    return x;
}

void add(deque<int>& q, int x, int d) {
    if (x > 1000000 || Z[x]!=0) return;
    Z[x] = d;
    q.push_back(x);
}

int main() {

    Z[1] = 1;
    deque<int> q;
    q.push_back(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop_front();
        add(q, x+1, Z[x]+1);
        add(q, inv(x), Z[x]+1);
    }
    
    cerr<<"ok, ready"<<endl;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int x;
        cin>>x;
        cout<<"Case #"<<t<<": "<<Z[x]<<endl;
  }
}
