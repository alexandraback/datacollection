#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>
#include <iostream>
using namespace std;

struct charCmp : binary_function <char *, char *, bool> {
    bool operator() (const char * const &a , const char * const &b) const { 
        return strcmp(a, b) < 0;
    }
};

__int64 gcd(__int64 a, __int64 b) {
    return b ? gcd(b, a % b) : a;
}

__int64 MODULO = 1000000007;

__int64 binpow(__int64 a, __int64 n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow(a, n - 1) * a) % MODULO;
    else {
        __int64 b = binpow(a, n / 2);
        return (b * b) % MODULO;
    }
}

__int64 modFactorial(int n) {
    static map<int, __int64> dm;
    map<int, __int64>::iterator i = dm.find(n);
    if (i != dm.end())
        return i->second;
    __int64 res = 1;
    for (int i = 2; i <= n; i++)
        res = (res * i) % MODULO;
    dm.insert(make_pair(n, res));
    return res;
}

__int64 modInvFactorial(int n) {
    static map<int, __int64> dm;
    map<int, __int64>::iterator i = dm.find(n);
    if (i != dm.end())
        return i->second;
    __int64 res = binpow(modFactorial(n), MODULO - 2);
    dm.insert(make_pair(n, res));
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testsCnt;
    scanf("%d", &testsCnt);
    for (int testN = 1; testN <= testsCnt; testN++) {

        char ss[110][110];
        char firstLetter[110], lastLetter[110];
        set<char> letters[110];
        set<int> letterOccurence[26], sFirst[26], sLast[26], sBoth[26], sMid[26];
        bool failFlag = 0;
        int n;

        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf(" %s", ss[i]);
            firstLetter[i] = ss[i][0];
            lastLetter[i] = ss[i][strlen(ss[i]) - 1];
            for (int j = 0; ss[i][j]; j++) {
                letters[i].insert(ss[i][j]);
                letterOccurence[ss[i][j] - 'a'].insert(i);
            }
        }

        for (int i = 0; i < 26; i++) {
            for (set<int>::iterator j = letterOccurence[i].begin(); j != letterOccurence[i].end(); j++) {
                if (firstLetter[*j] == i + 'a' && lastLetter[*j] == i + 'a')
                    sBoth[i].insert(*j);
                else if (firstLetter[*j] == i + 'a')
                    sFirst[i].insert(*j);
                else if (lastLetter[*j] == i + 'a')
                    sLast[i].insert(*j);
                else
                    sMid[i].insert(*j);
            }
            if (sFirst[i].size() > 1 || sLast[i].size() > 1 || (sMid[i].size() && (sFirst[i].size() || sLast[i].size() || sBoth[i].size()))) {
                failFlag = 1;
                break;
            }
        }
        bool hasFirst = 0, hasLast = 0, allBoth = 1;
        for (int i = 0; i < 26; i++) {
            if (!sFirst[i].empty() && sLast[i].empty() && sMid[i].empty())
                hasFirst = 1;
            if (!sLast[i].empty() && sFirst[i].empty() && sMid[i].empty())
                hasLast = 1;
            allBoth &= (sFirst[i].empty() && sLast[i].empty() && sMid[i].empty());
        }

        if ((!allBoth && !(hasFirst && hasLast)) || failFlag) {
            printf("Case #%d: 0\n", testN);
            continue;
        }

        int blocksCnt = n;
        __int64 multiplier = 1;
        for (int i = 0; i < 26; i++) {
            if (sFirst[i].size() && sLast[i].size())
                blocksCnt--;
            if (sBoth[i].size()) {
                blocksCnt -= sBoth[i].size() - 1;
                if (sFirst[i].size() || sLast[i].size())
                    blocksCnt--;
            }

            /*set<char *, charCmp> bs;
            multiset<char *, charCmp> bms;
            for (set<int>::iterator j = sBoth[i].begin(); j != sBoth[i].end(); j++) {
                bs.insert(ss[*j]);
                bms.insert(ss[*j]);
            }*/

            multiplier = (multiplier * modFactorial(sBoth[i].size())) % MODULO;
            /*for (set<char *, charCmp>::iterator j = bs.begin(); j != bs.end(); j++)
                multiplier = (multiplier * modInvFactorial(bms.count(*j))) % MODULO;*/
        }

        __int64 ans = (modFactorial(blocksCnt) * multiplier) % MODULO;
        printf("Case #%d: %I64d\n", testN, ans);
    }
}