#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

#define num(i,N) for(int i=0; i < (N); ++i)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin(); i != (c).end(); ++i)
#define has(c,x) ((c).find(x) != (c).end())

vector<int> group('z'-'a'+1);

void uf_init(vector<int> &comp){
    for(int i=0; i<sz(comp); i++) {
        comp[i] = i;
    }
}

int uf_root(vector<int> &comp, int node){
    return comp[node];
}

void uf_unite(vector<int> &comp, int a, int b){
    int ga = comp[a], gb = comp[b];
    for (int i=0; i<sz(comp); i++) {
        if (comp[i]==gb) comp[i]=ga;
    }
}

bool is_pure(string &s) {
    for (int i=1; i<sz(s); i++) {
        if (s[i]!=s[i-1]) return false;
    }
    return true;
}


long long int solve(vector<string> parts) {
    long long int current = 1;
    vector<int> pure('z'+1);
    vector<bool> used(sz(parts));

    vector<bool> ispure(sz(parts));
    for (int i=0; i<sz(parts); i++) {
        ispure[i] = is_pure(parts[i]);
    }

    string train = parts[0];
    used[0] = true;
    if (ispure[0]) {
        pure[parts[0][0]] += 1;
    }

    for (int ii=0; ii<sz(parts)*2; ii++) {
        // try app / prepending pures
        for (int i=0; i<sz(parts); i++) {
            if (!used[i] && ispure[i] && train[sz(train)-1]==parts[i][0]) {
                train += parts[i];
                used[i] = true;
                pure[parts[i][0]] += 1;
                current *= pure[parts[i][0]];
                current %= 1000000007;
            }
            if (!used[i] && ispure[i] && train[0]==parts[i][sz(parts[i])-1]) {
                train = parts[i] + train;
                used[i] = true;
                pure[parts[i][0]] += 1;
                current *= pure[parts[i][0]];
                current %= 1000000007;
            }
        }

        // try app / prepending something else
        for (int i=0; i<sz(parts); i++) {
            if (!used[i] && train[sz(train)-1]==parts[i][0]) {
                train += parts[i];
                used[i] = true;
                break;
            }
            if (!used[i] && train[0]==parts[i][sz(parts[i])-1]) {
                train = parts[i] + train;
                used[i] = true;
                break;
            }
        }
    }

    //cout << "TRAIN: " <<  train << endl;

    for (int i=0; i<sz(parts); i++) {
        if (used[i]==false) {
            return 0;
        }
    }

    bool all_pure = true;
    for (int i=0; i<sz(parts); i++) {
        if (ispure[i]==false) {
            all_pure = false;
            break;
        }
    }

    // check if all pure => just return factorial
    if (all_pure) {
        return current;
    }

    vector<bool> cused('z'+1);
    char before = train[0];
    cused[before] = true;;
    for (int i=1; i<sz(train); i++) {
        if (train[i]==before) continue;
        if (cused[train[i]]) return 0;
        before = train[i];
        cused[before] = true;
    }

    // otherwise return current
    return current;
}

int main() {
    int T = 0;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";

        int N=0;
        cin >> N;
        vector<string> w(N);
        for (int i=0; i<N; i++) {
            cin>>w[i];
        }

        uf_init(group);
        for (int i=0; i<N; i++) {
            for (int j=1; j<sz(w[i]); j++) {
                if (w[i][j]!=w[i][j-1]) {
                    uf_unite(group, w[i][j]-'a',w[i][j-1]-'a');
                }
            }
        }

        for (int i=0; i<N; i++) {
            //cout<<group[w[i][0]-'a']<<" "<<w[i]<<endl;
        }

        long long int total = 1;

        // grouping can be done any way
        long long int groups = 0;
        for (int g=0; g<='z'-'a'; g++) {
            vector<string> parts;
            for (int i=0; i<N; i++) {
                if (group[w[i][0]-'a']==g) {
                    parts.push_back(w[i]);
                }
            }
            if (sz(parts)==0) continue;
            //cout << endl << g << " ";
            total = total * solve(parts);
            total %= 1000000007;
            groups += 1;
            total *= groups;
            total %= 1000000007;
        }
        //cout << endl;

        cout << total << endl;
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
