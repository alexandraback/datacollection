#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <memory.h>
#include <queue>
#include <stack>
#include <deque>

using namespace std;

bool isTheSame(const string &s) {
    for(int i = 1; i < s.size(); i++)
        if(s[i] != s[i-1])
            return false;
    return true;
}

bool isInside(const string &s, char c) {
    if (isTheSame(s)) {
        return false;
    }
    int start = 0;
    while (start < s.size() && s[start] == c) {
        start++;
    }
    start = max(start, 1);
    int end = s.size() - 1;
    while (end >= 0 && s[end] == c) {
        end++;
    }
    end = min(end, (int)(s.size() - 2));
    for (int i = start; i <= end; i++) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

struct letter {
    bool isUsed = false;
    int quantity = 0;
    int beginLetter = -1;
    int endLetter = -1;
}letters[26];


bool wasUsed[26];

bool dfs(int p) {
    if (wasUsed[p])
        return false;
    wasUsed[p] = true;

    if (letters[p].endLetter == -1)
        return true;
    else {
        return dfs(letters[p].endLetter);
    }
}

int getComponentes() {
    for (int i = 0; i < 26; i++) {
        wasUsed[i] = false;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if(wasUsed[i])
            continue;
        if(letters[i].beginLetter == -1 && letters[i].isUsed) {
            count++;
            bool result = dfs(i);
            if (!result)
                return -1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if(wasUsed[i])
            continue;
        if(letters[i].isUsed)
        {
            wasUsed[i] = true;
            count++;
        }
    }
    return count;
}

long long MOD = 1000000007;

long long fact(int N) {
    long long result = 1;
    for(int i = 2; i <= N; i++) {
        result *= (long long)i;
        result %= MOD;
    }
    return result;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    // freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int TestNum;
    cin >> TestNum;
    for(int test = 1; test <= TestNum; test++) {
        printf("Case #%d: ",test);
        vector<string> sets;
        int N;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            string s;
            cin >> s;
            sets.push_back(s);
        }
        bool possible = true;
        for(int i = 0; i < 26; i++) {
            letters[i].quantity = 0;
            letters[i].beginLetter = -1;
            letters[i].endLetter = -1;
            letters[i].isUsed = false;
            bool inside = false;
            int beginQ = 0;
            int endQ = 0;
            for(int j = 0; j < sets.size(); j++) {
                if (isInside(sets[j], 'a' + i)) {
                    if (inside)
                        possible = false;
                    inside = true;

                }

                bool isSame = isTheSame(sets[j]);

                if (sets[j][0] == ('a' + i) && isSame) {
                    letters[i].isUsed = true;
                    letters[i].quantity++;
                }

                if (sets[j][0] == ('a' + i) && !isSame) {
                    letters[i].isUsed = true;
                    beginQ++;
                    letters[i].endLetter = sets[j][sets[j].size() - 1] - 'a';
                }
                if (sets[j][sets[j].size() - 1] == ('a' + i) && !isSame) {
                    endQ++;
                    letters[i].beginLetter = sets[j][0] - 'a';
                }
                if (!isSame && sets[j][0] == sets[j][sets[j].size() - 1]) {
                    possible = false;
                }
            }
            if(inside && (beginQ > 0 || endQ > 0))
                possible =  false;
            if (beginQ > 1 || endQ > 1)
                possible = false;
        }
        if (!possible) {
            printf("0\n");
            continue;
        }

        int components = getComponentes();
        if (components == -1)
            printf("0");
        else {
            long long result = fact(components);
            for(int i = 0; i < 26; i++)
            {
                result *= fact(letters[i].quantity);
                result %= MOD;
            }
            printf("%d", result);
        }
        printf("\n");
    }
    return 0;
}

