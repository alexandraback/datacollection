#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>

#define foreach(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

int MUL[4][4] = { { 0, 1, 2, 3 }, 
                  { 1, 0, 3, 2 },
                  { 2, 3, 0, 1 },
                  { 3, 2, 1, 0 }};

int SIGN[4][4] = { { 0, 0, 0, 0 }, 
                   { 0, 1, 0, 1 },
                   { 0, 1, 1, 0 },
                   { 0, 0, 1, 1 }};

int SMUL[8][8];

static void fillSmul()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            SMUL[i][j] = MUL[i & 3][j & 3] | ((SIGN[i & 3][j & 3] << 2) ^ (i & 4) ^ (j & 4));
}


int spow(int a, ll n)
{
    int ret = 0;

    if (n == 0)
        return ret;

    while (n != 1) {
        if (n & 1)
            ret = SMUL[ret][a];
        a = SMUL[a][a];
        n >>= 1;
    }

    return SMUL[ret][a];
}


template <int type, typename T>
int findLen(T begin, T end, int target)
{
    int v = 0;
    int ret = 0;

    for (int i = 0; i < 10; i++)
        for (T s = begin; s != end; s++) {
            ret++;
            if (type == 1)
                v = SMUL[v][*s];
            else
                v = SMUL[*s][v];
            if (v == target)
                return ret;
        }

    return -1;
}

int main(int argc, const char* argv[])
{
    int T;

    fillSmul();

    cin >> T;
    for (int t = 1; t <= T; t++) {
        int L;
        ll x;
        string s;
        cin >> L >> x;
        getline(cin, s);
        getline(cin, s);

        VI v(L);
        for (int i = 0; i < L; i++) {
            switch (s[i]) {
                case 'i':
                    v[i] = 1;
                    break;
                case 'j':
                    v[i] = 2;
                    break;
                case 'k':
                    v[i] = 3;
                    break;
            }
        }

        int tmul = 0;
        foreach (it, v)
            tmul = SMUL[tmul][*it];
        tmul = spow(tmul, x);
        if (tmul != 4) {
            cout << "Case #" << t << ": NO" << endl;
            continue;
        }

        ll left = (ll)findLen<1>(v.begin(), v.end(), 1);
        ll right = (ll)findLen<-1>(v.rbegin(), v.rend(), 3);

        if (left > 0 && right > 0 && left + right < L * x) {
            cout << "Case #" << t << ": YES" << endl;
        } else {
            cout << "Case #" << t << ": NO" << endl;
        }
    }
    return 0;
}
