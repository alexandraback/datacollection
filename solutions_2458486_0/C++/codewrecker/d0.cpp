#include <iostream>
#include <map>
#include <set>
//#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
map<int, int> c_k;
map<int, multiset<int>> c_ks;
vector<vector<int>> sols;
//unordered_set<set<int>> visit;
set<set<int>> visit;

bool found = false;

void dfs(const multiset<int> &keys, const set<int> &vst, const vector<int> &sol)
{
    if (found)
        return;
    if (vst.size() == N) {
        sols.push_back(sol);
        found = true;
        return;
    }

    /*
    if (visit.find(vst) != visit.end()) {
        //cout << visit.size() << endl;
        return;
    } else
        visit.insert(vst);
    */

    vector<int> nexts;
    for (int c = 1; c <= N; ++c) {
        if (!vst.count(c)) {
            if (keys.count(c_k[c])) {
                nexts.push_back(c);
            }
        }
    }
    for (auto &c : nexts) {
        set<int> nvst(vst);
        nvst.insert(c);
        if (visit.find(nvst) != visit.end()) {
            //cout << visit.size() << endl;
            continue;
        } else
            visit.insert(nvst);
        multiset<int> nkeys(keys);
        //nkeys.erase(c_k[c]);
        auto it = nkeys.find(c_k[c]);
        nkeys.erase(it);
        nkeys.insert(c_ks[c].begin(), c_ks[c].end());
        vector<int> nsol(sol);
        nsol.push_back(c);

        dfs(nkeys, nvst, nsol);
    }
}

int main()
{
    int T, tcnt = 0;
    cin >> T;

    while (T--) {
        cin >> K >> N;
        int tmp;
        multiset<int> keys;
        map<int, int> keys_amount;
        map<int, int> keys_needed;
        for (int i = 0; i < K; ++i) {
            cin >> tmp;
            keys.insert(tmp);
            if (keys_amount.count(tmp))
                ++keys_amount[tmp];
            else
                keys_amount[tmp] = 1;
        }
        c_k.clear();
        c_ks.clear();
        for (int i = 1; i <= N; ++i) {
            int t, k;
            cin >> t >> k;
            c_k.insert({i, t});
            if (keys_needed.count(t))
                ++keys_needed[t];
            else
                keys_needed[t] = 1;
            multiset<int> keys_inside;
            for (int j = 0; j < k; ++j) {
                cin >> tmp;
                keys_inside.insert(tmp);
                if (keys_amount.count(tmp))
                    ++keys_amount[tmp];
                else
                    keys_amount[tmp] = 1;
            }
            c_ks.insert({i, keys_inside});
        }
        bool imp = false;
        for (auto &k_n : keys_needed) {
            if (!keys_amount.count(k_n.first) || keys_amount[k_n.first] < k_n.second) {
                //cout << k_n.first << " " << k_n.second << " " << keys_amount[k_n.first] << endl;
                imp = true;
                break;
            }
        }

        if (!imp) {
            found = false;
            visit.clear();
            sols.clear();
            set<int> vst;
            vector<int> sol;
            dfs(keys, vst, sol);
            if (sols.empty())
                imp = true;
            /*
               cout << "keys: ";
               for (auto k : keys) cout << k << " "; cout << endl;
               cout << "chest - key:" << endl;
               for (auto &ck : c_k)
               cout << ck.first << "-" << ck.second << endl;
               cout << "chest - keys:" << endl;
               for (auto &cks : c_ks) {
               cout << cks.first << " - ";
               for (auto &k : cks.second)
               cout << k << " ";
               cout << endl;
               }
               */
            //sort(sols.begin(), sols.end());
            /*
               for (auto &s : sols) {
               for (auto &c : s)
               cout << c << " ";
               cout << endl;
               }
               */
        }

        cout << "Case #" << ++tcnt << ": ";
        if (imp)
            cout << "IMPOSSIBLE" << endl;
        else {
            auto &s = sols[0];
            for (int i = 0; i < s.size() - 1; ++i)
                cout << s[i] << " ";
            cout << s[s.size()-1];
            cout << endl;
        }
    }
}

