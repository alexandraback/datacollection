#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for(int a = b; a < c; a++)

#define dbg(x) cerr << x << endl;
#define _ << ", " << 

int freq[300];
string nums[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

int num[] = {
    0, 2, 6, 7, 4, 5, 8, 1, 3, 9
};

string id = "ZWXSUFGOTN";

int main() {
    ios_base::sync_with_stdio(false);

    int T;

    cin >> T;

    fr(cas, 1, T+1) {
        memset(freq, 0, sizeof freq);

        string s;
        cin >> s;

        int n = s.length();

        fr(i, 0, n) {
            freq[s[i]]++;
        }

        string ans = "";

        fr(i, 0, 10) {
            int x = num[i];
            //dbg(i _ x _ id[i]);
            while(freq[id[i]] > 0) {
                fr(i, 0, nums[x].size()) {
                    freq[nums[x][i]]--;
                }
                ans += '0'+x;
            }
        }

        sort(ans.begin(), ans.end());

        printf("Case #%d: %s\n", cas, ans.c_str());
    }

    return 0;
}


/*
    Z -> 0
    W -> 2
    X -> 6
    S -> 7
    U -> 4
    F -> 5
    G -> 8
    O -> 1
    T -> 3
    N -> 9

 */