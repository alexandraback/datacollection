#include <cassert>
#include <cstdio>
#include <cstring>

#include <string>
using namespace std;

const int SIGMA = 26;
const int MAX_N = 128;

int mapping[SIGMA];

int n;
char v[MAX_N];

inline int get_code(char ch) { return ch - 'a'; }

int main() {
    assert(freopen("A.in", "r", stdin));
    assert(freopen("A.out", "w", stdout));

    string s[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                   "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                   "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    string t[3] = {"our language is impossible to understand",
                   "there are twenty six factorial possibilities",
                   "so it is okay if you want to just give up"};

    for (int i = 0; i < 3; ++i)
        for (size_t j = 0; j < s[i].size(); ++j)
            mapping[ get_code(s[i][j]) ] = get_code(t[i][j]);

    mapping[ get_code('y') ] = get_code('a');
    mapping[ get_code('e') ] = get_code('o');
    mapping[ get_code('q') ] = get_code('z');
    mapping[ get_code('z') ] = get_code('q');

    int T; assert(scanf("%d ", &T) == 1);
    for (int test = 1; test <= T; ++test) {
        assert(fgets(v, MAX_N, stdin));
        int n = strlen(v) - 1;

        printf("Case #%d: ", test);
        for (int i = 0; i < n; ++i)
            printf("%c", mapping[ get_code(v[i]) ] + 'a');
        printf("\n");
    }
}
