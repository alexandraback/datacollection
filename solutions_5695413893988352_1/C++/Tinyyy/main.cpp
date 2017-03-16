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
    int tc; scanf("%d", &tc);
    for (int tcn = 1; tcn <= tc; tcn++) {
        string a, b;
        cin >> a >> b;
        
        long long mind = 9000000000000000000;
        pair<long long, long long> ans;
        long long x, y; // defined for use later
        
        long long prefix = 0;
        for (int i = 0; i < a.size()+1; i++) { // Position at which the 2 numbers are first different
            if (i == a.size()) { // The 2 numbers can be equal!
                mind = 0;
                ans.first = prefix; ans.second = prefix;
                break;
            }
            if (a[i] != '?' && b[i] != '?') { // both fixed
                if (a[i] == b[i]) {
                    prefix *= 10; prefix += a[i] - '0';
                    continue;
                }
                x = prefix; y = prefix;
                x *= 10; x += a[i] - '0';
                y *= 10; y += b[i] - '0';
                if (a[i] < b[i]) {
                    for (int j = i+1; j < a.size(); j++) {
                        x *= 10;
                        if (a[j] == '?') x += 9;
                        else x += a[j] - '0';
                    }
                    for (int j = i+1; j < a.size(); j++) {
                        y *= 10;
                        if (b[j] == '?') y += 0;
                        else y += b[j] - '0';
                    }
                    if (abs(x-y) < mind) {
                        mind = abs(x-y);
                        ans.first = x; ans.second = y;
                    }
                    else if (abs(x-y) == mind) {
                        long long min1 = min(ans.first, ans.second);
                        long long min2 = min(x, y);
                        if (min2 < min1) {
                            ans.first = x; ans.second = y;
                        }
                    }
                }
                else {
                    for (int j = i+1; j < a.size(); j++) {
                        x *= 10;
                        if (a[j] == '?') x += 0;
                        else x += a[j] - '0';
                    }
                    for (int j = i+1; j < a.size(); j++) {
                        y *= 10;
                        if (b[j] == '?') y += 9;
                        else y += b[j] - '0';
                    }
                    if (abs(x-y) < mind) {
                        mind = abs(x-y);
                        ans.first = x; ans.second = y;
                    }
                    else if (abs(x-y) == mind) {
                        long long min1 = min(ans.first, ans.second);
                        long long min2 = min(x, y);
                        if (min2 < min1) {
                            ans.first = x; ans.second = y;
                        }
                    }
                }
                break; // definitely different now!
            }
            else if (a[i] == '?' && b[i] != '?') {
                // b[i]-1, b[i]
                if (b[i] != '0') {
                    x = prefix, y = prefix;
                    x *= 10; x += b[i]-1-'0';
                    y *= 10; y += b[i]-'0';
                    for (int j = i+1; j < a.size(); j++) {
                        x *= 10;
                        if (a[j] == '?') x += 9;
                        else x += a[j] - '0';
                    }
                    for (int j = i+1; j < a.size(); j++) {
                        y *= 10;
                        if (b[j] == '?') y += 0;
                        else y += b[j] - '0';
                    }
                    if (abs(x-y) < mind) {
                        mind = abs(x-y);
                        ans.first = x; ans.second = y;
                    }
                    else if (abs(x-y) == mind) {
                        long long min1 = min(ans.first, ans.second);
                        long long min2 = min(x, y);
                        if (min2 < min1) {
                            ans.first = x; ans.second = y;
                        }
                    }
                }
                // b[i]+1, b[i]
                if (b[i] != '9') {
                    x = prefix, y = prefix;
                    x *= 10; x += b[i]+1-'0';
                    y *= 10; y += b[i]-'0';
                    for (int j = i+1; j < a.size(); j++) {
                        x *= 10;
                        if (a[j] == '?') x += 0;
                        else x += a[j] - '0';
                    }
                    for (int j = i+1; j < a.size(); j++) {
                        y *= 10;
                        if (b[j] == '?') y += 9;
                        else y += b[j] - '0';
                    }
                    if (abs(x-y) < mind) {
                        mind = abs(x-y);
                        ans.first = x; ans.second = y;
                    }
                    else if (abs(x-y) == mind) {
                        long long min1 = min(ans.first, ans.second);
                        long long min2 = min(x, y);
                        if (min2 < min1) {
                            ans.first = x; ans.second = y;
                        }
                    }
                }
                // b[i], b[i]
                prefix *= 10; prefix += b[i]-'0';
            }
            else if (a[i] != '?' && b[i] == '?') {
                // a[i], a[i]+1
                if (a[i] != '9') {
                    x = prefix, y = prefix;
                    x *= 10; x += a[i]-'0';
                    y *= 10; y += a[i]+1-'0';
                    for (int j = i+1; j < a.size(); j++) {
                        x *= 10;
                        if (a[j] == '?') x += 9;
                        else x += a[j] - '0';
                    }
                    for (int j = i+1; j < a.size(); j++) {
                        y *= 10;
                        if (b[j] == '?') y += 0;
                        else y += b[j] - '0';
                    }
                    if (abs(x-y) < mind) {
                        mind = abs(x-y);
                        ans.first = x; ans.second = y;
                    }
                    else if (abs(x-y) == mind) {
                        long long min1 = min(ans.first, ans.second);
                        long long min2 = min(x, y);
                        if (min2 < min1) {
                            ans.first = x; ans.second = y;
                        }
                    }
                }
                
                // a[i], a[i]-1
                if (a[i] != '0') {
                    x = prefix, y = prefix;
                    x *= 10; x += a[i]-'0';
                    y *= 10; y += a[i]-1-'0';
                    for (int j = i+1; j < a.size(); j++) {
                        x *= 10;
                        if (a[j] == '?') x += 0;
                        else x += a[j] - '0';
                    }
                    for (int j = i+1; j < a.size(); j++) {
                        y *= 10;
                        if (b[j] == '?') y += 9;
                        else y += b[j] - '0';
                    }
                    if (abs(x-y) < mind) {
                        mind = abs(x-y);
                        ans.first = x; ans.second = y;
                    }
                    else if (abs(x-y) == mind) {
                        long long min1 = min(ans.first, ans.second);
                        long long min2 = min(x, y);
                        if (min2 < min1) {
                            ans.first = x; ans.second = y;
                        }
                    }
                }
                
                // a[i], a[i]
                prefix *= 10; prefix += a[i]-'0';
            }
            else if (a[i] == '?' && b[i] == '?') { // Both are '?', so 0,1 or 1,0
                // 0, 1
                x = prefix; y = prefix;
                x *= 10;
                y *= 10; y += 1;
                for (int j = i+1; j < a.size(); j++) {
                    x *= 10;
                    if (a[j] == '?') x += 9;
                    else x += a[j] - '0';
                }
                for (int j = i+1; j < a.size(); j++) {
                    y *= 10;
                    if (b[j] == '?') y += 0;
                    else y += b[j] - '0';
                }
                if (abs(x-y) < mind) {
                    mind = abs(x-y);
                    ans.first = x; ans.second = y;
                }
                else if (abs(x-y) == mind) {
                    long long min1 = min(ans.first, ans.second);
                    long long min2 = min(x, y);
                    if (min2 < min1) {
                        ans.first = x; ans.second = y;
                    }
                }
                
                // 1, 0
                x = prefix; y = prefix;
                x *= 10; x += 1;
                y *= 10;
                for (int j = i+1; j < a.size(); j++) {
                    x *= 10;
                    if (a[j] == '?') x += 0;
                    else x += a[j] - '0';
                }
                for (int j = i+1; j < a.size(); j++) {
                    y *= 10;
                    if (b[j] == '?') y += 9;
                    else y += b[j] - '0';
                }
                if (abs(x-y) < mind) {
                    mind = abs(x-y);
                    ans.first = x; ans.second = y;
                }
                else if (abs(x-y) == mind) {
                    long long min1 = min(ans.first, ans.second);
                    long long min2 = min(x, y);
                    if (min2 < min1) {
                        ans.first = x; ans.second = y;
                    }
                }
                
                // 0, 0
                prefix *= 10;
            }
        }
        printf("Case #%d: ", tcn);
        string a1 = to_string(ans.first), a2 = to_string(ans.second);
        while (a1.size() != a.size()) a1 = '0' + a1;
        while (a2.size() != a.size()) a2 = '0' + a2;
        cout << a1 << ' ' << a2 << endl;
    }
    return 0;
}