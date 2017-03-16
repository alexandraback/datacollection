#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define MAXN 16
#define SETS 128
#define SUBSETS 16

set<long long> tmp, tmp2;
map<long long, set<long long> > m;
vector< set<long long> > sets;

long long random_set(int M, int N, long long n[]) {
    for (int j=0; j<N; j++) n[j] = (long long)(2+rand()%(M-1));
    sort(n, n+N);
    long long cur = 0LL;
    for (int j=0; j<N; j++) cur = cur*10LL + n[j];
    return cur;
}

long long merge(int K) {
    int i;
    vector<long long> valid;
    for (set<long long>::iterator it=sets[0].begin(); it!=sets[0].end(); it++) {
        for (i=1; i<K; i++) if (sets[i].find(*it) == sets[i].end()) break;
        if (i == K) valid.push_back(*it);
    }
    return valid[rand()%valid.size()];
}

int main() {
    int T, t, R, N, M, K, i, j, k;
    long long cur, n[MAXN], prod;

    cin >> T;
    for (t=1; t<=T; t++) {
        cout << "Case #" << t << ":" << endl;
        cin >> R >> N >> M >> K;

        for (i=0; i<SETS; i++) {
            cur = random_set(M, N, n);

            tmp.clear(); tmp2.clear();
            for (j=0; j<SUBSETS; j++) {
                prod = 1LL;
                for (k=0; k<N; k++) if (rand()&1) prod *= n[k];
                tmp.insert(prod);
            }
//            cout << cur << endl;
            for (set<long long>::iterator it=tmp.begin(); it!=tmp.end(); it++) {
                prod = (*it);
//                cout << '\t' << prod << endl;
                if (m.find(prod) == m.end()) m[prod] = tmp2;
                m[prod].insert(cur);
            }
        }

        for (i=0; i<R; i++) {
            sets.clear();
            for (j=0; j<K; j++) {
                cin >> prod;
                if (m.find(prod) != m.end()) sets.push_back(m[prod]);
            }
            if (sets.size() < K) cout << random_set(M, N, n) << endl;
            else cout << merge(K) << endl;
        }
    }

    return 0;
}
