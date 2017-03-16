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

bool good(const VS& cars, const VI& perm)
{
    char last = '\0';
    char vis[26];

    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < perm.size(); i++) {
        foreach (it, cars[perm[i]]) {
            if (*it != last) {
                if (vis[*it - 'a'])
                    return false;
                vis[*it - 'a'] = 1;
                last = *it;
            }
        }
    }
    return true;
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        VS cars;
        VI perm;
        ll ret = 0;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            cars.push_back(s);
            perm.push_back(i);
        }

        do {
            if (good(cars, perm))            
                ret++;
        } while (next_permutation(perm.begin(), perm.end()));

        cout << "Case #" << t << ": " << ret << endl; 
    }
    return 0;
}
