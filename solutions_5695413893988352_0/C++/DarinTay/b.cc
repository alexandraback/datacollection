#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>


using namespace std;
#define ll long long

string s1, s2;

pair<string,string> ans;
bool hasAns;

void solve(int pos, bool x) {
    string& s = x ? s2 : s1;
    for (int i=pos;i<s.size();++i) {
        if (s[i] == '?') {
            for (int j=0;j<10;++j) {
                s[i] = '0' + j;
                solve(i+1, x);
            }
            s[i] = '?';
            return;
        }
    }
    if (!x) {
        return solve(0, true);
    } else {
        if (!hasAns) {
            ans = make_pair(s1, s2);
            hasAns = true;
        }
        ll curA = stoll(s1);
        ll curB = stoll(s2);
        ll ansA = stoll(ans.first);
        ll ansB = stoll(ans.second);

        ll curDiff = abs(curA - curB);
        ll ansDiff = abs(ansA - ansB);
        auto cur = make_pair(s1, s2);
        if (curDiff < ansDiff || curDiff == ansDiff && curA < ansA || curDiff == ansDiff && curA == ansA && curB < ansB) {
            //printf("Replacing %lld, %lld with %lld, %lld\n",  ansA, ansB, curA, curB);
            ans = cur;
        }
    }
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        cin>>s1>>s2;

        hasAns = false;
        solve(0, false);

        printf("Case #%d: %s %s\n", t, ans.first.c_str(), ans.second.c_str());
    }

}
