#include <cstdio>
#include <string>
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    string orig[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                      "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                      "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    string translated[3] = {"our language is impossible to understand",
                            "there are twenty six factorial possibilities",
                            "so it is okay if you want to just give up"};

    char forward[255];
    memset(forward, 0, sizeof forward);

    for(int i = 0; i < 3; i++) {
        assert(translated[i].size() == orig[i].size());
        for(unsigned int j = 0; j < orig[i].size(); j++) {
            assert(!forward[(int)orig[i][j]] ||
                   forward[(int)orig[i][j]] == translated[i][j]);
            forward[(int)orig[i][j]] = translated[i][j];
        }
    }
    forward['q'] = 'z'; forward['z'] = 'q';

    cin.ignore();
    for(int z = 1; z <= t; z++) {
        string str;
        getline(cin, str);

        printf("Case #%d: ", z);
        for(unsigned int i = 0; i < str.size(); i++)
            printf("%c", forward[(int)str[i]]);
        printf("\n");
    }
}
