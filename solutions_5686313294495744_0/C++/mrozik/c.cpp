#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Topic {
    string a, b;
};

vector<Topic> topics;

int check(unsigned x) {
    set<string> first, second;
    for (int i=0; i<int(topics.size()); i++) {
        if (x & (1<<i))
            first.insert(topics[i].a), second.insert(topics[i].b);
    }
    int res = 0;
    for (int i=0; i<int(topics.size()); i++) {
        if (!(x & (1<<i))
            && first.count(topics[i].a)
            && second.count(topics[i].b))
            res++;
    }
    return res;
}


int main() {
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int N; cin>>N;
        topics.resize(N);
        for (int i=0; i<N; i++)
            cin>>topics[i].a>>topics[i].b;
        
        int res = 0;
        for (unsigned x = 0; x< (1<<N); x++)
            res = max(res, check(x));
        
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}

