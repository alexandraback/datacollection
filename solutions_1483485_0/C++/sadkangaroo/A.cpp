#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<cctype>
#include<climits>
#include<algorithm>
#include<complex>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

typedef long long LL;

string s1[3], s2[3];
char Mp[26];
char s[1000];

int main() {

    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    s1[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
    s1[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
    s1[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

    s2[0] = "our language is impossible to understand";
    s2[1] = "there are twenty six factorial possibilities";
    s2[2] = "so it is okay if you want to just give up";
    
    for (int i = 0; i < 3; ++i) 
        for (int k = 0; k < s1[i].length(); ++k)
            if (s1[i][k] != ' ')
                Mp[s1[i][k] - 'a'] = s2[i][k];
    Mp['q' - 'a'] = 'z';
    Mp['z' - 'a'] = 'q';
    int T;
    scanf("%d ", &T);
    for (int te = 1; te <= T; ++te) {
        cout << "Case #" << te << ": ";
        gets(s);
        int len = strlen(s);
        for (int i = 0; i < len; ++i)
            if (s[i] == ' ') cout << ' ';
            else cout << Mp[s[i] - 'a'];
        cout << endl;
    }

    return 0;

}

