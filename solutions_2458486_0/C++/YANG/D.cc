#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <deque>

using namespace std;

deque<int> p;

struct Box
{
    int id;
    int key;
    multiset<int> keys;
};

bool unlock(multiset<int>& mk, vector<Box>& bs)
{
    if (bs.empty()) {
        return true;
    }
    if (mk.empty()) {
        return false; 
    }

#if 1
    int kcnt[200] = {0};
    for (multiset<int>::const_iterator it = mk.begin(); it != mk.end(); it++)
        kcnt[*it -1]++;
    for (int i = 0; i < bs.size(); i++) {
        for (multiset<int>::const_iterator it = bs[i].keys.begin(); it != bs[i].keys.end(); it++)
            kcnt[*it -1]++;
    }
    for (int i = 0; i < bs.size(); i++) {
        if (--kcnt[bs[i].key - 1] < 0) return false;
    }

    int kchk[200] = {0};
    set<int> kv(mk.begin(), mk.end());
    for (int i = 0; i < bs.size(); i++) {
        multiset<int> ks = bs[i].keys;
        if (bs[i].keys.find(bs[i].key) != bs[i].keys.end()) {
            ks.erase(bs[i].key);

            kv.insert(ks.begin(), ks.end());
            kchk[bs[i].key - 1] = 1;
        } else {
            kv.insert(ks.begin(), ks.end());
        }
    }

    for (int i = 0; i < 200; i++) {
        if (kchk[i] == 1) {
            if (kv.find(i + 1) == kv.end()) {
                return false;
            }
        }
    }
#endif

    int i = 0;
    for (; i < bs.size(); i++) {
        multiset<int> mk1(mk);
        multiset<int>::iterator it = mk1.find(bs[i].key);
        if (it != mk1.end()) {
            mk1.erase(it);
            mk1.insert(bs[i].keys.begin(), bs[i].keys.end());
            
            vector<Box> bs1(bs.size() - 1);
            for (int j = 0; j < bs.size(); j++) {
                if (j < i) {
                    bs1[j] = bs[j];
                } else if (j > i) {
                    bs1[j - 1] = bs[j];
                }
            }

            p.push_back(bs[i].id);
            if (unlock(mk1, bs1)) {
                return true;
            } else {
                p.pop_back();
            }
        }
    }
    if (i == bs.size()) {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++) {
        int ks, ns;
        cin >> ks >> ns;
        multiset<int> mk;
        for (int j = 0; j < ks; j++) {
            int ki;
            cin >> ki;
            mk.insert(ki);
        }

        vector<Box> bs(ns);
        for (int j = 0; j < ns; j++) {
            bs[j].id = j + 1;
            int kn;
            cin >> bs[j].key >> kn;
            for (int k = 0; k < kn; k++) {
                int ki;
                cin >> ki;
                bs[j].keys.insert(ki);
            }
        }

        string r;
        deque<int>().swap(p);

        if (unlock(mk, bs)) {
            stringstream ss;
            for (int j = 0; j < p.size(); j++) {
                ss << " " << p[j];
            }
            r = ss.str();
        } else {
            r = " IMPOSSIBLE";
        }

        cout << "Case #" << i << ":" << r << endl;
    }
}
