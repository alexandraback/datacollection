#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;



int M[2], D[2];

struct Ev {
    string str;
    int a;
    Ev(string str, int a) :str(str), a(a) {}
    bool operator<(const Ev& e) const {
        return a < e.a;
    }
    bool operator==(const Ev& e) const {
        return a == e.a;
    }
};

int main() {
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        int N; cin>>N;
        int ix = 0;
        for (int i=0; i<N; i++) {
            int d, h, m;
            cin>>d>>h>>m;
            for (int j=0; j<h; j++)
                M[ix]=m, D[ix]=d, ix++, m++;
        }
        if (ix>2) cerr<<"WTF"<<endl;
        int res = 0;
        
        if (ix==2) {
            vector<Ev> v;
            v.push_back(Ev("A0", (360-D[0])*M[0]));
            v.push_back(Ev("A1", (720-D[0])*M[0]));
            v.push_back(Ev("B0", (360-D[1])*M[1]));
            v.push_back(Ev("B1", (720-D[1])*M[1]));
            
            sort(v.begin(), v.end());
            if (v[0]<v[1] && v[0].str[0]==v[1].str[0]) res=1;
            if (v[0]<v[1] && v[1]==v[2]) res=1;
        }
        
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
}
