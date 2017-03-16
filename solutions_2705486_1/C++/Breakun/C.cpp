#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;

char str[10000];
int go[521196 * 10][26], term[521196 * 10], uniq;
void init_go()
{
    FILE *fin = fopen("garbled_email_dictionary.txt", "r");
    for(int j = 0; j < 26; j++)
        go[0][j] = -1;
    term[0] = 0;
    uniq = 1;
    while(fscanf(fin, "%s", str) != EOF)
    {
        int state = 0;
        for(int i = 0; str[i]; i++)
        {
            if(go[state][str[i] - 'a'] == -1)
            {
                go[state][str[i] - 'a'] = uniq;
                for(int j = 0; j < 26; j++)
                    go[uniq][j] = -1;
                uniq++;
            }
            state = go[state][str[i] - 'a'];
        }
        term[state] = 1;
    }
    fclose(fin);
}

#define fi first
#define se second
typedef pair<int, int> PI;
typedef map<PI, int> MAP;
typedef MAP::iterator MAP_ITER;
MAP curr, next;
void upd(MAP &m, const PI &p, int v)
{
    if(m.count(p))
        m[p] = min(m[p], v);
    else
        m[p] = v;
}
int main()
{
    init_go();

    int mt; scanf("%d", &mt);
    for(int t = 1; t <= mt; t++)
    {
        scanf("%s", str);
        curr.clear();
        curr[PI(4, 0)] = 0;
        for(int i = 0; str[i]; i++)
        {
            next.clear();
            for(MAP_ITER it = curr.begin(); it != curr.end(); it++)
            {
                if(go[it->fi.se][str[i] - 'a'] != -1)
                    upd(next, PI(min(it->fi.fi + 1, 4), go[it->fi.se][str[i] - 'a']), it->se);
                if(it->fi.fi == 4)
                    for(int j = 0; j < 26; j++)
                        if((j != (str[i] - 'a')) && go[it->fi.se][j] != -1)
                            upd(next, PI(0, go[it->fi.se][j]), it->se + 1);
            }
            curr.clear();
            for(MAP_ITER it = next.begin(); it != next.end(); it++)
            {
                upd(curr, it->fi, it->se);
                if(term[it->fi.se])
                    upd(curr, PI(it->fi.fi, 0), it->se);
            }
        }
        int ans = strlen(str);
        for(MAP_ITER it = curr.begin(); it != curr.end(); it++)
            if(it->fi.se == 0)
                ans = min(ans, it->se);
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
