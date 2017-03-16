#include <iostream>
#include <vector>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n;
    char * org[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    char * tra[] = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
    char s[128];
    char mp[256];
    memset(mp, 0, sizeof(mp));
    mp['z'] = 'q';
    mp['q'] = 'z';
    for(int i = 0; i < 3; i++){
        int len = strlen(org[i]);
        for(int j = 0; j < len; j++){
            mp[org[i][j]] = tra[i][j];
        }
    }
    scanf("%d", &n);
    gets(s);
    for(int i = 0; i < n; i++){
        gets(s);
        int len = strlen(s);
        for(int j = 0; j < len; j++){
            if(s[j] >= 'a' && s[j] <= 'z')
                s[j] = mp[s[j]];
        }
        printf("Case #%d: %s\n", i + 1, s);
    }
    return 0;
}
