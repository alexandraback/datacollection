#include <bits/stdc++.h>
using namespace std;

        /*
          z"ZERO",
          w"TWO",
          x"SIX",
          g"EIGHT",
         -t"THREE",
         -r"FOUR",
         -o"ONE",
         -f"FIVE",
         -v"SEVEN",
         -i"NINE"
        */

char buffer[2020];
int freq[255];
string ans;

int dec(const char *d, char l, char n) {
    int count = freq[l];
    int lend = int(strlen(d));
    for (int i = 0; i < lend; i++)
        freq[d[i]] -= count;
    for (int i = 0; i < count; i++)
        ans += n;
    return count * lend;
}

void solve(string S) {
    memset(freq, 0, sizeof(freq));
    for (auto c: S)
        freq[c]++;
    int check = int(S.size());
    ans = "";
    check -= dec("ZERO", 'Z', '0');
    check -= dec("TWO", 'W', '2');
    check -= dec("SIX", 'X', '6');
    check -= dec("EIGHT", 'G', '8');
    check -= dec("THREE", 'T', '3');
    check -= dec("FOUR", 'R', '4');
    check -= dec("ONE", 'O', '1');
    check -= dec("FIVE", 'F', '5');
    check -= dec("SEVEN", 'V', '7');
    check -= dec("NINE", 'I', '9');
    assert(check == 0);
    sort(ans.begin(), ans.end());
}

int main() {
    int cases;
    scanf("%d", &cases);
    for (int cs = 1; cs <= cases; cs++) {
        scanf("%s", buffer);
        printf("Case #%d: ", cs);
        solve(string(buffer));
        puts(ans.c_str());
    }
}
