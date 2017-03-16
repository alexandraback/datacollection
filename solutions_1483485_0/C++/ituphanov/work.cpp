#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;

vector<string> a, b;
int b_to_a[26], vis[26];

int main()
{
    a.push_back("a zoo");
    a.push_back("our language is impossible to understand");
    a.push_back("there are twenty six factorial possibilities");
    a.push_back("so it is okay if you want to just give up");

    b.push_back("y qee");
    b.push_back("ejp mysljylc kd kxveddknmc re jsicpdrysi");
    b.push_back("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
    b.push_back("de kr kd eoya kw aej tysr re ujdr lkgc jv");

    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

    int i, j, k;
    memset(b_to_a, 255, sizeof(b_to_a));
    for (i = 0; i < a.size(); i++) {
        for (j = 0; j < a[i].size(); j++)
            if (a[i][j] != ' ') {
                int idxa = a[i][j] - 'a';
                int idxb = b[i][j] - 'a';
                if (b_to_a[idxb] != -1 && b_to_a[idxb] != idxa) {
                    cout << "Botva!" << endl;
                }
                b_to_a[idxb] = idxa;
            }
    }

    memset(vis, 0, sizeof(vis));
    k = 0;
    for (i = 0; i < 26; i++) {
        if (b_to_a[i] == -1) {
            k++;
        } else {
            vis[b_to_a[i]] = 1;
        }
    }
    if (k > 1) {
        cout << "Botva!" << endl;
    }
    if (k == 1) {
        int idxa, idxb;
        for (i = 0; i < 26; i++) {
            if (b_to_a[i] == -1) idxb = i;
            if (!vis[i]) idxa = i;
        }
        b_to_a[idxb] = idxa;
    }

    int tests;
    cin >> tests;
    string s;
    getline(cin, s);
    for (int sc = 0; sc < tests; sc++) {
        getline(cin, s);
        for (i = 0; i < s.length(); i++) {
            if (s[i] != ' ')  {
                s[i] = b_to_a[s[i]-'a'] + 'a';
            }
        }
        
        cout << "Case #" << sc+1 << ": ";
        cout << s;
        cout << endl;
    }

    fclose(stdin); fclose(stdout);
    return 0;
}