#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <unordered_map>
#include <cstring>
#include <ctime>
#include <bitset>
#include <cassert>
using namespace std;

#define INF 2100000000

int main() {
    freopen("/Users/tianyi/Desktop/input.txt", "r", stdin);
    freopen("/Users/tianyi/Desktop/output.txt", "w", stdout);
    int t; string s;
    scanf("%d", &t);
    for (int casen = 1; casen <= t; casen++) {
        cin >> s;
//        cout << s << endl;
        int cnt = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i-1]) cnt++;
        }
        if (s[s.size()-1] == '-') cnt++;
        printf("Case #%d: %d\n", casen, cnt);
    }
    return 0;
}