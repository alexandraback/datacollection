#include <iostream>
#include <map>
#include <vector>

using namespace std;

string reps[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void solve(int T) {
    printf("Case #%d: ", T);
    string s;

    cin >> s;
    map<char, int> allset;
    for(int i = 0; i < s.size(); i++) allset[s[i]] ++;

    vector < int > count(10, 0);
    vector < bool > used(10, 0);
    
    for(int it = 0; it < 10; it++) {
        map<char, int> cnt;
        for(int i = 0; i < 10; i++) {
            if (used[i]) continue;

            string cur = reps[i];
            for(int j = 0; j < cur.size(); j++) {
                cnt[cur[j]] ++;
            }
        }
        string found = "";
        char base;
        int pos;
        for(int i = 0; i < 10; i++) {
            if (used[i] || found != "") continue;
            string cur = reps[i];

            for(int j = 0; j < cur.size(); j++) {
                if (cnt[cur[j]] == 1) {
                    found = cur;
                    used[i] = true;
                    base = cur[j];
                    pos = i;
                    break;
                }
            }
        }
        count[pos] = allset[base];
        for(int i = 0; i < found.size(); i++) {
            allset[found[i]] -= count[pos];
        }
    }

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < count[i]; j++) {
            printf("%d", i);
        }
    }
    puts("");
}

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
