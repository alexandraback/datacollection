#include <cstdlib>
#include <bitset>
#include <functional>
#include <utility>
#include <tuple>
#include <limits>
#include <cstdint>
#include <cctype>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <random>
#include <numeric>
#include <iostream>
#include <sstream>

using namespace std;

long long best, one, two;
string ans1, ans2;

void rec(string &s1, string &s2, long long c1, long long c2, int idx) {
    if(idx >= s1.size()){
        long long diff = abs(c1 - c2);
        if(diff < best || (diff == best && c1 < one) || (diff == best && c1 == one && c2 < two)){
            best = diff;
            one = c1;
            two = c2;
            ans1 = s1;
            ans2 = s2;
        }
        return;
    }

    char ch1 = s1[idx];
    char ch2 = s2[idx];
    if(ch1 != '?' && ch2 != '?'){
        long long n1 = c1 * 10 + ch1 - '0';
        long long n2 = c2 * 10 + ch2 - '0';
        rec(s1, s2, n1, n2, idx+1);
        return;
    }

    if(c1 < c2){
        if(ch1 == '?')
            s1[idx] = '9';

        if(ch2 == '?')
            s2[idx] = '0';

        long long n1 = c1 * 10 + s1[idx] - '0';
        long long n2 = c2 * 10 + s2[idx] - '0';
        rec(s1, s2, n1, n2, idx+1);
    } else if(c1 > c2){
        if(ch1 == '?')
            s1[idx] = '0';

        if(ch2 == '?')
            s2[idx] = '9';

        long long n1 = c1 * 10 + s1[idx] - '0';
        long long n2 = c2 * 10 + s2[idx] - '0';
        rec(s1, s2, n1, n2, idx+1);
    } else {
        if(ch1 == '?' && ch2 != '?'){
            for(int i=-1; i<=1; ++i) {
                int test = s2[idx] - '0' + i;
                if(test >= 0 && test <= 9) {
                    s1[idx] = s2[idx] + i;
                    long long n1 = c1 * 10 + s1[idx] - '0';
                    long long n2 = c2 * 10 + s2[idx] - '0';
                    rec(s1, s2, n1, n2, idx + 1);
                }
            }
        } else if(ch1 != '?' && ch2 == '?'){
            for(int i=-1; i<=1; ++i) {
                int test = s1[idx] - '0' + i;
                if(test >= 0 && test <= 9) {
                    s2[idx] = s1[idx] + i;
                    long long n1 = c1 * 10 + s1[idx] - '0';
                    long long n2 = c2 * 10 + s2[idx] - '0';
                    rec(s1, s2, n1, n2, idx + 1);
                }
            }
        } else {
            s1[idx] = '0';
            s2[idx] = '0';
            rec(s1, s2, c1 * 10, c2 * 10, idx+1);

            s1[idx] = '1';
            rec(s1, s2, c1 * 10 + 1, c2 * 10, idx+1);

            s1[idx] = '0';
            s2[idx] = '1';
            rec(s1, s2, c1 * 10, c2 * 10 + 1, idx+1);
        }
    }
    s1[idx] = ch1;
    s2[idx] = ch2;
}

void comp(int tc){
    string s1, s2;
    cin >> s1 >> s2;
    best = one = two = numeric_limits<long long>::max();
    ans1 = ans2 = "";

    rec(s1, s2, 0, 0, 0);
    cout << "Case #" << tc << ": " << ans1 << " " << ans2 << endl;
}

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; ++tc){
        comp(tc);
    }
}