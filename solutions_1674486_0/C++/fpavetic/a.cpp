#include <cstdio>
#include <list>
using namespace std;

list<int> graf[1010];
int n;
char memo[1010][1010][2];
char bio[1010][1010][2], cookie = 0;

char rec(int a, int b, int razdvojio) {
    //printf("(%d %d %d)\n", a, b, razdvojio);
    if (a == b && razdvojio) {
        return 1;
    }

    char& ret = memo[a][b][razdvojio];
    if (bio[a][b][razdvojio] == cookie) {
        return ret;
    }
    bio[a][b][razdvojio] = cookie;
    ret = 0;

    for (list<int>::iterator it = graf[a].begin(); !ret && it != graf[a].end(); ++it) {
        for (list<int>::iterator jt = graf[b].begin(); !ret && jt != graf[b].end(); ++jt) {
            ret |= rec(*it, *jt, razdvojio || (*it != *jt));
        }
    }

    if (razdvojio) {
        for (list<int>::iterator it = graf[a].begin(); !ret && it != graf[a].end(); ++it) {
            ret |= rec(*it, b, 1);
        }

        for (list<int>::iterator it = graf[b].begin(); !ret && it != graf[b].end(); ++it) {
            ret |= rec(a, *it, 1);
        }
    }

    return ret;
}

int main(void) {
    int test; scanf("%d", &test);


    for (int cs = 0; cs < test; ++cs) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            int Mi; scanf("%d", &Mi);
            for (int j = 0; j < Mi; ++j) {
                int from; scanf("%d", &from); --from;
                graf[i].push_back(from);
            }
        }

        ++cookie;
        int ima = 0;
        for (int i = 0; i < n && !ima; ++i) {
            ima |= rec(i, i, 0);
            //printf("i=%d %d\n", i, ima);
        }

        printf("Case #%d: %s\n", cs+1, ima? "Yes": "No");

        for (int i = 0; i < n; ++i) {
            graf[i].clear();
        }
    }
return 0;
}
