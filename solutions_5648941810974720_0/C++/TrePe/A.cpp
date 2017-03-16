#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n;
int cnt[128];
char d[10][6] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
char s[2005];
vector<int> v;
int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%s", s);
        for (i = 0; i < 128; i++) cnt[i] = 0;
        for (i = 0; s[i]; i++) cnt[(int) s[i]]++;
        v.clear();
        while (cnt['W']) {
            v.push_back(2);
            cnt['T']--;
            cnt['W']--;
            cnt['O']--;
        }
        while (cnt['U']) {
            v.push_back(4);
            cnt['F']--;
            cnt['O']--;
            cnt['U']--;
            cnt['R']--;
        }
        while (cnt['Z']) {
            v.push_back(0);
            cnt['Z']--;
            cnt['E']--;
            cnt['R']--;
            cnt['O']--;
        }
        while (cnt['G']) {
            v.push_back(8);
            cnt['E']--;
            cnt['I']--;
            cnt['G']--;
            cnt['H']--;
            cnt['T']--;
        }
        while (cnt['X']) {
            v.push_back(6);
            cnt['S']--;
            cnt['I']--;
            cnt['X']--;
        }
        while (cnt['H']) {
            v.push_back(3);
            cnt['T']--;
            cnt['H']--;
            cnt['R']--;
            cnt['E']--;
            cnt['E']--;
        }
        while (cnt['F']) {
            v.push_back(5);
            cnt['F']--;
            cnt['I']--;
            cnt['V']--;
            cnt['E']--;
        }
        while (cnt['V']) {
            v.push_back(7);
            cnt['S']--;
            cnt['E']--;
            cnt['V']--;
            cnt['E']--;
            cnt['N']--;
        }
        while (cnt['O']) {
            v.push_back(1);
            cnt['O']--;
            cnt['N']--;
            cnt['E']--;
        }
        while (cnt['N']) {
            v.push_back(9);
            cnt['N']--;
            cnt['I']--;
            cnt['N']--;
            cnt['E']--;
        }
        sort(v.begin(), v.end());
        for (i = 0; i < v.size(); i++) {
            printf("%d", v[i]);
        }
        printf("\n");
    }
    return 0;
}
