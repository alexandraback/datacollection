#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

int cntvertex = 0;

struct tnode
{
    bool isend;
    tnode* link[26];
    
    tnode()
    {
        cntvertex++;
        isend = false;
        for (int i = 0; i < 26; i++) link[i] = NULL;
    }
};

typedef tnode* pnode;

struct tedge
{
    int next, first, last, all;
    
    tedge(){}
    tedge(int next, int first, int last, int all): next(next), first(first), last(last), all(all) {}
};

const int maxn = 4004;
const int inf = 1e9;

pnode root = NULL;
char s[maxn];
int n;
int ans[maxn][6];
vector<tedge> gr[maxn];

pnode add(pnode cur, char *s, int curpos, int len)
{
    if (cur == NULL) cur = new tnode;
    if (curpos == len)
    {
        cur->isend = true;
        return cur;
    }
    cur->link[s[curpos] - 'a'] = add(cur->link[s[curpos] - 'a'], s, curpos + 1, len);
    return cur;
}

void check(pnode cur, int curpos, int first, int last, int all, int wh)
{
    if (cur == NULL) return;
    if (cur->isend)
    {
        gr[wh].push_back(tedge(curpos, (first == -1 ? 5 : first), last, all));
    }
    if (curpos >= n) return;
    check(cur->link[s[curpos] - 'a'], curpos + 1, first, min(5, last + 1), all, wh);
    if (last < 5) return;
    for (int i = 0; i < 26; i++) if (i != s[curpos] - 'a')
    {
        check(cur->link[i], curpos + 1, (first == -1 ? curpos - wh : first), 1, all + 1, wh);
    }
}

void upd(int &a, int b)
{
    a = min(a, b);
}

int main()
{
    FILE *dict = fopen("cdict.txt", "r");
    
    for (int i = 0; i < 521196; i++)
    {
        fscanf(dict, "%s", s);
        root = add(root, s, 0, strlen(s));
    }
    
    fprintf(stderr, "total %d nodes\n", cntvertex);
    
    int NT = 0;
    scanf("%d", &NT);
    for (int T = 1; T <= NT; T++)
    {
        int answer = inf;
        
        scanf("%s", s);
        n = strlen(s);
        for (int i = 0; i < n; i++) gr[i].resize(0);
        for (int i = 0; i < n; i++)
        {
            check(root, i, -1, 5, 0, i);
//             for (int j = 0; j < (int)gr[i].size(); j++) printf("edge: from %d to %d, first %d, last %d, all %d\n", i, gr[i][j].next, gr[i][j].first, gr[i][j].last, gr[i][j].all);
        }
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= 5; j++) ans[i][j] = inf;
        }
        
        ans[0][5] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 5; j++) if (ans[i][j] < inf)
            {
//                 cout << i << ' ' << j << ' ' << ans[i][j] << endl;
                for (int t = 0; t < (int)gr[i].size(); t++) if (j + gr[i][t].first >= 5)
                {
                    upd(ans[gr[i][t].next][min(gr[i][t].last, gr[i][t].next - i + j)], ans[i][j] + gr[i][t].all);
                }
            }
        }
        
        for (int j = 0; j <= 5; j++) answer = min(answer, ans[n][j]);
        
        printf("Case #%d: ", T);
        printf("%d\n", answer);
        fprintf(stderr, "%d/%d cases done!\n", T, NT);
    }
    return 0;
}
