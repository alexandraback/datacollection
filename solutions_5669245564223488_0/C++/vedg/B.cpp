//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <limits>
#include <queue>
#include <stdexcept>
# include <cassert>

using namespace std;

typedef long long L;
const L mm = 1000 * 1000 * 1000 + 7;
L fact(L i)
{
    if (i == 0)
        return 1;
    return (i * fact(i - 1)) % mm;
}
struct Letter {
    int strId;
    bool beginning;
};

void disii(const vector<string> & cars, const vector<int> & count1,
         const vector<string> & groups, const vector<int> & sIdToGroup)
{
    cout << "Cars:\n";
    for (const string & s : cars) {
        cout << s << endl;
    }
    cout << "Count1:\n";
    for (int i = 'a'; i <= 'z'; ++i) {
        if (count1[i] != 0)
            cout << char(i) << ' ' << count1[i] << endl;
    }
    cout << "Groups:\n";
    for (const string & s : groups) {
        cout << s << endl;
    }
    cout << "sIdToGroup:\n";
    for (int i = 0; i < cars.size(); ++i) {
        if (sIdToGroup[i] != -1)
            cout << i << ' ' << sIdToGroup[i] << endl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    freopen("small.out", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {

        int n;
        cin >> n;
        vector<string> cars(n);
        vector<vector<Letter>> occurences(255);
        vector<int> count1(255);
        for (int sId = 0; sId < n; ++sId) {
            string & s = cars[sId];
            cin >> s;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] == s[i - 1]) {
                    s.erase(i, 1);
                    --i;
                }
            }
            if (s.size() == 1) {
                ++count1[s[0]];
                auto & v = occurences[s[0]];
                if (! v.empty()) {
                    int & ss = v.front().strId;
                    if (ss == -1) {
                        ss = -2;
                    }
                }
            }
            else {
                occurences[s.front()].push_back( {sId, true});
                occurences[s.back()].push_back( {sId, false});
                for (int i = 1; i < s.size() - 1; ++i) {
                    vector<Letter> & v = occurences[s[i]];
                    if (v.empty()) {
                        if (count1[s[i]] == 0)
                            v.push_back( { -1, true});
                        else
                            v.push_back( { -2, true});
                    }
                    else
                        v.front().strId = -2;
                }
            }
        }
        bool possible = true;
        L ans = 0;
        for (int i = 'a'; i <= 'z'; ++i) {
            vector<Letter> & v = occurences[i];
            if (v.empty())
                continue;
            if (v.front().strId == -2) {
                possible = false;
                break;
            }
            if (v.front().strId == -1 && v.size() != 1) {
                possible = false;
                break;
            }
            if (v.size() > 2  || v.size() == 2 &&
                    (v.front().beginning == v.back().beginning
                     || v.front().strId == v.back().strId)) {
                possible = false;
                break;
            }
        }
        vector<string> groups;
        vector<int> sIdToGroup(255, -1);
        bool err = false;
        if (possible) {
            ans = 1;
            for (int i = 'a'; i <= 'z'; ++i) {
                ans = (ans * fact(count1[i])) % mm;
                vector<Letter> & v = occurences[i];
                if (v.size() == 0) {
                    if (count1[i] != 0)
                        groups.push_back(string(1, i));
                }
                else if (v.size() == 1) {
                    int id = v.back().strId;
                    if (sIdToGroup[id] == -1) {
                        bool beg = v.back().beginning;
                        int otherEnd = beg ? cars[id].back() : cars[id].front();
                        if (occurences[otherEnd].size() < 2) {
                            sIdToGroup[id] = groups.size();
                            groups.push_back(cars[id]);
                        }
                    }
                }
                else {
                    // 2
                    assert(v.size() == 2);
                    int id1 = v.front().strId, id2 = v.back().strId;
                    bool beg1 = v.front().beginning, beg2 = v.back().beginning;
                    assert(beg1 != beg2);
                    if (id1 == id2) {
                        err = true;
                    }
                    assert(id1 != id2);
                    if (sIdToGroup[id2] == -1) {
                        swap(id1, id2);
                        swap(beg1, beg2);
                    }
                    if (sIdToGroup[id1] == -1) {
                        if (sIdToGroup[id2] == -1) {
                            sIdToGroup[id1] = sIdToGroup[id2] = groups.size();
                            groups.push_back(beg1  ? cars[id2] + cars[id1]
                                             : cars[id1] + cars[id2]);
                        }
                        else {
                            int t = sIdToGroup[id2];
                            sIdToGroup[id1] = t;
                            if (beg1) {
                                if (groups[t].back() == cars[id1].front()) {
                                    groups[t] += cars[id1];
                                }
                                else {
                                    possible = false;
                                    break;
                                }
                            }
                            else {
                                if (groups[t].front() == cars[id1].back()) {
                                    groups[t] = cars[id1] + groups[t];
                                }
                                else {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        possible = false;
                        break;
                    }
                }
            }

            ans = (ans * fact(groups.size())) % mm;
        }
        //  if (err)
      //  dis(cars, count1, groups, sIdToGroup);
        cout << "Case #" << cas << ": " << (possible ? ans :L( 0)) << endl;
    }


#ifndef ONLINE_JUDGE
    fclose(stdin);
    // putchar('\n');
#endif
}
