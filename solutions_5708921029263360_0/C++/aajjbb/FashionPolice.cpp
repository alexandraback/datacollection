#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int T, J, P, S, K;


int myrandom (int i) { return std::rand()%i;}

set<pair<int, pair<int, int> > > A() {
    set<pair<int, pair<int, int> > > ans;
    map<pair<int, int>, int> JP;
    map<pair<int, int>, int> JS;
    map<pair<int, int>, int> PS;

    vector<pair<int, pair<int, int> > > sp;
    
    for (int i = 1; i <= J; i++) {
        for (int j = 1; j <= P; j++) {            
            for (int k = S; k >= 1; k--) {
                sp.push_back(make_pair(i, make_pair(j, k)));
            }
        }
    }

    vector<int> vs;

    for (int i = 0; i < (int) sp.size(); i++) {
        vs.push_back(i);
    }

    random_shuffle(sp.begin(), sp.end());
    
    for (int i = 0; i < (int) sp.size(); i++) {
        int pi = sp[i].first;
        int pj = sp[i].second.first;
        int pk = sp[i].second.second;
        
        pair<int, int> pa = make_pair(pi, pj);
        pair<int, int> pb = make_pair(pi, pk);
        pair<int, int> pc = make_pair(pj, pk);
                
        if (JP[pa] < K && JS[pb] < K && PS[pc] < K) {
            JP[pa] += 1;
            JS[pb] += 1;
            PS[pc] += 1;
            //cout << "CK " << i << " " << j << " " << JP[pa] << " => " << K << endl;
            ans.insert(make_pair(pi, make_pair(pj, pk)));
        }
    }
    return ans;
}


int main(void) {
    srand(unsigned(std::time(0)));
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> J >> P >> S >> K;

        cout << "Case #" << t << ": ";

        set<pair<int, pair<int, int> > > ans;

        for (int i = 0; i < 1000; i++) {
            set<pair<int, pair<int, int> > > curr = A();
            if (curr.size() > ans.size()) {
                ans = curr;
            }
        }
        
        cout << ans.size() << endl;

        for (auto& it : ans) {
            cout << it.first << " " << it.second.first << " " << it.second.second << endl;
        }
        //cout << endl;
    }
    
    return 0;
}
