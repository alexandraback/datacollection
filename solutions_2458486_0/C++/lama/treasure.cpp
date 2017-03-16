#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
#include <unordered_set>

using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << (x) << endl;

int T, K, N;
int n_keys_t[210]; // n_keys_t[x] = number of keys for type x
int t_n[210]; // t_n[x] = type of key needed to open trove x
vector<bool> opened;
unordered_set< vector<bool> > memo;
vector<int> sequence;
vector<int> keys_inside[210];

bool dfs() {
    if(sequence.size() == N) { // if all opened
        for(int i = 0; i < sequence.size(); i++) {
            cout << " " << sequence[i];
        }
        cout << endl;
        return true;
    }
    if(memo.find(opened) != memo.end()) return false; // if already checked in the past
    bool res;
    for(int Ni = 1; Ni <= N; Ni++) {
        if(!opened[Ni] && n_keys_t[t_n[Ni]] > 0) {
            // open the trove
            opened[Ni] = true;
            sequence.push_back(Ni);
            n_keys_t[t_n[Ni]]--;
            for(int ki = 0; ki < keys_inside[Ni].size(); ki++) {
                n_keys_t[keys_inside[Ni][ki]]++;
            }
            res = dfs(); if(res) return res;
            memo.insert(opened);
            // close the trove
            opened[Ni] = false;
            sequence.pop_back();
            n_keys_t[t_n[Ni]]++;
            for(int ki = 0; ki < keys_inside[Ni].size(); ki++) {
                n_keys_t[keys_inside[Ni][ki]]--;
            }
        }
    }
    return res;
}

int main() {
    cin >> T;
    for(int i = 0; i < 25; i++) opened.push_back(false);
    for(int Ti = 1; Ti <= T; Ti++) {
        // reset values
        fill_n(n_keys_t, 210, 0);
        fill_n(t_n, 210, 0);
        fill_n(opened.begin(), 25, false);
        memo.clear();
        sequence.clear();
        for(int i = 0; i < 210; i++) keys_inside[i].clear();

        // input
        cin >> K >> N;
        for(int Ki = 0; Ki < K; Ki++) {
            int a;
            cin >> a;
            n_keys_t[a]++;
        }
        for(int Ni = 1; Ni <= N; Ni++) {
            int ti, ki;
            cin >> t_n[Ni] >> ki;
            for(int kii = 0; kii < ki; kii++) {
                int ffdas; cin >> ffdas;
                keys_inside[Ni].push_back(ffdas);
            }
        }
        cout << "Case #" << Ti << ":";
        if(!dfs()) cout << " IMPOSSIBLE" << endl;
    }
}