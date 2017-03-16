#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fst first
#define snd second
#define fr(i, a, b) for(int i=a; i<b; i++)
map<int, int> m;

void main2() {
    int n;
    cin >> n;
    m.clear();
    for(int i=0; i<2*n-1; i++) {
        for(int j=0; j<n; j++) {
            int t; cin>> t;
            if(m.count(t)==0) m[t] = 1;
            else
            m[t]++;
        }
    }
    vector<int> vs;
    for(map<int, int>::iterator it = m.begin(); it!=m.end(); it++) {
        if(it->second & 1) vs.push_back(it->first);
    }
    sort(vs.begin(), vs.end());
    for(int i=0; i<vs.size(); i++) cout<<" "<<vs[i];
    cout<<endl;
}

int main() {
    int T;
    cin>>T;
    for(int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<":";
        main2();
    }
}
