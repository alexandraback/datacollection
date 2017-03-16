#include <bits/stdc++.h>
#define debug(args...) fprintf(stderr, args)

using namespace std;

const int ALF = 'Z' - 'A' + 10, N = 10;

void go() {
    string s;
    string num[N] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    int tab[N][ALF];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < ALF; j++)
            tab[i][j] = 0;
    for(int i = 0; i < N; i++)
            for(int j = 0; j < num[i].size(); j++)
                tab[i][num[i][j] - 'A']++;
    int val[N] = {0, 2, 6, 8, 3, 4, 1, 5, 7, 9};
    cin >> s;
    int freq[ALF];
    for(int i = 0; i < ALF; i++) freq[i] = 0;
    for(int i = 0; i < s.size(); i++) freq[s[i] - 'A']++;
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        int mini = INT_MAX;
        for(int j = 0; j < num[val[i]].size(); j++) mini = min(mini, freq[num[val[i]][j] - 'A'] / tab[val[i]][num[val[i]][j] - 'A']);
        for(int j = 0; j < mini; j++) ans.push_back(val[i]);
        //debug("Coloquei %d numeros %d\n", mini, val[i]);
        for(int j = 0; j < ALF; j++) freq[j] -= mini * tab[val[i]][j];
        //for(int j = 0; j < ALF; j++) debug("freq[%c] = %d\n", j + 'A', freq[j]);
    }
    for(int i = 0; i < ALF; i++) if(freq[i]) debug("Ops, sobrou letra %c em %s!", i + 'A', s.c_str());
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) printf("%d", ans[i]);
}

int main() {
    int T;
    scanf("%d\n", &T);
    for(int t = 1; t <= T; t++) {
        debug("Entering test %d\n", t);
        printf("Case #%d: ", t);
        go();
        printf("\n");
    }
    return 0;
}
