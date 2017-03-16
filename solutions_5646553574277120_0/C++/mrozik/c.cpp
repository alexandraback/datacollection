#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int C, D, V;

bool check(const vector<int>& v) {
    unsigned m = 1;
    for (int i=0; i<int(v.size()); i++)
        for (int j=V-v[i]; j>=0; j--)
            if (m&(1<<j)) m|=(1<<(j+v[i]));
    return m==(1<<(V+1))-1;
}


int go(vector<int>& v, int start, int maxd) {
    if (check(v)) return 0;
    if (maxd==0) return 100;
    int res = 100;
    for (int i=start; i<=V; i++) {
        if (find(v.begin(), v.end(), i)!=v.end())
            continue;
        v.push_back(i);
        res = min(res, go(v, i+1, maxd-1)+1);
        v.pop_back();
    }
    return res;
}


int main() {
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cin>>C>>D>>V;
        vector<int> v;
        v.resize(D);
        for (int i=0; i<D; i++) cin>>v[i];
        
        int result = go(v, 1, 6);

        cout<<"Case #"<<t<<": "<<result<<endl;
  }
}
