#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
string cars[100];
int char_count[26], fixed_count;
bool inner[26], v[100], before[26][26];
int root[26];
int ans, N;
int find_root(int a) {
    if (root[a] == a)
        return a;
    else
        return (root[a] = find_root(root[a]));
}
void union_set(int a, int b) {
    root[b] = find_root(a);
    fixed_count--;
}
void work(int cnt, char head) {
    if (cnt == N)
        ans = (ans + 1) % 1000000007;
    for (int i = 0; i < N; i++) {
        if (v[i])
            continue;
        if ((char_count[head - 'a'] == 0) || (cars[i].front() == head)) {
            v[i] = true;
            char_count[head - 'a']--;
            work(cnt + 1, cars[i].back());
            char_count[head - 'a']++;
            v[i] = false;
        }
    }
}
int qpower(int a) {
    int ans = 1;
    for (int i = 1; i <= a; i++)
        ans = ans * i % 1000000007;
    return ans;
}
int main() {
    ifstream ifs("input.txt");
    freopen("output.txt", "w", stdout);
    int T, TC;
    ifs >> T;
    TC = T;
    while (TC--) {
        ifs >> N;
        ans = 0;
        for (int i = 0; i < N; i++) {
            ifs >> cars[i];
            for (int j = 0; j < cars[i].length() - 1; j++) {
                if (cars[i][j] == cars[i][j + 1]) {
                    cars[i].erase(cars[i].begin() + j);
                    j--;
                }
            }
        }
        memset(inner, 0, sizeof(inner));
        {
            int i = 0;
            for (; i < N; i++) {
                int j = 1;
                for (; j < cars[i].length() - 1; j++) {
                    if (inner[cars[i][j] - 'a']) {
                        printf("Case #%d: 0\n", T - TC);
                        break;
                    }
                    inner[cars[i][j] - 'a'] = true;
                }
                if ((cars[i].length() != 1) && (j != cars[i].length() - 1))
                    break;
            }
            if (i != N)
                continue;
        }
        int i = 0;
        for (; i < N; i++) {
            if (inner[cars[i].front() - 'a'] || inner[cars[i].back() - 'a']) {
                printf("Case #%d: 0\n", T - TC);
                break;
            }
        }
        if (i != N)
            continue;
        memset(char_count, 0, sizeof(char_count));
        for (int i = 0; i < N; i++) {
            if (cars[i].length() == 1)
                continue;
            char_count[cars[i].front() - 'a']++;
            char_count[cars[i].back() - 'a']--;
        }
        memset(char_count, 0, sizeof(char_count));
        for (int i = 0; i < N; i++) {
            if (cars[i].length() == 1)
                continue;
            char_count[cars[i].front() - 'a']++;
            char_count[cars[i].back() - 'a']++;
        }
        {
            int i = 0;
            for (; i < 26; i++)
                if (char_count[i] > 2) {
                    printf("Case #%d: 0\n", T - TC);
                    break;
                }
            if (i != 26)
                continue;
        }
        fixed_count = 0;
        memset(root, 0x7F, sizeof(root));
        for (int i = 0; i < N; i++) {
            if (root[cars[i].front() - 'a'] != cars[i].front() - 'a')
                root[cars[i].front() - 'a'] = cars[i].front() - 'a';
            if (root[cars[i].back() - 'a'] != cars[i].back() - 'a')
                root[cars[i].back() - 'a'] = cars[i].back() - 'a';
        }
        {
            int i = 0;
            for (; i < N; i++) {
                if (cars[i].front() == cars[i].back())
                    continue;
                if (find_root(cars[i].front() - 'a') == find_root(cars[i].back() - 'a')) {
                    printf("Case #%d: 0\n", T - TC);
                    break;
                } else
                    union_set(cars[i].front() - 'a', cars[i].back() - 'a');
            }
            if (i != N)
                continue;
        }
        memset(char_count, 0, sizeof(char_count));
        for (int i = 0; i < 26; i++)
            if (root[i] == i)
                fixed_count++;
        for (int i = 0; i < N; i++) {
            if (cars[i].front() == cars[i].back())
                char_count[cars[i].front() - 'a']++;
        }
        ans = 1;
        for (int i = 0; i < 26; i++) {
            if (char_count[i] > 1)
                ans = ans * qpower(char_count[i]) % 1000000007;
        }
        printf("Case #%d: %d\n", T - TC, ans * qpower(fixed_count) % 1000000007);
    }
}