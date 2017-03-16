#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

string merge(const string& s)
{
    char last = '\0';
    char vis[26];
    string ret = "";

    memset(vis, 0, sizeof(vis));

    foreach (it, s) {
        if (*it != last) {
            if (vis[*it - 'a'])
                return "";
            vis[*it - 'a'] = 1;
            last = *it;
            ret += last;
        }
    }

    return ret;
}

#define MOD 1000000007

ll fact[201];

void fill_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < sizeof(fact)/sizeof(fact[0]); i++)
        fact[i] = fact[i-1] * i % MOD;
}

//void print_arr(const VS& vs, ll ret)
//{
//    cout << ret << " ";
//    foreach (it, vs)
//        cout << *it << ",";
//    cout << endl;
//}

int main(int argc, const char* argv[])
{
    int T;
    fill_fact();
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        ll ret = 1;
        cin >> N;
        VS cars;

        {
            bool ggood = true;
            for (int i = 0; i < N; i++) {
                string s;
                cin >> s;
                s = merge(s);
                cars.push_back(s);
                if (!s.length())
                    ggood = false;
            }
            if (!ggood) {
                cout << "Case #" << t << ": 0" << endl; 
                continue;
            }
        }

        for (char c = 'a'; c <= 'z'; c++) {
            VS newcars;
            VS l2;
            int l1 = 0;
            //print_arr(cars, ret);
            foreach (jt, cars) {
                if (jt->find(c) != string::npos) {
                    if (jt->length() == 1) {
                        l1++;
                    } else {
                        l2.push_back(*jt);
                    }
                } else {
                    newcars.push_back(*jt);
                }
            }
            if (l2.size() > 2)
                goto fail;
            if (l2.size() == 2) {
                string s;
                if (l2[0][0] == c) {
                    if (*l2[1].rbegin() != c)
                        goto fail;
                    s = l2[1] + l2[0];
                } else if (*l2[0].rbegin() == c) {
                    if (l2[1][0] != c)
                        goto fail;
                    s = l2[0] + l2[1];
                }
                s = merge(s);
                if (!s.length())
                    goto fail;
                newcars.push_back(s);
            } else if (l2.size() == 1) {
                if (l2[0][0] != c && *l2[0].rbegin() != c && l1)
                    goto fail;
                newcars.push_back(l2[0]);
            } else if (l1) {
                string s;
                s += c;
                newcars.push_back(s);
            }
            ret *= fact[l1];
            ret %= MOD;
            cars = newcars;
        }

        ret *= fact[cars.size()];
        ret %= MOD;

        cout << "Case #" << t << ": " << ret << endl; 
        continue;
fail:
        cout << "Case #" << t << ": 0" << endl; 
    }
    return 0;
}
