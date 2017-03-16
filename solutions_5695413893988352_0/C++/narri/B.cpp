#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <map>
#include <stdint.h>
#include <climits>
#include <queue>
#include <iostream>


using namespace std;

int N;

inline long long absll(long long a) {
    if(a < 0){return -1*a;}
    return a;
}

struct key {
    long long score;
    int at;
    char a[18];
    char b[18];
    bool myless(const struct key &other) const {
        int sa = score;
        int sb = other.score;
        if(sa < 0) {sa *= -1;}
        if(sb < 0) {sb *= -1;}
        if(sa != sb) {
            return sa < sb;
        }
        int z;
        z = memcmp(a, other.a, N);
        if(z != 0) {return z < 0;}
        z = memcmp(b, other.b, N);
        return at > other.at;
    }
    bool operator<(const struct key &other) const {
        return !myless(other);
    }
};

string AA;
string BB;
long long dims[19];
long long OO = (1LL << 62);
string RA;
string RB;


void do_dfs(long long score, int at) {
    while(at < N && AA[at] != '?' && BB[at] != '?') {
        int diff = AA[at] - BB[at];
        score += dims[at] * diff;
        ++at;
    }
    if(at == N) {
        if(llabs(score) < OO) {
            OO = llabs(score);
            RA = AA;
            RB = BB;
        }
        /*
        else if(llabs(score) == OO) {
            if(AA < RA) {
                OO = llabs(score);
                RA = AA;
                RB = BB;
            }
            else if(AA == RA && BB < RB) {
                OO = llabs(score);
                RA = AA;
                RB = BB;
            }
        }
        */
        return;
    }
    if(AA[at] == '?' && BB[at] == '?') {
        AA[at] = '0';
        for(int i=0;i<10;++i) {
            AA[at] = '0' + i;
            for(int j=0;j<10;++j) {
                BB[at] = '0' + j;
                do_dfs(score + dims[at] * (AA[at] - BB[at]), at+1);
            }
        }
        BB[at] = '?';
        AA[at] = '?';
    }
    else if(AA[at] == '?') {
        for(int i=0;i<10;++i) {
            AA[at] = '0' + i;
            do_dfs(score + dims[at] * (AA[at] - BB[at]), at+1);
        }
        AA[at] = '?';
    }
    else if(BB[at] == '?'){
        for(int i=0;i<10;++i) {
            BB[at] = '0' + i;
            do_dfs(score + dims[at] * (AA[at] - BB[at]), at+1);
        }
        BB[at] = '?';
    }
    else {
        do_dfs(score + dims[at] * (AA[at] - BB[at]), at+1);
    }
}


int main(int argc, char **argv) {
    int T;
    cin >> T;
    for(int _cn = 1;_cn <= T;++_cn) {
        string a,b;
        cin >> a >> b;
        AA = a;
        BB = b;
        struct key initial;
        initial.score = 0;
        initial.at = 0;
        ::N = a.size();
        memcpy(initial.a, a.c_str(), a.size());
        memcpy(initial.b, b.c_str(), b.size());
        priority_queue<key> pq;
        pq.push(initial);
        struct key bestkey;
        memcpy(&bestkey, &initial, sizeof(initial));
        bestkey.score = (1LL << 62);
        ::OO = (1LL << 62);
        for(long long i=(int)a.size()-1, gg=1;i>=0;--i) {
            dims[i] = gg;
            gg *= 10;
        }
        do_dfs(0, 0LL);
        printf("Case #%d: %s %s\n", _cn, RA.c_str(), RB.c_str());
    }

    return 0;
}

